#include "Main.h"

Player::Player( SDL_Renderer* r , Text* t , float x , float y ) : GameObject(r,x,y,150,150)
{
    text = t;
    
    direction=90;
    towerDirection=90;

    moveSpeed = 0;
    directionSpeed = 0;
    towerSpeed = 0;

    tankMaxSpeed = 200;
    tankMaxSpeedDir = 128;
    
    sprite = new TankSprite( renderer , 1 ); // 1-4 colors
}

void Player::handleEvent( SDL_Event& e )
{
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: moveSpeed -= tankMaxSpeed; break;
            case SDLK_DOWN: moveSpeed += tankMaxSpeed; break;
            case SDLK_LEFT: directionSpeed -= tankMaxSpeedDir; break;
            case SDLK_RIGHT: directionSpeed += tankMaxSpeedDir; break;
            case SDLK_z: towerSpeed -= tankMaxSpeedDir; break;
            case SDLK_x: towerSpeed += tankMaxSpeedDir; break;
        }
    }
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: moveSpeed += tankMaxSpeed; break;
            case SDLK_DOWN: moveSpeed -= tankMaxSpeed; break;
            case SDLK_LEFT: directionSpeed += tankMaxSpeedDir; break;
            case SDLK_RIGHT: directionSpeed -= tankMaxSpeedDir; break;
            case SDLK_z: towerSpeed += tankMaxSpeedDir; break;
            case SDLK_x: towerSpeed -= tankMaxSpeedDir; break;
        }
    }
}

void Player::move( float timeStep )
{
    // move forward and back
    x += (cos(iDirection *M_PI/180) * moveSpeed * timeStep);
    y += (sin(iDirection *M_PI/180) * moveSpeed * timeStep);
    
    // rotate tank and tower
    direction += directionSpeed * timeStep ;
    towerDirection += directionSpeed * timeStep + towerSpeed * timeStep;
    
    if ( direction > 360 ) direction -= 360;
    if ( towerDirection > 360 ) towerDirection -= 360;
    
    if ( direction < 0 ) direction += 360;
    if ( towerDirection < 0 ) towerDirection += 360;
    
    // dzięki temu kąt obrotu będzie można zapisać jako liczbę
    // od 0 do 180 i zmieści się w jednym bajcie
    iDirection = round(direction/2)*2;
    iTowerDirection = round(towerDirection/2)*2;
    
    //std::cout << iDirection << "  " << iTowerDirection << "\n";
    
    // Wall limits
    if( x < width/2 )
    {
        x = width/2 ;
    }
    else if( x > 2048 - width/2 )
    {
        x = 2048 - width/2;
    }

    if( y < height/2 )
    {
        y = height/2;
    }
    else if( y > 2048 - height/2 )
    {
        y = 2048 - height/2;
    }
}

void Player::draw()
{
    sprite->draw( x , y , iDirection , iTowerDirection , moveSpeed );
    
    text->draw( "x: " + std::to_string( x ) ,  500 , 500 );
    text->draw( "y: " + std::to_string( y ) ,  500 , 530 );
}
