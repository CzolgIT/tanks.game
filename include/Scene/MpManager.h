#ifndef MpManager_h
#define MpManager_h

#include "Main.h"

class MpManager : public _Scene
{
public:

    MpManager(int color = 1);
    void handleEvents();
    void draw();
    void CheckColliders();
    void sendMovement();

    void loadFromServer();

private:
    NetManager * netManager;
    Background* background = nullptr;

    std::vector<Player*> players;
    std::vector<Bullet*> bullets;
    std::vector<_GameObject*> gameObjects;
    std::vector<Animation*> animations;
    EventPacket * prevEventPacket = nullptr;

    Player* player;

};

#endif
