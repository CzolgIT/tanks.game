#include "Texture.h"

#ifndef Sprite_h
#define Sprite_h

class Sprite
{
public:
    void setTexture(Texture texture);
    void setRect( int x, int y, int w, int h ); // start point on texture and size
    void draw(SDL_Renderer* renderer, int x, int y, int angle = 0); // start point on window
    void setCenter( int x, int y); // to rotate image around the point
private:
    Texture spriteTexture;
    SDL_Rect clip;
    int centerX = 0;
    int centerY = 0;
};

#endif

