#ifndef TextureManager_h
#define TextureManager_h

#include "Main.h"

class TextureManager
{
public:

    TextureManager();

    // user interface
    Texture* logo;
    Texture* button;

    // map elements
    Texture* wall;
    Texture* background;

    // tank sprites
    Texture* tracks;
    Texture* tower[4];
    Texture* bullet;

};

#endif
