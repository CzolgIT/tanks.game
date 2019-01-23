#include "Main.h"

Timer::Timer()
{
    mStartTicks = 0;
    mPausedTicks = 0;
    
    mPaused = false;
    mStarted = false;

    start();
}

void Timer::start()
{
    mStarted = true;
    mPaused = false;

    mStartTicks = SDL_GetTicks();
    mPausedTicks = 0;
}

void Timer::stop()
{
    mStarted = false;
    mPaused = false;

    mStartTicks = 0;
    mPausedTicks = 0;
}


Uint32 Timer::getTicks()
{
    Uint32 time = 0;

    if(mStarted)
    {
        if(mPaused)
        {
            time = mPausedTicks;
        }
        else
        {
            time = SDL_GetTicks() - mStartTicks;
        }
    }
    
    return time;
}
