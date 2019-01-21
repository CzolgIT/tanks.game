#ifndef TextureManager_h
#define TextureManager_h

#include <GUIElement/TextStatic.h>
#include "Main.h"

class TextureManager
{
public:

    TextureManager();

    // user interface
    Texture* button;
    TextStatic* youdied;

    // map elements
    Texture* background;
    Texture* map;
    Texture* mapmin;

    // tank sprites
    Texture* barrel;
    Texture* body;
    Texture* tower;
    Texture* tracks;

    // gameobjects
    Texture* bullet;
    Texture* powerups;

    // animation sheets
    Texture* tankdrive;
    Texture* tankshoot;
    Texture* tankexplode;
    Texture* bulletexplode;

    void reloadGUI();

};

#endif
