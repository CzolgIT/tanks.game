#include "Main.h"

Player::Player( int color , int id ) : _GameObject( {0,0} , { (int)((double)170*TANKSCALE),(int)((double)130*TANKSCALE) }  , 0 , DYNAMIC )
{
    this->id = id;

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

void Player::draw( int x0 , int y0 )
{
    if (id == Game::netManager->getMyId())
        sprite->draw( { Game::configuration->getDisplayMode()->w/2 , Game::configuration->getDisplayMode()->h/2 } , direction , iTowerDirection , (int)moveSpeed );
    else
        sprite->draw( { x0+position.x , y0+position.y } , direction , iTowerDirection , (int)moveSpeed );
}

void Player::drawInfo()
{
    Game::textManager->draw( "x: " + std::to_string( position.x ) ,  150 , 500 );
    Game::textManager->draw( "y: " + std::to_string( position.y ) ,  150 , 520 );
    Game::textManager->draw( "sp: " + std::to_string( moveSpeed ) ,  150 , 540 );
    Game::textManager->draw( "dir: " + std::to_string( direction ) ,  150 , 560 );
    Game::textManager->draw( "xblock: " + std::to_string( blocked.x ) ,  550 , 500 );
    Game::textManager->draw( "yblock: " + std::to_string( blocked.y ) ,  550 , 530 );
}

int Player::getTowDir()
{
    return iTowerDirection;
}

int Player::getDir()
{
    return direction;
}

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

void Player::setPosition(SDL_Point position)
{
    this->position = position;
}
void Player::setDirection(int direction)
{
    this->direction = direction;
}
void Player::setTowerDirection(int towerDirection)
{
    this->iTowerDirection = towerDirection;
}

int Player::getId()
{
    return id;
}