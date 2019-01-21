#ifndef TANKSGAME_POWERUP_H
#define TANKSGAME_POWERUP_H

#include "Main.h"

class PowerUp: public _GameObject
{
public:

    PowerUp( int id , SDL_Point position , int type );
    void draw(int x0 , int y0) override;
    void reloadGUI();

private:

    int id;
    int type;
    Sprite* sprite;

};
#endif
