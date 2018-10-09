#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "ECS.h"
#include "Tank.h"
#include "Sprite.h"
#include "Texture.h"

#ifdef __APPLE__
#include <SDL2_image/SDL_image.h>
#include <SDL2_net/SDL_net.h>
#else
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_net.h>
#endif

#ifndef Game_h
#define Game_h

class Game {
private:
  std::vector<GameObject*> gameObjects;
public:
    bool isRunning = false;

    SDL_Window * window = NULL;
    SDL_Renderer * renderer = NULL;
    SDL_Event eventhandler;

    bool Initialize();
    bool CreateWindow(int width, int height,
                    int x = SDL_WINDOWPOS_UNDEFINED,
                    int y = SDL_WINDOWPOS_UNDEFINED);
    //void Start();
    //void Update();
};

#endif
