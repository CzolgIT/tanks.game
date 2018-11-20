#include "Main.h"

Manager::Manager(SDL_Renderer * renderer, Text* text , int color): Scene( renderer , text )
{
    background = new Background( renderer );
    player = new Player( renderer , text , SCR_W/2 - 50 , SCR_H/2 - 50 , color );
    gameObjects.push_back(player);
    auto map = new Map( renderer );
    map->loadFromFile( &gameObjects );
    std::cout << "Zaczyna sie gra" << std::endl;
}

void Manager::draw( float frameTime )
{
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( renderer );

    auto x0 = (int)((float)SCR_W/2-player->getX());
    auto y0 = (int)((float)SCR_H/2-player->getY());

    background->draw( x0 , y0 );

    for (auto &gameObject : gameObjects) {
        gameObject->draw( x0 , y0 );
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
                SDL_Point punkt = player->shootPosition();
                auto* bullet = new Bullet(renderer, punkt.x , punkt.y , player->getTowDir());
                gameObjects.push_back(bullet);
            }
        }
        for (auto &gameObject : gameObjects) {
            gameObject->handleEvent( eventHandler );
        }
    }

    // Check colliders
    Vector2D col = Collider::areColliding(gameObjects[0]->collider(), gameObjects[1]->collider());
    if (col.x != 0 || col.y != 0)
    {
        std::cout << col.x << ", " << col.y << std::endl;
        player->PushOut(col);
    }
    for (auto &gameObject : gameObjects) {
        gameObject->move( frameTime );
    }
}
