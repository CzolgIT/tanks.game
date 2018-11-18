#include "Main.h"

Room::Room( SDL_Renderer* renderer , Text* text , NetManager* net) : Scene( renderer , text )
{
    this->text = text;
    selectedTank = 1;
    dir=0;
    netManager = net;
    if (netManager->activate() == false)
    {
        flagReturn = 0;
        running = false;
    }

    sprite[0] = new TankSprite( renderer , 1 );
    sprite[1] = new TankSprite( renderer , 2 );
    sprite[2] = new TankSprite( renderer , 3 );
    sprite[3] = new TankSprite( renderer , 4 );
}

void  Room::handleEvents( float frameTime )
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
                case SDLK_RETURN:

                    flagReturn = 4; // tu byl selectedtank, ale tworzenie czolgu bedzie musialo byc juz w tej klasie
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

void Room::draw( float frameTime )
{
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( renderer );

    dir+=0.2;
    if (dir>=360) dir-=360;
    sprite[0]->draw( 100 , 280 , dir , dir , 0 );
    sprite[1]->draw( 300 , 280 , dir , dir , 0 );
    sprite[2]->draw( 500 , 280 , dir , dir , 0 );
    sprite[3]->draw( 700 , 280 , dir , dir , 0 );



    text->setAlignment( true );

    text->setColor( C_RED );
    text->setSize( 65 );
    text->draw( "Tanks Game" , 400 , 20 );

    //text->setColor( C_BLACK );
    text->setSize( 40 );

    if ( selectedTank == 1 )
        text->draw( NICKNAME , 100 , 400 );
    if ( selectedTank == 2 )
        text->draw( NICKNAME , 300 , 400 );
    if ( selectedTank == 3 )
        text->draw( NICKNAME , 500 , 400 );
    if ( selectedTank == 4 )
        text->draw( NICKNAME , 700 , 400 );

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
     SDL_RenderPresent( renderer );
}
