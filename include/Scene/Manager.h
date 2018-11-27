#ifndef Manager_h
#define Manager_h

#include "Main.h"

class Manager : public Scene
{
public:

    Manager();
    void handleEvents();
    void draw();
    void CheckColliders();

private:

    Background* background = nullptr;
    std::vector<GameObject*> gameObjects;
    Player* player;

};

#endif
