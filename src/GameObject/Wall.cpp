#include "Main.h"

Wall::Wall(SDL_Renderer* r , int x , int y , int width, int height)
: GameObject(r, x, y, width, height , STATIC )
{
    collider = new Collider(x,y,width,height);
}

void Wall::setTexture( Texture* texture )
{
    this->texture = texture;
}

void Wall::draw( int x0 , int y0 )
{
    texture->render(renderer , x0 + x - width / 2, y0 + y - height / 2);
}
