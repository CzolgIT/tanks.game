#include "Main.h"

_Animation::_Animation( SDL_Point position , SDL_Point dimensions , int rotation , Texture* tex , int frames , int speed )
{
    this->frames = frames;
    this->rotation = rotation;
    this->x = position.x;
    this->y = position.y;
    for( int i=0; i<frames; i++ )
        this->Sheet[i] = new Sprite( tex , { i*dimensions.x , 0 , dimensions.x , dimensions.y } );
    this->frame = 0;
    this->todelete = false;
    this->speed = speed;
}

void _Animation::draw(int x0, int y0)
{
    frame+= Game::stepTime * speed ;

    if (int(frame)>=frames)
        this->todelete = true;
    else
        this->Sheet[int(frame)]->draw( { int(x0 + x) , int(y0 + y) } ,rotation);
}

bool _Animation::gettodelete()
{
    return todelete;
}