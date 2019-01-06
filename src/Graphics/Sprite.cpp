#include "Main.h"

Sprite::Sprite( Texture* texture , SDL_Rect clip )
{
    this->texture = texture;
    this->clip = clip;
    center.x = clip.w/2;
    center.y = clip.h/2;
}

void Sprite::draw( SDL_Point position , int direction )
{
    if (texture== nullptr )
        printf("Sprite -> Texture -> draw error");
    else
        texture->draw( position.x -center.x , position.y-center.y , SPRITESCALE , &clip, direction , &center );
}
