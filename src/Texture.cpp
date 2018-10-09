#include <string>

#include <SDL2/SDL.h>
#ifdef __APPLE__
#include <SDL2_image/SDL_image.h>
#include <SDL2_net/SDL_net.h>
#else
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_net.h>
#endif

#include "Texture.h"

Texture::Texture()
{
    texture = NULL;
    width = 0;
    height = 0;
}
Texture::~Texture()
{
    free();
}

bool Texture::load( SDL_Renderer* renderer , std::string path )
{
    free();
    SDL_Surface* surface = IMG_Load( path.c_str() );
    if( surface == NULL )
    {
        printf("Failed to load file: %s\n",path.c_str());
        printf("SDL_Image error: %s\n",IMG_GetError());
        return false;
    }
    texture = SDL_CreateTextureFromSurface( renderer, surface );
    if( texture == NULL )
    {
        printf("Failed to load texture: %s\n",path.c_str());
        printf("SDL error: %s\n",SDL_GetError());
        return false;
    }
    width = surface->w;
    height = surface->h;
    SDL_FreeSurface( surface );
    return true;
}

void Texture::free() // Clears texture if exists
{
    if ( texture != NULL )
    {
        SDL_DestroyTexture( texture );
        texture = NULL;
        width = 0;
        height = 0;
    }
}

int Texture::getWidth()
{
    return width;
}
int Texture::getHeight()
{
    return height;
}
