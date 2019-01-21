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
    Game::soundManager->PlayTurretSound();

    for (auto const& client : Game::netManager->clientsMap){
        if (client.first != myPlayer->getId())
        {
            players.push_back(new Player( client.first , client.second ));
        }
    }

}

void MpManager::everyStep()
{
    Mix_Volume(3, abs(myPlayer->getTankSpeed()/2)  );
    Mix_Volume(4, abs(myPlayer->getTurretRotationSpeed())  );

    loadFromServer();

    // simulate movement
    for (auto &p : players)
    {
        if (!p->updated)
            p->simulate();
        p->updated = false;

        int los = int(random()%3); // generate drive animation
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

    if (!myPlayer->isDead)
        sendMovement();
    else{
        const Uint8 *state = SDL_GetKeyboardState(nullptr);
        if(state[SDL_SCANCODE_RETURN]){
            auto *playerReadyPacket = new PlayerReadyPacket;
            playerReadyPacket->setId(static_cast<Uint8>(netManager->getMyId()));
            powerUps.erase (powerUps.begin(),powerUps.end());
            netManager->tcpSend(playerReadyPacket);
            myPlayer->isDead = false;
        }
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
//                if (!player_found) {
//                    auto *newPlayer = new Player((int) packet->getPlayerId(), netManager->clientsMap[packet->getPlayerId()]);
//                    newPlayer->setFromPacket(packet);
//                    players.push_back(newPlayer);
//                    std::string info = newPlayer->getNickname();
//                    deads.push_back(new TextStatic(info.append(" joined to the game "),32,0.5,1,0.1));
//                }
                //delete packet;
            }
                break;
            case PT_PLAYER_DISCONNECTED:
            {
                auto* packet = (PlayerDisconnectedPacket *)received;

                Game::netManager->clientsMap.erase(packet->getId());

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

                bool player_found = false;
                for (auto &player : players) {
                    if (player->getId() == packet->getId()) {
                        player_found = true;
                    }
                }
                if (!player_found) {
                    auto *newPlayer = new Player((int) packet->getId(), packet->getNickname() );
                    players.push_back(newPlayer);
                    std::string info = packet->getNickname();
                    deads.push_back(new TextStatic(info.append(" joined to the game "),32,0.5,1,0.1));
                }
            }
                break;
            case PT_BULLET_INFO:
            {
                auto* packet = (BulletInfoPacket*)received;

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
                else
                {
                    auto * bullet = new Bullet( {packet->getX(),packet->getY()} , packet->getAngle() , packet->getBulletId());
                    bullets.push_back(bullet);

                    auto* tankshoot = new Animation( TANKSHOOT , {packet->getX(),packet->getY()} , packet->getAngle() );
                    animations.push_back(tankshoot);

                    Game::soundManager->PlayShootSound();
                }
            }
                break;
            case PT_PLAYER_DEAD:{
                auto* packet = (PlayerDeadPacket*) received;

                std::string info = "gracz ";
                deads.push_back(new TextStatic(info.append(toString(netManager->clientsMap[packet->getPlayerId()])).append(" zastrzelony przez ").append(toString(netManager->clientsMap[packet->getKillerId()])),32,0.5,1,0.1));

                for (auto &player : players) {
                    if (player->getId() == packet->getPlayerId())
                    {
                        Game::soundManager->PlayExplosionSound();
                        auto* tankexplode = new Animation( TANKEXPLODE , {player->getX(),player->getY()} , 0 );
                        animations.push_back(tankexplode);
                    }
                }


                if (packet->getPlayerId() == myPlayer->getId())
                {
                    myPlayer->isDead = true;
                }
            }
            break;
            case PT_POWERUP:{
                auto* packet = (PowerUpPacket*) received;

                if (packet->getToShow())
                    powerUps.push_back( new PowerUp( packet->getPowerUpId() , { packet->getX() , packet->getY() } , packet->getPowerUpType() ));
                else
                {
                    Game::soundManager->PlayPowerUpSound();
                    auto powerup_iterator = powerUps.begin();
                    while(powerup_iterator != powerUps.end())
                    {

                        if((*powerup_iterator)->getId() == packet->getPowerUpId())
                        {
                            delete *powerup_iterator;
                            powerup_iterator = powerUps.erase(powerup_iterator);
                        }
                        else
                            ++powerup_iterator;

                    }
                }

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

    int text_iter=0;
    for (auto &player     : players    )     player->draw(x0,y0);
    for (auto &bullet     : bullets    )     bullet->draw(x0,y0);
    for (auto &powerUp    : powerUps   )    powerUp->draw(x0,y0);
    for (auto &animation  : animations )  animation->draw(x0,y0);
    for (auto &player     : players    ) player->drawInfo(x0,y0);
    for (auto &text       : deads      )  text->drawInLine(text_iter++);

    if (myPlayer->isDead)
    {
        SDL_Rect ramka = {0,0,Game::configuration->getDisplayMode()->w,Game::configuration->getDisplayMode()->h};

        SDL_SetRenderDrawBlendMode(Game::renderer , SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor( Game::renderer , 0 , 0 , 0 ,120);
        SDL_RenderFillRect( Game::renderer , &ramka );

        Game::textureManager->youdied->draw();
    }

    const Uint8 *state = SDL_GetKeyboardState(nullptr);
    if(state[SDL_SCANCODE_TAB])
    {
        int w = Game::configuration->getDisplayMode()->w;
        int h = Game::configuration->getDisplayMode()->h;
        SDL_Rect statramka = {w/4,h/4,w/2,h/2};
        SDL_SetRenderDrawBlendMode(Game::renderer , SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor( Game::renderer , 0 , 0 , 0 ,120);
        SDL_RenderFillRect( Game::renderer , &statramka );

        Game::textManager->draw("id",w/4+w/40,h/4+(w/40),20*Game::configuration->getScale(),C_WHITE);
        Game::textManager->draw("nickname",w/4+w/10,h/4+(w/40),20*Game::configuration->getScale(),C_WHITE);
        Game::textManager->draw("deaths",w/4+3*w/10,h/4+(w/40),20*Game::configuration->getScale(),C_WHITE);
        Game::textManager->draw("score",w/4+4*w/10,h/4+(w/40),20*Game::configuration->getScale(),C_WHITE);

        SDL_Rect statline = {w/4+w/40,h/4+2*w/36,w/2-w/20,5};
        SDL_SetRenderDrawColor( Game::renderer , 255 , 255 , 255 ,255);
        SDL_RenderFillRect( Game::renderer , &statline );

        int iterator=3;
        for (auto &player     : players    )
        {
            Game::textManager->draw(std::to_string(player->getId()),w/4+w/40,h/4+(w/40)*iterator,20*Game::configuration->getScale(),C_WHITE);
            Game::textManager->draw(player->getNickname(),w/4+w/10,h/4+(w/40)*iterator,20*Game::configuration->getScale(),C_WHITE);
            Game::textManager->draw(std::to_string(player->getDeaths()),w/4+3*w/10,h/4+(w/40)*iterator,20*Game::configuration->getScale(),C_WHITE);
            Game::textManager->draw(std::to_string(player->getScore()),w/4+4*w/10,h/4+(w/40)*iterator,20*Game::configuration->getScale(),C_WHITE);
            iterator++;
        }

    }


    Game::debugger->draw();

    SDL_RenderPresent( Game::renderer );
}

void MpManager::reloadGUI()
{
    Game::configuration->resizeWindow();

    for (auto &player     : players    )     player->reloadGUI();
    for (auto &bullet     : bullets    )     bullet->reloadGUI();
    for (auto &powerUp    : powerUps   )    powerUp->reloadGUI();
    for (auto &animation  : animations )  animation->reloadGUI();
    map->reloadGUI();
    Game::textureManager->reloadGUI();

}

void MpManager::handleEvent()
{
    // executing only on keyboard event
    // use eventHandler
}


