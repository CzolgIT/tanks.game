#include <SDL2/SDL.h>
#ifdef __APPLE__
#include <SDL2_image/SDL_image.h>
#include <SDL2_net/SDL_net.h>
#else
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_net.h>
#endif

#include "Sprite.h"
#include "Texture.h"

bool Sprite::setTexture(Texture texture)
{
    
    return true;
}
