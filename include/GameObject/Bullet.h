#ifndef BULLET_H
#define BULLET_H

#include "Main.h"

class Bullet: public _GameObject
{
public:

    Bullet(int x , int y , int dir);
    void draw( int x0 , int y0 );
    void move( float timeStep );

private:

    int direction;

};


#endif //BULLET_H
