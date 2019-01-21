#ifndef TANKSGAME_POWERUP_H
#define TANKSGAME_POWERUP_H

#include "Main.h"

class PowerUp
{
public:

    PowerUp( int id , SDL_Point position , int type );
    void draw(int x0 , int y0);
    void reloadGUI();
    int getId();

private:

    SDL_Point position;
    int id;
    int type;
    Sprite* sprite;

};
#endif
