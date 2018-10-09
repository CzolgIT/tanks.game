#include "Texture.h"

#ifndef Sprite_h
#define Sprite_h

class Sprite
{
public:
    bool setTexture(Texture texture);
    bool setRect( int x, int y, int w, int h ); // start point on texture and size
    bool draw(SDL_Renderer* renderer, int x, int y, int angle = 0); // start point on window
    bool setCenter( int x, int y); // to rotate image around the point
private:
    Texture texture;
    SDL_Rect* clip = NULL;
    int centerX = 0;
    int centerY = 0;
};

#endif

