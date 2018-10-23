#ifndef Manager_h
#define Manager_h

#include "Main.h"

class Manager
{
public:
    Manager();

    bool init();
    void close();

    void handleEvents();
    void updateScreen();

    SDL_Window* window;
    SDL_Renderer* renderer;

    std::vector<GameObject*> gameObjects; 
    Menu* menu;

    bool isRunning();

private:
    bool running;

    Timer stepTimer;
    SDL_Event eventHandler;

    Texture* TEX_Tank;
    Texture* TEX_Menu;
};


#endif /* Manager_h */
