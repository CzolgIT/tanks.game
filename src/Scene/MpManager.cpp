#include "Main.h"

MpManager::MpManager(int color): _Scene()
{
    // net start
    this->netManager = Game::netManager;

    // creating player
    player = new Player( Game::netManager->getMyId() );
    players.push_back(player);

    // filling map
    background = new Background();
    auto map = new Map();
    map->loadFromFile( &gameObjects );
}

void MpManager::draw()
{
    SDL_SetRenderDrawColor( Game::renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( Game::renderer );

    auto x0 = (int)((float)Game::configuration->getDisplayMode()->w/2-player->getX());
    auto y0 = (int)((float)Game::configuration->getDisplayMode()->h/2-player->getY());

    background->draw( x0 , y0 );

    for (auto &gameObject : gameObjects)
        gameObject->draw( x0 , y0 );

    for (auto &p : players)
    {
        p->draw(x0, y0);
//        p->drawInfo(x0,y0);
    }

    for (auto &animation : animations)
        animation->draw( x0 , y0 );

    Game::debugger->draw();

    SDL_RenderPresent( Game::renderer );
}

void MpManager::handleEvents()
{
    SDL_Event eventHandler;
    while ( SDL_PollEvent( &eventHandler ) != 0 ) {
        if (eventHandler.type == SDL_QUIT) // quit game
        {
            running = false;
            netManager->disconnectPlayer();
            flagReturn = -1;
            break;
        }
        if (eventHandler.type == SDL_KEYDOWN && eventHandler.key.keysym.sym == SDLK_ESCAPE) // back to menu
        {
            running = false;
            netManager->disconnectPlayer();
            flagReturn = 0;
            break;
        }
    }

    const Uint8 *state = SDL_GetKeyboardState(nullptr);

    // todo: animacja powinna być rysowana dla wszystkich graczy
    int los = random()%10;
    if (state[SDL_SCANCODE_UP] && los==2)
    {
        auto* tankdrive = new Animation( TANKDRIVE , player->smokePosition() , player->getDir() );
        animations.push_back(tankdrive);
    }
    // todo: koniec

    Game::netManager->read(); // load all packets

    std::unique_ptr<BasePacket> received;

    while ( Game::netManager->pollPacket(received) )
    {
        if (auto *p = dynamic_cast<CurrentPositionPacket *>(received.get()))
        {
            bool found=false;

            for (auto &pl : players)
            {
                if ( pl->getId() == p->getPlayerId() )
                {
                    found=true;
                    pl->setPosition({(int)p->getX(), (int)p->getY()});
                    pl->setDirection((int)p->getTankRotation());
                    pl->setTowerDirection((int)p->getTurretRotation());
                    pl->setTankSpeed((int)p->getTankSpeed());
                    pl->setRotationSpeed((int)p->getRotationSpeed());
                    pl->setTurretRotationSpeed((int)p->getTurretRotationSpeed());
                    pl->updated = true;
                }
            }
            if (!found)
            {
                Player *newPlayer = new Player((int)p->getPlayerId());
                newPlayer->setPosition({(int)p->getX(), (int)p->getY()});
                newPlayer->setDirection((int)p->getTankRotation());
                newPlayer->setTowerDirection((int)p->getTurretRotation());
                newPlayer->setTankSpeed((int)p->getTankSpeed());
                newPlayer->setRotationSpeed((int)p->getRotationSpeed());
                newPlayer->setTurretRotationSpeed((int)p->getTurretRotationSpeed());
                players.push_back(newPlayer);
            }
        }
        else if(auto *p = dynamic_cast<PlayerDisconnectedPacket *>(received.get()))
        {
            auto players_iterator = players.begin();
            while(players_iterator != players.end())
            {
                if (p->getId() == (*players_iterator)->getId())
                {
                    delete *players_iterator;
                    players_iterator = players.erase(players_iterator);
                }
                else
                    ++players_iterator;
            }
        }
        else if(auto *p = dynamic_cast<PlayerJoinedPacket *>(received.get()))
        {
            p->print();
        }
        else if(auto *p = dynamic_cast<BulletInfoPacket *>(received.get()))
        {
            Bullet * bullet = new Bullet({p->getX(),p->getY()},p->getAngle());
            gameObjects.push_back(bullet);

            auto* tankshoot = new Animation( TANKSHOOT , {p->getX(),p->getY()} , p->getAngle() );
            animations.push_back(tankshoot);
        }
    }

    // simulate movement
    for (auto &p : players)
    {
        if (!p->updated)
        {
            p->simulate();
        }
    }





    //CheckColliders();

//    for (auto &gameObject : gameObjects) {
//        if(gameObject->shouldBeDestroy())
//        {
//            if (auto *b = dynamic_cast<Bullet *>(gameObject))
//            {
//                auto* bulletexplode = new Animation( BULLETEXPLODE , b->getPosition() , 0 );
//                animations.push_back(bulletexplode);
//            }
//            //gameObject->destroy();
//            //delete_object(gameObject);
//            gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), gameObject), gameObjects.end());
//        }
//        else{
//            gameObject->move();
//            SendMovement();
//        }
//    }

//    bool anykey=false;
//    if (state[SDL_SCANCODE_UP]) anykey=true;
//    if (state[SDL_SCANCODE_DOWN]) anykey=true;
//    if (state[SDL_SCANCODE_LEFT]) anykey=true;
//    if (state[SDL_SCANCODE_RIGHT]) anykey=true;
//    if (state[SDL_SCANCODE_SPACE]) anykey=true;
//    if (state[SDL_SCANCODE_Z]) anykey=true;
//    if (state[SDL_SCANCODE_X]) anykey=true;
    //if (anykey)

    for (auto &p : players)
        p->updated = false;

        sendMovement();

    auto gameObject_iterator = gameObjects.begin();
    while(gameObject_iterator != gameObjects.end())
    {
        if((*gameObject_iterator)->shouldBeDestroy())
        {
            if (auto *b = dynamic_cast<Bullet *>(*gameObject_iterator))
            {
                auto* bulletexplode = new Animation( BULLETEXPLODE , b->getPosition() , 0 );
                animations.push_back(bulletexplode);


            }
            delete *gameObject_iterator;
            gameObject_iterator = gameObjects.erase(gameObject_iterator);
        }
        else{
            (*gameObject_iterator)->move();
            ++gameObject_iterator;
        }
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

void MpManager::sendMovement()
{
    const Uint8 *state = SDL_GetKeyboardState(nullptr);
    bool keys[7] = {bool(state[SDL_SCANCODE_UP]),bool(state[SDL_SCANCODE_DOWN]),bool(state[SDL_SCANCODE_LEFT]),
                    bool(state[SDL_SCANCODE_RIGHT]),bool(state[SDL_SCANCODE_Z]),bool(state[SDL_SCANCODE_X]),bool(state[SDL_SCANCODE_SPACE])};

    auto * ep = new EventPacket();
    ep->setKeys(keys);
    ep->setId(netManager->netPlayer->id);
    ep->setTime(netManager->getGlobalTime());
    Game::netManager->udpSend(ep);
    //std::cout << "Wyslano pakiet" << std::endl;
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
                        bool del_i=false;
                        bool del_j=false;
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
                            del_i=true;
                        } else if (auto *b = dynamic_cast<Bullet *>(gameObjects[j])) {
                            del_j=true;
                        }

                        if (!(del_i && del_j))
                        {
                            if (del_i) gameObjects[i]->setToBeDestroyed();
                            if (del_j) gameObjects[j]->setToBeDestroyed();
                        }

                    }
                }
            }
        }
    }
}

