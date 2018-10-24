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
    
    // metody stanu gry
    void startGame( int color );
    
private:
    bool running;

    // ważne rzeczy - managery - silniki - globalne
    SDL_Window* window;
    SDL_Renderer* renderer;
    Timer stepTimer;
    SDL_Event eventHandler;
    Text* text;
    NetManager* net;
    
    Menu* menu;
    Room* room;
    Background* background;
    
    // obiekty gry
    std::vector<GameObject*> gameObjects;
    Player* player;
};

#endif /* Manager_h */
