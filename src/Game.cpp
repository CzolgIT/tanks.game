#include "Game.h"

bool Game::Initialize()
{
  if(SDL_Init (SDL_INIT_EVERYTHING) < 0)
  {
    return false;
  } else return true;

}

void Game::CreateWindow(int width, int height){

  windowWidth = width;
  windowHeight = height;
  window = SDL_CreateWindow( "XD", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, 0 );
  if( window == NULL )
  {
    printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
  }
  else
  {
    //Get window surface
    screenSurface = SDL_GetWindowSurface( window );

    //Fill the surface white
    SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0x1F, 0x22, 0xFB ) );

    //Update the surface
    SDL_UpdateWindowSurface( window );

    //Wait two seconds
    SDL_Delay( 2000 );
  }
}
