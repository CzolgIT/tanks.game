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
    
    sprite[0] = new TankSprite( 1 , 0.5 );
    sprite[1] = new TankSprite( 2 , 0.5 );
    sprite[2] = new TankSprite( 3 , 0.5 );
    sprite[3] = new TankSprite( 4 , 0.5 );
    sprite[4] = new TankSprite( 5 , 0.5 );
    sprite[5] = new TankSprite( 6 , 0.5 );

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

    Game::textManager->draw( "room: " + std::string(ipadress) , 400 , 20 ,65 , C_BLACK , true);
    Game::textManager->draw( "lista graczy: ",80,160,35,C_BLACK,false);

    int i = 0;
    for (auto const& client : Game::netManager->clientsMap){
        sprite[(client.first-1)%6]->draw( { 140 , 260+(i*60) } , int(dir) , int(dir) , 0 );
        Game::textManager->draw(std::to_string(client.first),80,240+(i*60),30,C_BLACK,false);
        Game::textManager->draw((client.second),180,240+(i*60),30,C_BLACK,false);
        i++;
    }

    bt->draw();
    bt2->draw();

    Game::debugger->draw();
    SDL_RenderPresent( Game::renderer );
}
