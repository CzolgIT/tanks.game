#ifndef Timer_h
#define Timer_h

#include "Main.h"

class Timer
{
public:
    Timer();
    void start();
    void stop();

    Uint32 getTicks();
    

    
private:
    Uint32 mStartTicks;
    Uint32 mPausedTicks;

    bool mPaused;
    bool mStarted;
};

#endif /* Timer_h */
