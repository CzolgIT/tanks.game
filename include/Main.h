#pragma once

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <math.h>

#ifdef __APPLE__
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
    #include <SDL2_net/SDL_net.h>
    #include <SDL2_ttf/SDL_ttf.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_net.h>
    #include <SDL2/SDL_ttf.h>
#endif

#include "Collider.h"
#include "GameObject.h"
#include "Texture.h"
#include "Text.h"
#include "Menu.h"
#include "Timer.h"
#include "Sprite.h"
#include "Player.h"
#include "Background.h"
#include "Manager.h"
#include "NetManager.h"
#include "Wall.h"

// Screen position and dimensions
const int SCREEN_X = 300;
const int SCREEN_Y = 300;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Resources
const char TEXTURE_FILE[] = "texture.png";
const char MENU_FILE[] = "png800x600.png";
const char FONT_FILE[] = "assets/armyrangersexpand.ttf";
const int FONT_SIZE = 42;

#define SERVERIP "153.19.7.230"
//#define SERVERIP "153.19.7.230" // sigma
//#define SERVERIP "127.0.0.1" // localhost
#define SERVERPORT 6666
#define CLIENTPORT 1666

// Some Colors
const SDL_Color C_RED = { 255 , 0 , 0 };
const SDL_Color C_BLUE = { 0 , 0 , 255 };
