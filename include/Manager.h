#ifndef Manager_h
#define Manager_h

#include "Main.h"

class Manager : public Scene
{
public:

    Manager(SDL_Renderer * renderer, Text* text , int color);
    void handleEvents( float frameTime );
    void draw( float frameTime );

private:
    Background* background = nullptr;
    std::vector<GameObject*> gameObjects;
    Player* player;
};

#endif /* Manager_h */
