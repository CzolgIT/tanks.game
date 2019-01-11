#include "Main.h"

Room::Room() : _Scene()
{
    Game::netManager = new NetManager();
    selectedTank = 1;
    dir=0;
    this->netManager = Game::netManager;
    Uint32 globalTime = 0;
    if (!netManager->connect(SERVERIP,SERVERPORT,globalTime))
    {
        flagReturn = 0;
        running = false;
    }
    std::cout << "Pyklo" << std::endl;
    
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

void  Room::handleEvents()
{
    while( SDL_PollEvent( &eventHandler ) != 0 )
    {

        if( eventHandler.type == SDL_QUIT )
        {
            running = false;
            flagReturn = -1;
            break;
        }

        if( eventHandler.type == SDL_KEYDOWN && eventHandler.key.repeat == 0 )
        {
            switch( eventHandler.key.keysym.sym )
            {
                case SDLK_ESCAPE:
                    running = false;
                    flagReturn = -1;
                    break;
                case SDLK_RETURN:
                    flagReturn = 8; // tu byl selectedtank, ale tworzenie czolgu bedzie musialo byc juz w tej klasie
                    running = false;
                    break;
                //case SDLK_UP: if (selected == 1 ) selected = 5; else selected=1; break;
                //case SDLK_DOWN: if (selected == 5) selected = 1; else selected=5; break;
                //case SDLK_RIGHT: if (selectedTank == 4 ) selectedTank=1; else selectedTank++; break;
                //case SDLK_LEFT: if (selectedTank == 1 ) selectedTank=4; else selectedTank--; break;
            }
        }
    }
}

void Room::draw()
{
    netManager->getAllPlayersData();
    SDL_SetRenderDrawColor( Game::renderer, 215, 226, 175, 0xFF );
    SDL_RenderClear( Game::renderer );

    dir+=100 * Game::windowManager->getStepTime();
    if (dir>=360) dir-=360;

    Game::textManager->draw( "room: " + std::string(SERVERIP) , 400 , 20 ,65 , C_BLACK , true);
    Game::textManager->draw( "lista graczy: ",80,160,35,C_BLACK,false);

    for(unsigned i = 0; i < netManager->clients.size(); i++)
    {
        sprite[(netManager->clients[i]-1)%6]->draw( { 140 , int(260+(i*60)) } , dir , dir , 0 );
        Game::textManager->draw(std::to_string(netManager->clients[i]),80,240+(i*60),30,C_BLACK,false);
    }


//    if ( selectedTank == 1 )
//    {
//        //Game::textManager->draw(NICKNAME, 100, 400, 40, C_BLACK, true);
//    }
//    if ( selectedTank == 2 )
//        //Game::textManager->draw( NICKNAME , 300 , 400 , 40 ,C_BLACK,true);
//    if ( selectedTank == 3 )
//        //Game::textManager->draw( NICKNAME , 500 , 400 , 40 ,C_BLACK,true);
//    if ( selectedTank == 4 )
//        //Game::textManager->draw( NICKNAME , 700 , 400 , 40 ,C_BLACK,true);

    bt->draw();
    bt2->draw();

    /*

    if ( selected == 1 )
    {
        text->setSize( 60 );
        text->draw( "Start" , 400 , 470 );
    }
    else
    {
        text->setSize( 40 );
        text->draw( "Start" , 400 , 480 );
    }
    if ( selected == 5 )
    {
        text->setSize( 60 );
        text->draw( "Back" , 400 , 530 );
    }
    else
    {
        text->setSize( 40 );
        text->draw( "Back" , 400 , 540 );
    }
*/
    Game::debugger->draw();
    SDL_RenderPresent( Game::renderer );
}
