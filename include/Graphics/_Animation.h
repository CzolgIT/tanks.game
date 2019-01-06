#ifndef _Animation_h
#define _Animation_h

#include "Main.h"

class _Animation
{
public:

    _Animation( Texture* tex , int frames , int width , int height , int xcenter , int ycenter , int rotation , int x , int y , int animspeed );
    void draw( int x0 , int y0 );
    bool gettodelete();

private:

    int frames;
    float frame;
    int rotation;
    int x,y;
    int animspeed;
    bool todelete;
    Sprite* Sheet[24];

};

#endif
