#include "Main.h"

Manager::Manager(SDL_Renderer * r, Text* t , Configuration* c): Scene( r , t , c )
{
    background = new Background( renderer );
    player = new Player( renderer , text , 128 , 128 , 1 );
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
            if (eventHandler.key.keysym.sym == SDLK_ESCAPE)
            {
                running = false;
                flagReturn = -1;
                break;
            }
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

    CheckColliders();

    for (auto &gameObject : gameObjects) {
        if(gameObject->shouldBeDestroy()){
            gameObject->destroy();
            delete_object(gameObject);
            gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), gameObject), gameObjects.end());
        }
        else
            gameObject->move( frameTime );
    }
}

void Manager::CheckColliders()
{
    Collider * col1 = nullptr;
    Collider * col2 = nullptr;

    for (int i = 0; i < gameObjects.size(); i++)
    {
        for (int j = i+1; j < gameObjects.size(); j++)
        {
            double diagonal1 = sqrt( pow(gameObjects[i]->getW()/2,2) + pow(gameObjects[i]->getH()/2,2) );
            double diagonal2 = sqrt( pow(gameObjects[j]->getW()/2,2) + pow(gameObjects[j]->getH()/2,2) );
            double distance = sqrt( pow(gameObjects[j]->getX()-gameObjects[i]->getX(),2) + pow(gameObjects[j]->getY()-gameObjects[i]->getY(),2) );

            if ( (distance < diagonal1 + diagonal2) && !(gameObjects[i]->getType()==STATIC && gameObjects[j]->getType()==STATIC) )
            {
                col1 = gameObjects[i]->getCollider();
                col2 = gameObjects[j]->getCollider();

                Vector2D col = Collider::areColliding(col1, col2);
                if (col.x != 0 || col.y != 0) {

                    if (auto *p = dynamic_cast<Player *>(gameObjects[i])) {
                        if (auto *b = dynamic_cast<Bullet *>(gameObjects[j])) {

                        } else{
                             p->PushOut(col * 2);
                        }
                    } else if (auto *p = dynamic_cast<Player *>(gameObjects[j])) {
                        if (auto *b = dynamic_cast<Bullet *>(gameObjects[i])) {

                        } else{
                              p->PushOut(col * 2);

                        }
                    } else if (auto *b = dynamic_cast<Bullet *>(gameObjects[i])) {
                        b->setToBeDestroyed();
                    } else if (auto *b = dynamic_cast<Bullet *>(gameObjects[j])) {
                        b->setToBeDestroyed();
                    }
                }
            }
        }
    }
}

Player & Manager::getPlayer() {
    return reinterpret_cast<Player &>(this->player);
}
