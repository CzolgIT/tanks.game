#include "Main.h"

_Scene::_Scene()
{
    running = true;
    flagReturn = 0;
}

void _Scene::update()
{
    handleAllEvents();
    everyStep();
    draw();
}

void _Scene::handleAllEvents()
{
    while ( SDL_PollEvent( &eventHandler ) != 0 )
    {
        if (eventHandler.type == SDL_QUIT) // quit game
        {
            running = false;
            if (Game::netManager!=nullptr)
                Game::netManager->disconnectPlayer();
            flagReturn = -1;
            break;
        }
        if( eventHandler.type == SDL_WINDOWEVENT )
            reloadGUI();
        if (eventHandler.type == SDL_KEYDOWN)
        {
            if (eventHandler.key.keysym.sym == SDLK_ESCAPE) // go back
                exitScene();
            else
                handleEvent();
        }
    }
}

void _Scene::reloadGUI()
{
    Game::configuration->resizeWindow();
}

void _Scene::exitScene()
{
    running = false;
    if (Game::netManager!=nullptr)
        Game::netManager->disconnectPlayer();
    flagReturn = 0;
}