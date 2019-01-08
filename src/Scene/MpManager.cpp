#include "Main.h"

MpManager::MpManager(int color): _Scene()
{
    this->netManager = Game::netManager;
    background = new Background();
    player = new Player( {128 , 128} , color );
    gameObjects.push_back(player);
    auto map = new Map();
    map->loadFromFile( &gameObjects );
    std::cout << "Zaczyna sie gra" << std::endl;
}

void MpManager::draw()
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

    Game::debugger->draw();
    SDL_RenderPresent( Game::renderer );
}

void MpManager::handleEvents()
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
                netManager->disconnectPlayer();
                flagReturn = 0;
                break;
            }
            if (eventHandler.key.keysym.sym == SDLK_SPACE)
            {
                SDL_Point punkt = player->shootPosition();
                // INVOKE BULLETS WYSYLA PAKIET Z PUNKTEM WYstrzelenia i kierunkiem 
                auto* bullet = new Bullet( {punkt.x , punkt.y} , player->getTowDir());
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
        else{
            gameObject->move();
            SendMovement();
        }
    }
}

void MpManager::SendMovement()
{
    const Uint8 *state = SDL_GetKeyboardState(nullptr);
    bool keys[7] = {bool(state[SDL_SCANCODE_UP]),bool(state[SDL_SCANCODE_DOWN]),&state[SDL_SCANCODE_LEFT],
                    &state[SDL_SCANCODE_RIGHT],&state[SDL_SCANCODE_Z],&state[SDL_SCANCODE_X],&state[SDL_SCANCODE_SPACE]};

    EventPacket * ep = new EventPacket();
    ep->setKeys(keys);
    ep->setTime(netManager->getGlobalTime());
    Game::netManager->udpSend(ep);
    std::cout << "Wyslano pakiet" << std::endl;
}


void MpManager::CheckColliders()
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

