#ifndef Scene_h
#define Scene_h

#include "Main.h"

class Scene
{
public:

    Scene( SDL_Renderer* renderer , Text* text );
    bool isRunning() { return running; }
    void update( float frameTime );
        virtual void handleEvents( float frameTime ){}
        virtual void draw( float frameTime ){}
    int getFlag() { return flagReturn ;}

protected:

    bool running;
    SDL_Renderer* renderer;
    SDL_Event eventHandler;
    Text* text;
    int flagReturn;

};

#endif
