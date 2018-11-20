#include "Main.h"

Manager::Manager(SDL_Renderer * renderer, Text* text , int color): Scene( renderer , text )
{
    background = new Background( renderer );
    player = new Player( renderer , text , SCR_W/2 - 50 , SCR_H/2 - 50 , color );
    gameObjects.push_back(player);
    Wall * wall = new Wall( renderer , 200 , 200, 64, 64 );
    gameObjects.push_back(wall);
    std::cout << "Zaczyna sie gra" << std::endl;
}

void Manager::draw( float frameTime )
{
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( renderer );

    int x0 = (int)((float)SCR_W/2-player->getX());
    int y0 = (int)((float)SCR_H/2-player->getY());

    background->draw( x0 , y0 );

    for (int i = 0; i < gameObjects.size();i++)
    {
      gameObjects[i]->draw( x0 , y0 );
    }

    player->draw( x0 , y0 ); // czolg musi byc rysowany ostatni... nwm jak to rozegrac
    // narazie rysuje sie dwa razy

    text->draw( "fps: " + std::to_string( frameTime ) ,  500 , 560 );

    SDL_RenderPresent( renderer );
}

void Manager::handleEvents( float frameTime )
{
    while ( SDL_PollEvent( &eventHandler ) != 0 )
    {
        if ( eventHandler.type == SDL_QUIT )
        {
            running = false;
            flagReturn = -1;
            break;
        }

        if( eventHandler.type == SDL_KEYDOWN) // && eventHandler.key.repeat == 0 )
        {
            if (eventHandler.key.keysym.sym == SDLK_SPACE)
            {
                Bullet* bullet = new Bullet(renderer, (int) player->getX(), (int) player->getY(), player->getTowDir());
                gameObjects.push_back(bullet);
            }
        }

        for (int i = 0; i < gameObjects.size();i++)
        {
            gameObjects[i]->handleEvent( eventHandler );
        }
    }

    // Check colliders
    Vector2D col = Collider::areColliding(gameObjects[1]->collider(), player->collider());
    if (col.x != 0 || col.y != 0)
    {
        std::cout << col.x << ", " << col.y << std::endl;
    }

    for (int i = 0; i < gameObjects.size();i++)
    {
        gameObjects[i]->move( frameTime );
    }
}
