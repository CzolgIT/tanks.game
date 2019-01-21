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

    // map elements
    Texture* wall;
    Texture* background;
    Texture* city;

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

    Texture* map;

    TextStatic* youdied;

    void reloadGUI();


};

#endif
