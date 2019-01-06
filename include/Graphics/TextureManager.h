#ifndef TextureManager_h
#define TextureManager_h

#include "Main.h"

class TextureManager
{
public:

    TextureManager();

    // user interface
    Texture* button;

    // map elements
    Texture* wall;
    Texture* background;

    // tank sprites
    Texture* barrel;
    Texture* body;
    Texture* tower;
    Texture* tracks;

    Texture* bullet;

    // animation sheets
    Texture* tankdrive;
    Texture* tankshoot;
    Texture* tankexplode;
    Texture* bulletexplode;

};

#endif
