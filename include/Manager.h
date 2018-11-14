#ifndef Manager_h
#define Manager_h

#include "Main.h"

class Manager : public Scene
{
public:

    Manager(SDL_Renderer * renderer, Text* text , int color);
    void handleEvents();
    void draw();
    bool isRunning();

private:
    Background* background = NULL;

    Timer stepTimer;
    std::vector<GameObject*> gameObjects;
    Player* player;
};

#endif /* Manager_h */
