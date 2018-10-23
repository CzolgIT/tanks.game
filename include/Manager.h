#ifndef Manager_h
#define Manager_h

#include "Main.h"

class Manager
{
public:
    Manager();
    ~Manager();

    void handleEvents();
    void updateScreen();

    SDL_Renderer* renderer;

    std::vector<GameObject*> gameObjects; 
    Menu* menu;

    bool isRunning();

private:
    bool running;

    SDL_Window* window;
    Timer stepTimer;
    SDL_Event eventHandler;
    Player* player;
    
    Text* text;

    Texture* TEX_Tank;
    Texture* TEX_Menu;
};


#endif /* Manager_h */
