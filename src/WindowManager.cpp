#include "Main.h"

WindowManager::WindowManager()
{
    window = SDL_CreateWindow("Tanks Game",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,800,600,SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    stepTime = 0;
    stepTimer = new Timer();
    stepTimer->start();
}

void WindowManager::update() {
    stepTime = stepTimer->getTicks() / 1000.f;

    if (stepTime < 1000.f / 60.f)
    {
        SDL_Delay(1000.f / 120.f - stepTime); //- stepTimer->getTicks());
        stepTime = 1000.f / 120000.f;
    }

    // here we can stop game-time to align to specified fps

    stepTimer->start();
}

float WindowManager::getStepTime()
{
    return stepTime;
}

SDL_Window* WindowManager::getWindow()
{
    return window;
}