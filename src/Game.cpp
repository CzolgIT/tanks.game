#include "Game.h"

bool Game::Initialize()
{
    // Initialize SDL library
    if(SDL_Init (SDL_INIT_EVERYTHING) < 0)
    {
        printf("SDL could not initialize!\n");
        printf("SDL Error: %s\n",SDL_GetError());
        return false;
    }


    isRunning = true;
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



    Tank * tank = new Tank();
    tank->AddComponent<Sprite>();
    SDL_RenderClear( renderer );
    if (tank->hasComponent<Sprite>())
    {
      SDL_Rect fillRect = { 114, 111, 111, 112 };
      SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );
      SDL_RenderFillRect( renderer, &fillRect );

    } else {
      SDL_SetRenderDrawColor( renderer, 0xF2, 0xAF, 0x12, 0xFF );
    }
    SDL_RenderPresent(renderer);

    return true;
}
