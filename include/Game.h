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
    static NetManager* netManager;
    static Configuration* configuration;
    static TextureManager* textureManager;
    static Text* text;
    static float stepTime;

private:

    SDL_Window* window;
    Timer* stepTimer;
    Scene * currentScene;
    bool running;

};

#endif
