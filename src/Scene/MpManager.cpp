#include "Main.h"

Map* MpManager::map = nullptr;

MpManager::MpManager(): _Scene()
{
    // net start
    this->netManager = Game::netManager;

    // creating player
    myPlayer = new Player( Game::netManager->getMyId(), Game::netManager->getMyNickname() );
    players.push_back(myPlayer);

    Game::soundManager->PlayBackgroundMusic();
    Game::soundManager->PlayEngineSound();
}

void MpManager::everyStep()
{
    Mix_Volume(3, myPlayer->getTankSpeed()/3  );

    loadFromServer();
    sendMovement();

    // simulate movement
    for (auto &p : players)
    {
        if (!p->updated)
            p->simulate();
        p->updated = false;

        int los = int(random()%10); // generate drive animation
        if (p->getTankSpeed()>0 && los==2)
        {
            auto* tankdrive = new Animation( TANKDRIVE , p->smokePosition() , p->getDir() );
            animations.push_back(tankdrive);
        }
    }

    // deleting bullets
    auto bullet_iterator = bullets.begin();
    while(bullet_iterator != bullets.end())
    {
        if((*bullet_iterator)->shouldBeDestroy())
        {
            auto* bulletexplode = new Animation( BULLETEXPLODE , (*bullet_iterator)->getPosition() , 0 );
            animations.push_back(bulletexplode);

            delete *bullet_iterator;
            bullet_iterator = bullets.erase(bullet_iterator);
        }
        else{
            (*bullet_iterator)->move();
            ++bullet_iterator;
        }
    }

    // deleting animations
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

void MpManager::loadFromServer()
{
    Game::netManager->read(); // load all packets

    while ( Game::netManager->canPollPacket() )
    {
        BasePacket* received = Game::netManager->pollPacket();

        switch (received->getType())
        {
            case PT_CURRENT_POSITION:
            {
                auto *packet = (CurrentPositionPacket *)received;
                bool player_found = false;
                for (auto &player : players) {
                    if (player->getId() == packet->getPlayerId()) {
                        player_found = true;
                        player->setFromPacket(packet);
                    }
                }
                if (!player_found) {
                    auto *newPlayer = new Player((int) packet->getPlayerId(), netManager->clientsMap[packet->getPlayerId()]);
                    newPlayer->setFromPacket(packet);
                    players.push_back(newPlayer);
                }
                //delete packet;
            }
                break;
            case PT_PLAYER_DISCONNECTED:
            {
                auto* packet = (PlayerDisconnectedPacket *)received;
                auto players_iterator = players.begin();
                while(players_iterator != players.end())
                {
                    if (packet->getId() == (*players_iterator)->getId())
                    {
                        delete *players_iterator;
                        players_iterator = players.erase(players_iterator);
                    }
                    else
                        ++players_iterator;
                }
                //delete packet;
            }
                break;
            case PT_PLAYER_JOINED:
            {
                auto* packet = (PlayerJoinedPacket*)received;

                auto *newPlayer = new Player(packet->getId(),packet->getNickname());
                players.push_back(newPlayer);

                packet->print();
                //delete packet;
            }
                break;
            case PT_BULLET_INFO:
            {
                auto* packet = (BulletInfoPacket*)received;

                int bx = int(packet->getX()*Game::configuration->getScale());
                int by = int(packet->getY()*Game::configuration->getScale());

                if ((int)packet->getX() == 0 || (int)packet->getY() == 0)
                {
                    for (auto &bullet: bullets)
                    {
                        if (bullet->getId() == packet->getBulletId())
                        {
                            bullet->setToBeDestroyed();
                        }
                    }
                    break;
                }


                auto * bullet = new Bullet( {bx,by} , packet->getAngle() , packet->getBulletId());
                bullets.push_back(bullet);

                auto* tankshoot = new Animation( TANKSHOOT , {bx,by} , packet->getAngle() );
                animations.push_back(tankshoot);

                Game::soundManager->PlayShootSound();
                //delete packet;
            }
                break;
        }
        delete received;
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
    if(prevEventPacket!= nullptr){
        if(!ep->compare(prevEventPacket)){
            //delete_object(prevEventPacket);
            std::cout << "wysłałem nowy pakiet" << std::endl;
            Game::netManager->udpSend(ep);
            prevEventPacket = new EventPacket();
            prevEventPacket->setId(ep->getId());
            prevEventPacket->setKeys(ep->getKeys());
        }else{
//            std::cout << "nic sie nie stalo" << std::endl;
        }
    }else{
        //delete_object(prevEventPacket);
        prevEventPacket = new EventPacket();
        prevEventPacket->setId(ep->getId());
        prevEventPacket->setKeys(ep->getKeys());
        std::cout << "przypisałem nowy pakiet jako wzorcowy" << std::endl;
        Game::netManager->udpSend(ep);
    }
    //std::cout << "Wyslano pakiet" << std::endl;
}


void MpManager::draw()
{
    SDL_SetRenderDrawColor( Game::renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( Game::renderer );

    auto x0 = (int)((float)Game::configuration->getDisplayMode()->w/2-myPlayer->getX() * Game::configuration->getScale() );
    auto y0 = (int)((float)Game::configuration->getDisplayMode()->h/2-myPlayer->getY() * Game::configuration->getScale() );

    MpManager::map->draw(x0 ,y0);

    for (auto &gameObject : gameObjects) gameObject->draw(x0,y0);
    for (auto &player     : players    )     player->draw(x0,y0);
    for (auto &bullet     : bullets    )     bullet->draw(x0,y0);
    for (auto &animation  : animations )  animation->draw(x0,y0);
    for (auto &player     : players    ) player->drawInfo(x0,y0);

    Game::debugger->draw();

    SDL_RenderPresent( Game::renderer );
}

void MpManager::handleEvent()
{
    // executing only on keyboard event
    // use eventHandler
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

