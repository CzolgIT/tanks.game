#include "Main.h"

Wall::Wall( int x , int y , int width , int height ) : _GameObject( x , y , width , height , STATIC )
{
    collider = new Collider(x,y,width,height);
}

void Wall::draw( int x0 , int y0 )
{
    Game::textureManager->wall->render(x0 + x - width / 2, y0 + y - height / 2);
}
