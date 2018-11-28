#include "Main.h"

Settings::Settings() : _Scene()
{
    selected=1;

    title = new TextStatic( "Settings" , 5 , 4 , 0.2 );

    button[0] = new Button( "video" , 13.5 );
    button[1] = new Button( "audio" , 17.5 );
    button[2] = new Button( "controller" , 21.5 );
    button[3] = new Button( "game" , 25.5 );
    button[4] = new Button( "back" , 31 );
}

void  Settings::handleEvents()
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
                    flagReturn = 0;
                    running = false;
                    break;
                case SDLK_RETURN:
                    if (selected == 5)
                        flagReturn = 0;
                    else
                        flagReturn = 3+selected;
                    running = false;
                    break;
                case SDLK_UP:
                    if (selected == 1 )
                        selected = 5;
                    else selected--;
                    break;
                case SDLK_DOWN:
                    if (selected == 5 )
                        selected = 1;
                    else selected++;
                    break;
            }
        }
    }
}

void Settings::draw()
{
    SDL_SetRenderDrawColor( Game::renderer, 215, 226, 175, 0xFF );
    SDL_RenderClear( Game::renderer );

    title->draw();

    button[0]->draw( selected == 1 );
    button[1]->draw( selected == 2 );
    button[2]->draw( selected == 3 );
    button[3]->draw( selected == 4 );
    button[4]->draw( selected == 5 );

    Game::debugger->draw();
    SDL_RenderPresent( Game::renderer );
}

