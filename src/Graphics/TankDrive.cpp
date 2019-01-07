#include "Main.h"

TankDrive::TankDrive( SDL_Point position , int rotation ) :
    _Animation( position , {128,128} , rotation , Game::textureManager->tankdrive , 16 , 40 )
{

}