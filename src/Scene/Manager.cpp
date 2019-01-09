#include "Main.h"

Manager::Manager(): _Scene()
{
    background = new Background();
    player = new Player( 1 );
    player->setPosition({128,128});
    gameObjects.push_back(player);
    auto map = new Map();
    map->loadFromFile( &gameObjects );
    std::cout << "Zaczyna sie gra" << std::endl;
}

void Manager::draw()
{
    SDL_SetRenderDrawColor( Game::renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( Game::renderer );

    auto x0 = (int)((float)Game::configuration->getDisplayMode()->w/2-player->getX());
    auto y0 = (int)((float)Game::configuration->getDisplayMode()->h/2-player->getY());

    background->draw( x0 , y0 );

    for (auto &gameObject : gameObjects)
    {
        if (gameObject != player)
            gameObject->draw( x0 , y0 );
    }
    player->draw( x0 , y0 );

    for (auto &animation : animations)
    {
        if( !animation->gettodelete() )
            animation->draw( x0 , y0 );
    }

    Game::debugger->draw();
    Game::textManager->draw( "gameobjects: " + std::to_string( gameObjects.size() ) , 5 , 20 , 20 , C_BLACK , false );
    Game::textManager->draw( "animations: " + std::to_string( animations.size() ) , 5 , 40 , 20 , C_BLACK , false );

    SDL_RenderPresent( Game::renderer );
}

void Manager::handleEvents()
{
    SDL_Event eventHandler;
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
                flagReturn = 0;
                break;
            }
            if (eventHandler.key.keysym.sym == SDLK_SPACE)
            {
                auto* bullet = new Bullet( player->shootPosition() , player->getTowDir());
                gameObjects.push_back(bullet);

                auto* tankshoot = new Animation( TANKSHOOT , player->shootPosition() , player->getDir() );
                animations.push_back(tankshoot);
            }
        }
        for (auto &gameObject : gameObjects) {
            gameObject->handleEvent( eventHandler );
        }
    }

    const Uint8 *state = SDL_GetKeyboardState(nullptr);
    int los = random()%10;

    if (state[SDL_SCANCODE_UP] && los==2)
    {
        auto* tankdrive = new Animation( TANKDRIVE , player->smokePosition() , player->getDir() );
        animations.push_back(tankdrive);
    }


    CheckColliders();

    for (auto &gameObject : gameObjects) {
        if(gameObject->shouldBeDestroy())
        {
            //gameObject->destroy();
            if (auto *b = dynamic_cast<Bullet *>(gameObject))
            {
                auto* bulletexplode = new Animation( BULLETEXPLODE , b->getPosition() , 0 );
                animations.push_back(bulletexplode);
            }

            gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), gameObject), gameObjects.end());
            //delete gameObject;
        }
        else
            gameObject->move();
    }

    auto animation_iterator = animations.begin();
    while(animation_iterator != animations.end())
    {
        if((*animation_iterator)->gettodelete())
        {
            delete *animation_iterator;
            animation_iterator = animations.erase(animation_iterator);
        }
        else
            ++animation_iterator;
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
            if (!(gameObjects[i]->getType()==STATIC && gameObjects[j]->getType()==STATIC))
            {
                double diagonal1 = sqrt( pow(gameObjects[i]->getW()/2,2) + pow(gameObjects[i]->getH()/2,2) );
                double diagonal2 = sqrt( pow(gameObjects[j]->getW()/2,2) + pow(gameObjects[j]->getH()/2,2) );
                double distance = sqrt( pow(gameObjects[j]->getX()-gameObjects[i]->getX(),2) + pow(gameObjects[j]->getY()-gameObjects[i]->getY(),2) );

                if ( (distance < diagonal1 + diagonal2) )
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
}
