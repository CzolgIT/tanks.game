#include <utility>

#include "Main.h"

Room::Room(std::string ipadress) : _Scene()
{
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

    bt = new Button( "join", 50,26, 1 );
    bt2 = new Button( "back", 50,30, 1 );
    bt->setActive(true);

}

void  Room::handleEvent()
{
    if ( eventHandler.key.keysym.sym == SDLK_RETURN)
    {
        flagReturn = 8;
        running = false;
    }
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
