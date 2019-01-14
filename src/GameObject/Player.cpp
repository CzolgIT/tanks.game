#include "Main.h"

Player::Player( int id, std::string nickname ) : _GameObject( {0,0} , { (int)((double)170*TANKSCALE),(int)((double)130*TANKSCALE) }  , 0 , DYNAMIC )
{
    this->id = id;
    this->nickname = nickname;

    directionFloat=0;
    towerDirection=0;

    moveSpeed = 0;
    directionSpeed = 0;
    towerSpeed = 0;

    sprite = new TankSprite( id );
    collider = new Collider( position , dimensions , direction );

    blocked = {0,0};

    xFloat = position.x;
    yFloat = position.y;
}

void Player::handleEvent( SDL_Event& e )
{
    // not used anymore
}

void Player::PushOut(Vector2D vec)
{
    blocked.x -= vec.x;
    blocked.y -= vec.y;
}

void Player::move()
{
    collider->update( position , dimensions , direction );
}

void Player::simulate()
{
    float step = Game::windowManager->getStepTime();

    xFloat += cos((direction) *M_PI/180) * tankSpeed * step;
    yFloat += sin((direction) *M_PI/180) * tankSpeed * step;

    position.x = int(xFloat);
    position.y = int(yFloat);

    directionFloat += rotationSpeed * step ;
    towerDirection += rotationSpeed * step + turretRotationSpeed * step;

    direction = int(directionFloat);
    iTowerDirection = int(towerDirection);
}

void Player::draw( int x0 , int y0 )
{
    if (id == Game::netManager->getMyId())
        sprite->draw( { Game::configuration->getDisplayMode()->w/2 , Game::configuration->getDisplayMode()->h/2 } , direction , iTowerDirection , (int)moveSpeed );
    else
        sprite->draw( { x0+position.x , y0+position.y } , direction , iTowerDirection , (int)moveSpeed );
}

void Player::drawInfo( int x0 , int y0 )
{
    Game::textManager->draw(nickname,x0+position.x,y0+position.y+40,15,C_BLACK,true);
//
//    Game::textManager->draw( std::to_string( position.x ) , x0+position.x , y0+position.y-140 , 15 , C_BLACK , true );
//    Game::textManager->draw( std::to_string( position.y ) ,  x0+position.x , y0+position.y-126 , 15 , C_BLACK , true);
//    Game::textManager->draw( std::to_string( direction ) , x0+position.x , y0+position.y-112 , 15 , C_BLACK , true);
//
//    Game::textManager->draw( std::to_string( (int)tankSpeed ) ,  x0+position.x , y0+position.y-94 , 15 , C_BLACK , true);
//    Game::textManager->draw( std::to_string( (int)rotationSpeed ) ,  x0+position.x , y0+position.y-80 , 15 , C_BLACK , true);
//    Game::textManager->draw( std::to_string( (int)turretRotationSpeed ) ,  x0+position.x , y0+position.y-66 , 15 , C_BLACK , true);

//    Game::textManager->draw( "x: " + std::to_string( position.x ) , x0+position.x , y0+position.y-140 , 15 , C_BLACK , true );
//    Game::textManager->draw( "y: " + std::to_string( position.y ) ,  x0+position.x , y0+position.y-126 , 15 , C_BLACK , true);
//    Game::textManager->draw( "d: " + std::to_string( direction ) , x0+position.x , y0+position.y-112 , 15 , C_BLACK , true);
//
//    Game::textManager->draw( "ts: " + std::to_string( (int)tankSpeed ) ,  x0+position.x , y0+position.y-94 , 15 , C_BLACK , true);
//    Game::textManager->draw( "rs: " + std::to_string( (int)rotationSpeed ) ,  x0+position.x , y0+position.y-80 , 15 , C_BLACK , true);
//    Game::textManager->draw( "trs: " + std::to_string( (int)turretRotationSpeed ) ,  x0+position.x , y0+position.y-66 , 15 , C_BLACK , true);
//
//    Game::textManager->draw( "x: " + std::to_string( position.x ) , x0+position.x , y0+position.y-140 , 15 , C_BLACK , true );
//    Game::textManager->draw( "y: " + std::to_string( position.y ) ,  x0+position.x , y0+position.y-126 , 15 , C_BLACK , true);
//    Game::textManager->draw( "d: " + std::to_string( direction ) , x0+position.x , y0+position.y-112 , 15 , C_BLACK , true);
//
//    Game::textManager->draw( "ts: " + std::to_string( (int)tankSpeed ) ,  x0+position.x , y0+position.y-94 , 15 , C_BLACK , true);
//    Game::textManager->draw( "rs: " + std::to_string( (int)rotationSpeed ) ,  x0+position.x , y0+position.y-80 , 15 , C_BLACK , true);
//    Game::textManager->draw( "trs: " + std::to_string( (int)turretRotationSpeed ) ,  x0+position.x , y0+position.y-66 , 15 , C_BLACK , true);

    //Game::textManager->draw( "sp: " + std::to_string( moveSpeed ) ,  150 , 540 );
    //Game::textManager->draw( "dir: " + std::to_string( direction ) ,  150 , 560 );
    //Game::textManager->draw( "xblock: " + std::to_string( blocked.x ) ,  550 , 500 );
    //Game::textManager->draw( "yblock: " + std::to_string( blocked.y ) ,  550 , 530 );
}

int Player::getTowDir() { return iTowerDirection; }

int Player::getDir() { return direction; }

SDL_Point Player::shootPosition()
{
    SDL_Point punkt;
    punkt.x = (int)(position.x+(cos(double(iTowerDirection) *M_PI/180) * 60));
    punkt.y = (int)(position.y+(sin(double(iTowerDirection) *M_PI/180) * 60));
    return punkt;
}
SDL_Point Player::smokePosition()
{
    int los = (random()%32)-16;


    SDL_Point punkt;
    punkt.x = (int)(position.x+(cos((direction+los) *M_PI/180) * -50));
    punkt.y = (int)(position.y+(sin((direction+los) *M_PI/180) * -50));
    return punkt;
}

int Player::getId()
{
    return id;
}

void Player::setPosition(SDL_Point position) { this->position=position; xFloat=position.x; yFloat=position.y; }
void Player::setDirection(int direction) { this->direction=direction; this->directionFloat=direction; }
void Player::setTowerDirection(int towerDirection) { this->iTowerDirection=towerDirection; this->towerDirection=towerDirection; }
void Player::setTankSpeed(int tankSpeed) { this->tankSpeed = tankSpeed; }
void Player::setRotationSpeed(int rotationSpeed) { this->rotationSpeed = rotationSpeed; }
void Player::setTurretRotationSpeed(int turretRotationSpeed) { this->turretRotationSpeed = turretRotationSpeed; }

void Player::setFromPacket( CurrentPositionPacket * packet )
{
    this->position = { packet->getX() , packet->getY() };
    this->xFloat = position.x;
    this->yFloat = position.y;
    this->direction=packet->getTankRotation();
    this->directionFloat=direction;
    this->iTowerDirection = packet->getTurretRotation();
    this->towerDirection = iTowerDirection;
    this->tankSpeed = packet->getTankSpeed();
    this->rotationSpeed = packet->getRotationSpeed();
    this->turretRotationSpeed = packet->getTurretRotationSpeed();

    this->updated=true;
}

int Player::getTankSpeed() { return tankSpeed; }

std::string Player::getNickname() {
    return std::__cxx11::string();
}
