#ifndef Scene_h
#define Scene_h

#include "Main.h"

class Scene {
public:

    Scene(SDL_Renderer * renderer);
    virtual void handleEvents() {}
    virtual void draw(){}
    bool isRunning() { return running; }
    void update( float frameTime );
    int getFlag() { return flagReturn ;}
    void showFPS( float frameTime );

protected:
    bool running;
    SDL_Renderer* renderer;
    SDL_Event eventHandler;
    Text* text;
    int flagReturn;

};

#endif /* Scene_h */
