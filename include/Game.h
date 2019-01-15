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
    static Debugger* debugger;
    static TextManager* textManager;
    static WindowManager* windowManager;
    static SoundManager* soundManager;


private:

    _Scene * currentScene;
    bool running;

};

#endif
