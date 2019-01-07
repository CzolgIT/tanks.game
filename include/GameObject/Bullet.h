#ifndef BULLET_H
#define BULLET_H

#include "Main.h"

class Bullet: public _GameObject
{
public:

    Bullet( SDL_Point position , int direction );
    void draw( int x0 , int y0 );
    void move();

private:

    //int direction;
    double floatX,floatY;

};


#endif //BULLET_H
