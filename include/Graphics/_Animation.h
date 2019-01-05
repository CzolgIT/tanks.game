#ifndef _Animation_h
#define _Animation_h

#include "Main.h"

class _Animation
{
public:

    _Animation( Texture* tex , int frames , int width , int height );

private:

    int frames;
    Sprite* Sheet[];

};

#endif
