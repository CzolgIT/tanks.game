#include "Main.h"

Menu::Menu( SDL_Renderer* r , Text* t , Configuration* c ) : Scene( r , t , c )
{
    selected = 1;
}

void Menu::handleEvents( float frameTime )
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
                    if (selected == 4)
                        flagReturn = -1;
                    else
                        flagReturn = selected;
                    running = false;
                    break;
                case SDLK_UP:
                    if (selected == 1 )
                        selected = 4;
                    else selected--;
                    break;
                case SDLK_DOWN:
                    if (selected == 4 )
                        selected = 1;
                    else selected++;
                    break;
            }
        }
    }

}

void Menu::draw( float frameTime )
{

    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( renderer );
    text->setAlignment( true );

    text->setColor( C_RED );
    text->setSize( 80 );
    text->draw( "Tanks" , 400 , 50 );
    text->draw( "Game" , 400 , 130 );

    text->setColor( C_BLACK );
    text->setSize( 40 );

    text->draw( "Multiplayer" , 400 , 280 );
    text->draw( "Singleplayer" , 400 , 340 );
    text->draw( "Settings" , 400 , 400 );
    text->draw( "Exit" , 400 , 460 );

    switch( selected )
    {
        case 1: text->draw( "- Multiplayer -" , 400 , 280 ); break;
        case 2: text->draw( "- Singleplayer -" , 400 , 340 ); break;
        case 3: text->draw( "- Settings -" , 400 , 400 ); break;
        case 4: text->draw( "- Exit -" , 400 , 460 ); break;
    }

    SDL_RenderPresent( renderer );

}
