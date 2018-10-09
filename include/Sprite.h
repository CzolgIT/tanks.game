#include "Texture.h"
#include "ECS.h"
#include <SDL2/SDL.h>
#ifdef __APPLE__
#include <SDL2_image/SDL_image.h>
#include <SDL2_net/SDL_net.h>
#else
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_net.h>
#endif

#ifndef Sprite_h
#define Sprite_h

class Sprite : public Component
{
public:
    void Start();
    void Update();
    void setTexture(Texture texture);
    void setRect( int x, int y, int w, int h ); // start point on texture and size
    void draw(SDL_Renderer* renderer, int x, int y, int angle = 0); // start point on window
    void setCenter( int x, int y); // to rotate image around the point
    ~Sprite() { }
private:
    Texture spriteTexture;
    SDL_Rect clip;
    int centerX = 0;
    int centerY = 0;
};

#endif
