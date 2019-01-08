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
    void SendMovement();

private:
    float ttt = 0;
    NetManager * netManager;
    Background* background = nullptr;
    std::vector<_GameObject*> gameObjects;
    std::vector<Animation*> animations;
    Player* player;

};

#endif
