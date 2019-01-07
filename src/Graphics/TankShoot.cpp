#include "Main.h"

TankShoot::TankShoot( SDL_Point position , int rotation ) :
        _Animation( position , {128,128} , rotation , Game::textureManager->tankshoot , 24 , 30 )
{

}