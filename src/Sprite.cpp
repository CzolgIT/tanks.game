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

void Sprite::setTexture(Texture texture)
{
    spriteTexture = texture;
}

void Sprite::setRect(int x, int y, int w, int h)
{
    clip.x = x;
    clip.y = y;
    clip.w = w;
    clip.h = h;
}

void Sprite::draw(SDL_Renderer *renderer, int x, int y, int angle)
{
    //angle not used for now
    
    
    
}
