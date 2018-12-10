#include "Main.h"

_Menu::_Menu( int maxSelected ) : _Scene()
{
    this->selected = 0;
    this->maxSelected = maxSelected-1;
}

void  _Menu::handleEvents()
{
    while( SDL_PollEvent( &eventHandler ) != 0 )
    {
        if( eventHandler.type == SDL_WINDOWEVENT )
        {
            if (eventHandler.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
            {
                Game::configuration->resizeWindow();
                updateGUI();
            }
        }
        if( eventHandler.type == SDL_QUIT )
        {
            running = false;
            flagReturn = -1;
            break;
        }
        if( eventHandler.type == SDL_KEYDOWN && eventHandler.key.repeat == 0 )
        {
            elements[selected]->setActive(false);
            switch( eventHandler.key.keysym.sym )
            {
                case SDLK_ESCAPE:
                    flagReturn = elements[maxSelected]->getFlag();
                    running = false;
                    break;
                case SDLK_RETURN:
                    flagReturn = elements[selected]->getFlag();
                    running = false;
                    break;
                case SDLK_UP:
                    if (selected == 0 )
                        selected = maxSelected;
                    else selected--;
                    break;
                case SDLK_DOWN:
                    if (selected == maxSelected )
                        selected = 0;
                    else selected++;
                    break;
                case SDLK_LEFT:
                    actionLeft(selected);
                    break;
                case SDLK_RIGHT:
                    actionRight(selected);
                    break;
            }
            elements[selected]->setActive(true);
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

