#pragma once

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <math.h>
#include <typeinfo>
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

#include "Timer.h"
#include "Sprite.h"
#include "TankSprite.h"
#include "Scene.h"
#include "Room.h"
#include "Menu.h"
#include "Player.h"
#include "Background.h"
#include "Wall.h"
#include "NetManager.h"
#include "Manager.h" // musi być ostatni
#include "Game.h"


// SDL vars
const int ACCELERATION = 0x00000002;
const int VSYNC = 0x00000004;

// Screen position and dimensions
const int SCR_X = 300;
const int SCR_Y = 300;
const int SCR_W = 800;
const int SCR_H = 600;

// Resources
//const char TEXTURE_FILE[] = "assets/texture.png";
//const char MENU_FILE[] = "assets/png800x600.png";
const char FONT_FILE[] = "assets/font.ttf";
//const int FONT_SIZE = 42;
const char NICKNAME[] = "Player";

#define SERVERIP "153.19.7.230"
//#define SERVERIP "153.19.7.230" // sigma
//#define SERVERIP "127.0.0.1" // localhost
#define SERVERPORT 6666
#define CLIENTPORT 1666

// Some Colors
const SDL_Color C_RED = { 255 , 100 , 0 };
const SDL_Color C_BLUE = { 100 , 0 , 255 };
const SDL_Color C_BLACK = { 0 , 0 , 0 };
