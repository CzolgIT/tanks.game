#include "Main.h"

_Animation::_Animation( Texture* tex , int frames , int width , int height )
{
    this.frames = frames;
    this->Sheet[0] = new Sprite( tex , 0 , 0 , 0 , 0 , 0 , 0 );
}