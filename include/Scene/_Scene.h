#ifndef Scene_h
#define Scene_h

#include "Main.h"

class _Scene
{
public:

    _Scene();
    virtual ~_Scene() = default;

    // every step
    void update();
    void handleAllEvents();
    virtual void everyStep(){}
    virtual void draw(){}

    // on action
    virtual void handleEvent(){}
    virtual void reloadGUI();
    virtual void exitScene();

    bool isRunning() { return running; }
    int getFlag() { return flagReturn; }

protected:

    SDL_Event eventHandler;
    bool running;
    int flagReturn;

};

#endif
