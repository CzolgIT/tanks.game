#include "Main.h"

_Menu::_Menu( int maxSelected ) : _Scene()
{
    this->selected = 0;
    this->maxSelected = maxSelected-1;
}

void  _Menu::handleEvent()
{
    elements[selected]->setActive(false);
    switch( eventHandler.key.keysym.sym )
    {
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
        default:
            break;
    }
    elements[selected]->setActive(true);
}

void _Menu::draw()
{
    SDL_SetRenderDrawColor( Game::renderer, 215, 226, 175, 0xFF );
    SDL_RenderClear( Game::renderer );

    for( _Element* e : elements ) e->draw();
    Game::debugger->draw();

    SDL_RenderPresent( Game::renderer );
}

void _Menu::reloadGUI()
{
    Game::configuration->resizeWindow();
    for( _Element* e : elements ) e->updateScale();
}

void _Menu::exitScene()
{
    flagReturn = elements[maxSelected]->getFlag();
    running = false;
}