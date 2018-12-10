#pragma once

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <typeinfo>
#include <memory>
#include <queue>
#include <thread>
#include <atomic>
#include <algorithm>
#include <mutex>

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

#include "Collisions/Vector2D.h"
#include "Collisions/Projection.h"
#include "Collisions/Collider.h"

#include "Connection/BasePacket.h"
#include "Connection/HeartbeatPacket.h"
#include "Connection/JoinResponsePacket.h"
#include "Connection/JoinRequestPacket.h"
#include "Connection/UniversalPacket.h"
#include "Connection/PlayerDisconnectedPacket.h"
#include "Connection/SyncPacket.h"
#include "Connection/UDPConnection.h"
#include "Connection/TCPConnection.h"
#include "Connection/NetManager.h"

#include "Graphics/Texture.h"
#include "Graphics/Debugger.h"
#include "Graphics/TextureManager.h"
#include "Graphics/Sprite.h"
#include "Graphics/TankSprite.h"
#include "Graphics/Background.h"

#include "Text/Letter.h"
#include "Text/Font.h"
#include "Text/TextManager.h"

#include "GUIElement/_Element.h"
#include "GUIElement/TextStatic.h"
#include "GUIElement/Button.h"

#include "GameObject/_GameObject.h"
#include "GameObject/Player.h"
#include "GameObject/Bullet.h"
#include "GameObject/Wall.h"

#include "Scene/_Scene.h"
#include "Scene/_Menu.h"
#include "Scene/Settings.h"
#include "Scene/SettingsVideo.h"
#include "Scene/Room.h"
#include "Scene/MainMenu.h"
#include "Scene/Manager.h"

#include "Map.h"
#include "Timer.h"
#include "Configuration.h"
#include "Game.h"

#define delete_object(x) {delete x; x = nullptr;}

const char NICKNAME[] = "Player";

#define SERVERIP "153.19.7.230"
//#define SERVERIP "127.0.0.1"
#define SERVERPORT 7777

//Tank Globals
#define TANKMAXSPEED 200
#define TANKMAXDIR 128
#define TANKACCELERATION 3
#define TANKSCALE 0.5
#define BULLETSPEED 500

// Some Colors
const SDL_Color C_RED = { 255 , 100 , 0 };
const SDL_Color C_BLUE = { 100 , 0 , 255 };
const SDL_Color C_BLACK = { 0 , 0 , 0 };
const SDL_Color C_WHITE = { 255 , 255 , 255 };
