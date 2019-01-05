#include "Main.h"

Room::Room() : _Scene()
{
    Game::netManager = new NetManager();
    selectedTank = 1;
    dir=0;
    this->netManager = Game::netManager;
    Uint32 globalTime = 0;
    if (!netManager->connect("127.0.0.1",7777,globalTime))
    {
        flagReturn = 0;
        running = false;
    }
    sprite[0] = new TankSprite( 1 );
    sprite[1] = new TankSprite( 2 );
    sprite[2] = new TankSprite( 3 );
    sprite[3] = new TankSprite( 4 );

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
                case SDLK_RIGHT: if (selectedTank == 4 ) selectedTank=1; else selectedTank++; break;
                case SDLK_LEFT: if (selectedTank == 1 ) selectedTank=4; else selectedTank--; break;
            }
        }
    }
}

void Room::draw()
{
    SDL_SetRenderDrawColor( Game::renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( Game::renderer );

    dir+=0.2;
    if (dir>=360) dir-=360;
    sprite[0]->draw( 100 , 280 , dir , dir , 0 );
    sprite[1]->draw( 300 , 280 , dir , dir , 0 );
    sprite[2]->draw( 500 , 280 , dir , dir , 0 );
    sprite[3]->draw( 700 , 280 , dir , dir , 0 );

    Game::textManager->draw( "Tanks Game" , 400 , 20 ,65 , C_RED , true);

    if ( selectedTank == 1 )
        Game::textManager->draw( NICKNAME , 100 , 400 , 40 ,C_BLACK,true);
    if ( selectedTank == 2 )
        Game::textManager->draw( NICKNAME , 300 , 400 , 40 ,C_BLACK,true);
    if ( selectedTank == 3 )
        Game::textManager->draw( NICKNAME , 500 , 400 , 40 ,C_BLACK,true);
    if ( selectedTank == 4 )
        Game::textManager->draw( NICKNAME , 700 , 400 , 40 ,C_BLACK,true);

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
