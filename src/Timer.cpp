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
    
    //Get the current clock time
    mStartTicks = SDL_GetTicks();
    mPausedTicks = 0;
}

void Timer::stop()
{
    //Stop the timer
    mStarted = false;
    
    //Unpause the timer
    mPaused = false;
    
    //Clear tick variables
    mStartTicks = 0;
    mPausedTicks = 0;
}


Uint32 Timer::getTicks()
{
    //The actual timer time
    Uint32 time = 0;
    
    //If the timer is running
    if( mStarted )
    {
        //If the timer is paused
        if( mPaused )
        {
            //Return the number of ticks when the timer was paused
            time = mPausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            time = SDL_GetTicks() - mStartTicks;
        }
    }
    
    return time;
}
