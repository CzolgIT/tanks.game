#ifndef TextureManager_h
#define TextureManager_h

#include "Main.h"

class TextureManager
{
public:

    explicit TextureManager( SDL_Renderer* r );

    // user interface
    Texture* logo;
    Texture* button;

    // map elements
    Texture* block;
    Texture* background;

    // tank sprites
    Texture* tracks;
    Texture* tower[4];
    Texture* bullet;

};

#endif
