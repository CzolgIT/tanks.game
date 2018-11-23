#ifndef Manager_h
#define Manager_h

#include "Main.h"

class Manager : public Scene
{
public:

    Manager(SDL_Renderer * r, Text* t , Configuration* c);
    void handleEvents( float frameTime );
    void draw( float frameTime );
    void CheckColliders();

private:

    Background* background = nullptr;
    std::vector<GameObject*> gameObjects;
    Player* player;

};

#endif
