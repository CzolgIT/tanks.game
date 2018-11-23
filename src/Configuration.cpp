#include "Main.h"

Configuration::Configuration()
{
    // wszystkie nastepujace dane musza zostac zaladowane z pliku

    this->quality = 1;
    this->acceleration = true;
    this->vsync = true;
        this->rendererFlags = (acceleration ? SDL_RENDERER_ACCELERATED : 0) | (vsync ? SDL_RENDERER_PRESENTVSYNC : 0);
    this->resolutionWidth = 1600;
    this->resolutionHeight = 900;
    this->fullscreen = false;
}

float Configuration::getQuality() { return quality; }
void Configuration::setQuality(float quality) { this->quality = quality; }

bool Configuration::getAcceleration() { return acceleration; }
void Configuration::setAcceleration( bool acceleration )
{
    this->acceleration = acceleration;
    saveToFile(); // gra musi zostac uruchomiona ponownie
}
bool Configuration::getVsync() { return vsync; }
void Configuration::setVsync(bool vsync)
{
    this->vsync = vsync;
    saveToFile(); // gra musi zostac uruchomiona ponownie
}
    Uint32 Configuration::getRendererFlags() { return rendererFlags; }

int Configuration::getResolutionWidth() { return resolutionWidth; }
void Configuration::setResolutionWidth(int resolutionWidth) { this->resolutionWidth = resolutionWidth; }

int Configuration::getResolutionHeight() { return resolutionHeight; }
void Configuration::setResolutionHeight(int resolutionHeight) { this->resolutionHeight = resolutionHeight; }

bool Configuration::isFullscreen() { return fullscreen; }
void Configuration::setFullscreen(bool fullscreen) { this->fullscreen = fullscreen; }

void Configuration::saveToFile()
{
    // zapisywanie wszystkich obecnych ustawien
}