#ifndef Wall_h
#define Wall_h

#include "Main.h"

class Wall : public _GameObject
{
public:

    Wall( int x , int y , int width , int height );
    void draw( int x0 , int y0 );

};

#endif
