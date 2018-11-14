#include "Main.h"

Manager::Manager(SDL_Renderer * renderer, Text* text , int color): Scene(renderer)
{
    background = new Background( renderer );
    player = new Player( renderer , text , SCR_W/2 - 50 , SCR_H/2 - 50 , color );
    gameObjects.push_back(player);
    std::cout << "Zaczyna sie gra" << std::endl;
}

void Manager::draw()
{
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( renderer );
    background->draw( SCR_W/2-player->getX() , SCR_H/2-player->getY() );

    for (int i = 0; i < gameObjects.size();i++)
    {
      gameObjects[i]->draw();
    }
    SDL_RenderPresent( renderer );
}

void Manager::handleEvents()
{
    while( SDL_PollEvent( &eventHandler ) != 0 )
    {
        if( eventHandler.type == SDL_QUIT )
        {
            running = false;
            flagReturn = -1;
            break;
        }

        for (int i = 0; i < gameObjects.size();i++)
        {
            gameObjects[i]->handleEvent( eventHandler );
        }
    }

    float timeStep = stepTimer.getTicks() / 1000.f;
    for (int i = 0; i < gameObjects.size();i++)
    {
        gameObjects[i]->move( timeStep );
    }
    stepTimer.start();
}


bool Manager::isRunning()
{
    return running;
}
