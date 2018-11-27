#ifndef Game_h
#define Game_h

#include "Main.h"

class Game
{
public:

    Game();
    ~Game();
    void Update();
    bool isRunning() { return running; }

private:

    SDL_Window* window;
    SDL_Renderer* renderer;
    Configuration* configuration;
    Timer* stepTimer;
    Text* text;
    NetManager* netManager;
    TextureManager* textureManager;
    Scene * currentScene;
    bool running;

};

#endif
