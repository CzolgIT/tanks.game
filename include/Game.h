#ifndef Game_h
#define Game_h

#include "Main.h"

class Game {

public:
    Game();
    //void SwitchScene(Scene * scene);
    void Update();
    bool isRunning() { return running; }
    ~Game();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    Timer* stepTimer;
    //SDL_Event eventHandler;
    Text* text;
    NetManager* netManager;
    Scene * currentScene;
    bool running;


};
#endif /* Game_h */
