#include "Main.h"

Configuration::Configuration()
{
    this->window = nullptr;
    // wszystkie nastepujace dane musza zostac zaladowane z pliku

    this->quality = 1;
    this->acceleration = true;
    this->vsync = true;
        this->rendererFlags = (acceleration ? SDL_RENDERER_ACCELERATED : 0) | (vsync ? SDL_RENDERER_PRESENTVSYNC : 0);
    this->resolutionWidth = 1800;
    this->resolutionHeight = 1000;
    this->fullscreen = true;
}

void Configuration::setWindow(SDL_Window* window)
{
    this->window = window;
}

float Configuration::getQuality() { return quality; }
bool Configuration::getAcceleration() { return acceleration; }
bool Configuration::getVsync() { return vsync; }
    Uint32 Configuration::getRendererFlags() { return rendererFlags; }
int Configuration::getResolutionWidth()
{
    int w;
    int h;
    SDL_GetWindowSize( window , &w , &h );
    return w;
}
int Configuration::getResolutionHeight()
{
    int w;
    int h;
    SDL_GetWindowSize( window , &w , &h );
    return h;
}
bool Configuration::isFullscreen() { return fullscreen; }


void Configuration::setQuality(float quality)
{
    this->quality = quality;
}
void Configuration::setAcceleration( bool acceleration )
{
    this->acceleration = acceleration;
    saveToFile(); // gra musi zostac uruchomiona ponownie
}
void Configuration::setVsync(bool vsync)
{
    this->vsync = vsync;
    saveToFile(); // gra musi zostac uruchomiona ponownie
}
void Configuration::setResolution( int resolutionWidth , int resolutionHeight)
{
    //this->resolutionWidth = resolutionWidth;
    //this->resolutionHeight = resolutionHeight;

    // 640 x 480
    // 800 x 600
    // 832 x 624
    // 1024 x 576
    // 1024 x 768
    // 1152 x 870

    // 1280 x 960
    // 1280 x 1024
    // 1344 x 756
    // 1600 x 900
    // 1600 x 1200

    // 1920 x 1080
    // 2304 x 1296
    // 2560 x 1440
    // 3008 x 1692
    // 3200 x 1800
    // 3360 x 1890
    // 3840 x 2160





    SDL_SetWindowSize( window , 1600 , 901 );
}

void Configuration::setFullscreen( bool fullscreen)
{
    if (fullscreen)
        SDL_SetWindowFullscreen( window, SDL_TRUE );
    else
        SDL_SetWindowFullscreen( window, SDL_FALSE );
    this->fullscreen = fullscreen;
}

void Configuration::saveToFile()
{
    // zapisywanie wszystkich obecnych ustawien
}