#ifndef _Animation_h
#define _Animation_h

#include "Main.h"

class _Animation
{
public:

    _Animation( SDL_Point position , SDL_Point dimensions , int rotation , Texture* tex , int frames , int speed );
    void draw( int x0 , int y0 );
    bool gettodelete();

private:

    int frames;
    float frame;
    int rotation;
    int x,y;
    int speed;
    bool todelete;
    Sprite* Sheet[24];

};

#endif
