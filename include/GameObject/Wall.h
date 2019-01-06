#ifndef Wall_h
#define Wall_h

#include "Main.h"

class Wall : public _GameObject
{
public:

    Wall( SDL_Point position );
    void draw( int x0 , int y0 );

};

#endif
