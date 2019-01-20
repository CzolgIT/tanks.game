#ifndef Animation_h
#define Animation_h

#include "Main.h"

enum AnimationType : Uint8{
    BULLETEXPLODE = 0,
    TANKDRIVE = 1,
    TANKSHOOT = 2,
    TANKEXPLODE = 3
};

class Animation
{
public:

    Animation( AnimationType type , SDL_Point position , int rotation );
    void draw( int x0 , int y0 );
    bool gettodelete();

    void reloadGUI();

private:

    Texture* tex;
    int frames;
    float frame;
    int rotation;
    int x,y;
    SDL_Point dimensions;
    int speed;
    bool todelete;
    Sprite* Sheet[24];

};

#endif
