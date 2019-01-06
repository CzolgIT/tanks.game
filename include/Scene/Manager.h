#ifndef Manager_h
#define Manager_h

#include "Main.h"

class Manager : public _Scene
{
public:

    Manager();
    void handleEvents();
    void draw();
    void CheckColliders();

private:

    Background* background = nullptr;
    std::vector<_GameObject*> gameObjects;
    std::vector<_Animation*> animations;
    Player* player;

};

#endif

