#include "Main.h"

Sprite::Sprite( Texture* texture , SDL_Rect clip , float scale )
{
    this->texture = texture;
    this->clip = clip;
    this->scale = scale;
    center.x = clip.w/2*scale;
    center.y = clip.h/2*scale;
}

void Sprite::draw( SDL_Point position , int direction )
{
    if (texture== nullptr )
        printf("Sprite -> Texture -> draw error");
    else
        texture->draw( position.x -center.x , position.y-center.y , scale , &clip, direction , &center );
}
