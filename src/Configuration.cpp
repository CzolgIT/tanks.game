#include "Main.h"

Configuration::Configuration()
{
    this->window = nullptr;
    // wszystkie nastepujace dane musza zostac zaladowane z pliku

    this->quality = 1;
    this->acceleration = true;
    this->vsync = true;
        this->rendererFlags = (acceleration ? SDL_RENDERER_ACCELERATED : 0) | (vsync ? SDL_RENDERER_PRESENTVSYNC : 0);
    this->resolutionWidth = 1920;
    this->resolutionHeight = 1080;
    this->fullscreen = true;
}
void Configuration::init(SDL_Window* window)
{
    this->window = window;

    setQuality( quality );
    setFullscreen( isFullscreen() );
    setResolution( resolutionWidth , resolutionHeight );
}
void Configuration::setQuality( float quality )
{
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, std::to_string(quality).c_str() );
    this->quality = quality;
}
void Configuration::setFullscreen( bool fullscreen )
{
    fullscreen ? SDL_SetWindowFullscreen( window, SDL_TRUE ) : SDL_SetWindowFullscreen( window, SDL_FALSE );
    this->fullscreen = fullscreen;
}


void Configuration::setResolution( int resolutionWidth , int resolutionHeight)
{
    // rozdzielczosc ma byc tu przetrzymywana i ustawiana jako displaymode
    SDL_SetWindowSize( window , resolutionWidth , resolutionHeight );
    this->resolutionWidth = resolutionWidth;
    this->resolutionHeight = resolutionHeight;
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




void Configuration::saveToFile()
{
    // zapisywanie wszystkich obecnych ustawien
}