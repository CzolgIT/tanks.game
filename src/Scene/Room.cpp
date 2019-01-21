#include <utility>

#include "Main.h"

Room::Room(std::string ipadress) : _Scene()
{
    this->selected = 0;
    this->maxSelected = 1;
    MpManager::map = new Map();
    Game::netManager = new NetManager();
    selectedTank = 1;
    dir=0;
    this->ipadress = ipadress;
    Uint32 globalTime = 0;
    if (!Game::netManager->connect(std::move(ipadress),SERVERPORT,globalTime))
    {
        flagReturn = 0;
        running = false;
    }
    std::cout << "Connected to lobby" << std::endl;
    
    sprite[0] = new TankSprite( 1 , 0.4 * Game::configuration->getScale() );
    sprite[1] = new TankSprite( 2 , 0.4 * Game::configuration->getScale() );
    sprite[2] = new TankSprite( 3 , 0.4 * Game::configuration->getScale() );
    sprite[3] = new TankSprite( 4 , 0.4 * Game::configuration->getScale() );
    sprite[4] = new TankSprite( 5 , 0.4 * Game::configuration->getScale() );
    sprite[5] = new TankSprite( 6 , 0.4 * Game::configuration->getScale() );

    mapSprite = new Sprite(Game::textureManager->mapmin,{0,0,957,957},0.1 * Game::configuration->getDisplayMode()->h/300 );

    bt = new Button( "join", 50,26, 8 );
    bt2 = new Button( "back", 50,30, 0 );
    elements.push_back(bt);
    elements.push_back(bt2);
    bt->setActive(true);

}

void  Room::handleEvent()
{

    elements[selected]->setActive(false);
    switch( eventHandler.key.keysym.sym )
    {
        case SDLK_RETURN:
            Game::soundManager->PlayClickSound();
            flagReturn = elements[selected]->getFlag();
            if(flagReturn == 8){
                auto * playerReadyPacket = new PlayerReadyPacket();
                std::cout << "moje id - " << Game::netManager->getMyId() << std::endl;
                playerReadyPacket->setId(static_cast<Uint8>(Game::netManager->getMyId()));
                Game::netManager->tcpSend(playerReadyPacket);
            }
            running = false;
            break;
        case SDLK_UP:
            Game::soundManager->PlayClickSound();
            if (selected == 0 )
                selected = maxSelected;
            else selected--;
            break;
        case SDLK_DOWN:
            Game::soundManager->PlayClickSound();
            if (selected == maxSelected )
                selected = 0;
            else selected++;
            break;
        default:
            break;
    }
    elements[selected]->setActive(true);
}

void Room::draw()
{
    Game::netManager->getAllPlayersData();
    SDL_SetRenderDrawColor( Game::renderer, 215, 226, 175, 0xFF );
    SDL_RenderClear( Game::renderer );

    dir+=100 * Game::windowManager->getStepTime();
    if (dir>=360) dir-=360;

    Game::textManager->draw( "room: " + std::string(ipadress) , Game::configuration->getDisplayMode()->w/3 , 20 ,int(double(50)*Game::configuration->getScale()) , C_BLACK , true);
    Game::textManager->draw( "lista graczy: ",Game::configuration->getDisplayMode()->w/10,Game::configuration->getDisplayMode()->h/7,int(double(25)*Game::configuration->getScale()),C_BLACK,false);

    Game::textManager->draw( "map: city" + std::string(ipadress) , 6*Game::configuration->getDisplayMode()->w/8 , Game::configuration->getDisplayMode()->h/9 ,int(double(30)*Game::configuration->getScale()) , C_BLACK , true);
    mapSprite->draw( { 6*Game::configuration->getDisplayMode()->w/8 , Game::configuration->getDisplayMode()->h/3 } );


    int i = 0;
    for (auto const& client : Game::netManager->clientsMap){
        sprite[(client.first-1)%6]->draw( { Game::configuration->getDisplayMode()->w/12 + Game::configuration->getDisplayMode()->w/18 , Game::configuration->getDisplayMode()->h/5+(i*int(double(50)*Game::configuration->getScale())) + int(double(10)*Game::configuration->getScale())} , int(dir) , int(dir) , 0 );
        Game::textManager->draw(std::to_string(client.first),Game::configuration->getDisplayMode()->w/10,Game::configuration->getDisplayMode()->h/5+(i*int(double(50)*Game::configuration->getScale())),int(double(20)*Game::configuration->getScale()),C_BLACK,false);
        Game::textManager->draw((client.second),Game::configuration->getDisplayMode()->w/10+Game::configuration->getDisplayMode()->w/15,Game::configuration->getDisplayMode()->h/5+(i*int(double(50)*Game::configuration->getScale())),int(double(20)*Game::configuration->getScale()),C_BLACK,false);
        i++;
    }

    bt->draw();
    bt2->draw();

    Game::debugger->draw();
    SDL_RenderPresent( Game::renderer );
}

void Room::reloadGUI()
{
    Game::configuration->resizeWindow();

    delete sprite[0];
    delete sprite[1];
    delete sprite[2];
    delete sprite[3];
    delete sprite[4];
    delete sprite[5];

    sprite[0] = new TankSprite( 1 , 0.4 * Game::configuration->getScale() );
    sprite[1] = new TankSprite( 2 , 0.4 * Game::configuration->getScale() );
    sprite[2] = new TankSprite( 3 , 0.4 * Game::configuration->getScale() );
    sprite[3] = new TankSprite( 4 , 0.4 * Game::configuration->getScale() );
    sprite[4] = new TankSprite( 5 , 0.4 * Game::configuration->getScale() );
    sprite[5] = new TankSprite( 6 , 0.4 * Game::configuration->getScale() );

    delete mapSprite;
    mapSprite = new Sprite(Game::textureManager->mapmin,{0,0,957,957},0.1 * Game::configuration->getDisplayMode()->h/300 );

    elements[0]->updateScale();
    elements[1]->updateScale();
}