#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_net/SDL_net.h>
#include "ECS.h"
#include "Game.h"
#include "Texture.h"

bool Game::Initialize()
{
    // Initialize SDL library
    if(SDL_Init (SDL_INIT_EVERYTHING) < 0)
    {
        printf("SDL could not initialize!\n");
        printf("SDL Error: %s\n",SDL_GetError());
        return false;
    }

    //Initialize SDL_image library
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf("SDL_image could not initialize!\n");
        printf("SDL_mage Error: %s\n",IMG_GetError());
        return false;
    }
    return true;
}

bool Game::CreateWindow(int width, int height, int x, int y)
{
    //Create window
    window = SDL_CreateWindow("Tanksgame", x, y, width, height, 0 );
    if( window == NULL )
    {
        printf("Window could not be created!\n");
        printf("SDL_Error: %s\n",SDL_GetError());
        return false;
    }
    //Create renderer for window
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    if( renderer == NULL )
    {
        printf("Renderer could not be created!\n");
        printf("SDL Error: %s\n",SDL_GetError());
        return false;
    }
    //Initialize renderer color
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    return true;
}
