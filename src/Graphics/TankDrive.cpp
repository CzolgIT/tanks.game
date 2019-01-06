#include "Main.h"

TankDrive::TankDrive( int x , int y , int rotation ) : _Animation( Game::textureManager->tankdrive , 16 , 167 , 183 , 97 , 86 , rotation , x , y , 30 )
{

}