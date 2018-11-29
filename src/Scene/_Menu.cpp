#include "Main.h"

_Menu::_Menu( int maxSelected ) : _Scene()
{
    this->selected = 1;
    this->maxSelected = maxSelected;
}

void  _Menu::handleEvents()
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

                    if (selected == maxSelected)
                        flagReturn = flagPrevious ;
                    else
                        flagReturn = elements[0]->getFlag();

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

void _Menu::draw()
{
    SDL_SetRenderDrawColor( Game::renderer, 215, 226, 175, 0xFF );
    SDL_RenderClear( Game::renderer );

    for( _Element* e : elements ) e->draw();

    Game::debugger->draw();
    SDL_RenderPresent( Game::renderer );
}

void _Menu::updateGUI()
{
    for( _Element* e : elements ) e->updateScale();
}

