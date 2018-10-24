#ifndef Manager_h
#define Manager_h

#include "Main.h"

class Manager
{
public:
    Manager();
    ~Manager();

    // metody do głównej pętli
    void handleEvents();
    void updateScreen();
    bool isRunning();
    
private:
    bool running;

    // ważne rzeczy - managery - silniki - globalne
    SDL_Window* window;
    SDL_Renderer* renderer;
    Timer stepTimer;
    SDL_Event eventHandler;
    Text* text;
    NetManager* net;
    
    // obiekty gry
    std::vector<GameObject*> gameObjects;
    Player* player;
    Menu* menu;
};

#endif /* Manager_h */
