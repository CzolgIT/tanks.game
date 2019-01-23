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
#include <map>

#ifdef __APPLE__
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
    #include <SDL2_net/SDL_net.h>
    #include <SDL2_ttf/SDL_ttf.h>
    #include <SDL2_mixer/SDL_mixer.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_net.h>
    #include <SDL2/SDL_ttf.h>
    #include <SDL2/SDL_mixer.h>
#endif

#include "Graphics/Texture.h"
#include "Graphics/Debugger.h"
#include "Graphics/TextureManager.h"
#include "Graphics/Sprite.h"
#include "Graphics/TankSprite.h"
#include "Graphics/Animation.h"

#include "Text/Letter.h"
#include "Text/Font.h"
#include "Text/TextManager.h"

#include "GUIElement/_Element.h"
#include "GUIElement/TextStatic.h"
#include "GUIElement/Button.h"

#include "Connection/BasePacket.h"
#include "Connection/BulletInfoPacket.h"
#include "Connection/CurrentPositionPacket.h"
#include "Connection/HeartbeatPacket.h"
#include "Connection/InfoRequestPacket.h"
#include "Connection/JoinResponsePacket.h"
#include "Connection/JoinRequestPacket.h"
#include "Connection/UniversalPacket.h"
#include "Connection/MapDataPacket.h"
#include "Connection/PlayerDisconnectedPacket.h"
#include "Connection/PlayerJoinedPacket.h"
#include "Connection/PlayerReadyPacket.h"
#include "Connection/PlayerDeadPacket.h"
#include "Connection/SyncPacket.h"
#include "Connection/EventPacket.h"
#include "Connection/NetPlayer.h"
#include "Connection/UDPConnection.h"
#include "Connection/TCPConnection.h"
#include "Connection/NetManager.h"

#include "PowerUpType.h"
#include "GameObject/_GameObject.h"
#include "GameObject/Player.h"
#include "GameObject/Bullet.h"
#include "GameObject/PowerUp.h"
#include "Connection/PowerUpPacket.h"

#include "Map.h"
#include "Scene/_Scene.h"
#include "Scene/_Menu.h"
#include "Scene/Settings.h"
#include "Scene/SettingsVideo.h"
#include "Scene/SettingsGame.h"
#include "Scene/Room.h"
#include "Scene/MainMenu.h"
#include "Scene/MpManager.h"


#include "Timer.h"
#include "WindowManager.h"
#include "SoundManager.h"
#include "Configuration.h"
#include "Game.h"

#define delete_object(x) {delete x; x = nullptr;}

#define SIGMAIP "153.19.7.230"
#define LOCALIP "127.0.0.1"
//#define LOCALIP "25.63.145.1"
#define SERVERPORT 7777

#define TANKSCALE 0.5
#define BULLETSPEED 1100

const SDL_Color C_RED = { 255 , 100 , 0 };
const SDL_Color C_BLUE = { 100 , 0 , 255 };
const SDL_Color C_BLACK = { 0 , 0 , 0 };
const SDL_Color C_WHITE = { 255 , 255 , 255 };

template<class T>
std::string toString(const T&t){
    std::ostringstream stream;
    stream << t;
    return stream.str();
}