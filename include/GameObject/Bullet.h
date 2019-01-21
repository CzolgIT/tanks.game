#ifndef BULLET_H
#define BULLET_H

#include "Main.h"

class Bullet: public _GameObject
{
public:

    Bullet( SDL_Point position , int direction, int id );
    void draw( int x0 , int y0 );
    void move();
    void reloadGUI();

    int getId();

private:

    //int direction;
    int id;
    double floatX,floatY;
    Sprite * sprite;


};


#endif //BULLET_H
