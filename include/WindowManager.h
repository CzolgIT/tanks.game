#ifndef WindowManager_h
#define WindowManager_h

#include "Main.h"

class WindowManager
{
public:

    WindowManager();
    void update();
    float getStepTime();
    SDL_Window* getWindow();

    int getWidth();
    int getHeight();

private:

    int width,height;
    SDL_Window* window;
    float stepTime;
    Timer* stepTimer;

};

#endif