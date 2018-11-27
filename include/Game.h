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
    static SDL_Renderer* renderer;

private:

    SDL_Window* window;

    Configuration* configuration;
    Timer* stepTimer;
    Text* text;
    NetManager* netManager;
    TextureManager* textureManager;
    Scene * currentScene;
    bool running;

};

#endif
