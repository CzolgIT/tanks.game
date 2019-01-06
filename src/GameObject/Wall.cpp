#include "Main.h"

Wall::Wall( SDL_Point position ) : _GameObject( position , {64,64} , 0 , STATIC )
{
    collider = new Collider( position , dimensions , direction );
}

void Wall::draw( int x0 , int y0 )
{
    Game::textureManager->wall->draw(x0 + position.x - dimensions.x / 2, y0 + position.y - dimensions.y / 2);
}
