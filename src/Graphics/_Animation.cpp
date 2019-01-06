#include "Main.h"

_Animation::_Animation( Texture* tex , int frames , int width , int height , int xcenter , int ycenter , int rotation , int x , int y , int animspeed )
{
    this->frames = frames;
    this->rotation = rotation;
    this->x = x;
    this->y = y;
    for( int i=0; i<frames; i++ )
        this->Sheet[i] = new Sprite( tex , { i*width , 0 , width , height } );
    this->frame = 0;
    this->todelete = false;
    this->animspeed = animspeed;
}

void _Animation::draw(int x0, int y0)
{
    frame+= Game::stepTime * animspeed ;

    if (int(frame)>=frames)
        this->todelete = true;
    else
        this->Sheet[int(frame)]->draw( { int(x0 + x - (97*2 * TANKSCALE / 2)) , int(y0 + y - (86*2 * TANKSCALE / 2)) } ,rotation);
}

bool _Animation::gettodelete()
{
    return todelete;
}