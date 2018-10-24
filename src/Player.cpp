#include "Main.h"

Player::Player( SDL_Renderer* r , Text* t , float x , float y ) : GameObject(r,x,y,100,100)
{
    text = t;
    
    direction=90;
    towerDirection=90;

    moveSpeed = 0;
    directionSpeed = 0;
    towerSpeed = 0;

    tankMaxSpeed = 256;
    tankMaxSpeedDir = 128;
    
    Texture* texture = new Texture( renderer , "assets/tex_tank.png" );

    spriteTrackLeft = new Sprite( renderer , texture , 96+122+122 , 0 , 33 , 158 , 66 , 80 );
    spriteTrackRight = new Sprite( renderer , texture , 96+122+122 , 0 , 33 , 158 , -33 , 80 );
    spriteBody = new Sprite( renderer , texture , 96 , 0 , 122 , 171 , 61 , 84 );
    spriteTower = new Sprite( renderer , texture , 0 , 0 , 96 , 128 , 48 , 64 );
    spriteBarrel = new Sprite( renderer , texture , 96 , 171+171 , 54 , 131 , 27 , 105 );
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
    
    // dzięki temu kąt obrotu będzie miał zakres 180 i zmieści się w jednym bajcie
    iDirection = round(direction/2)*2;
    iTowerDirection = round(towerDirection/2)*2;
    
    //std::cout << iDirection << "  " << iTowerDirection << "\n";
    
    // Wall limits
    if( x < 0 )
    {
        x = 0;
    }
    else if( x > SCR_W - width )
    {
        x = SCR_W - width;
    }

    if( y < 0 )
    {
        y = 0;
    }
    else if( y > SCR_H - height )
    {
        y = SCR_H - height;
    }
    
}

void Player::draw()
{
    /* RYSOWANIE PO CALYM OKNIE
    spriteTrackLeft->draw( x , y+25 , iDirection);
    spriteTrackRight->draw( x+99, y+25 , iDirection);
    spriteBody->draw( x+5, y+21 , iDirection);
    spriteTower->draw( x+18, y+41 , iTowerDirection);
    spriteBarrel->draw( x+39, y , iTowerDirection);
    */
    
    // RYSOWANIE NA SRODKU OKNA
    spriteTrackLeft->draw( SCR_W/2-66 , SCR_H/2-105+25 , iDirection);
    spriteTrackRight->draw( SCR_W/2-66+99, SCR_H/2-105+25 , iDirection);
    spriteBody->draw( SCR_W/2-66+5, SCR_H/2-105+21 , iDirection);
    spriteTower->draw( SCR_W/2-66+18, SCR_H/2-105+41 , iTowerDirection);
    spriteBarrel->draw( SCR_W/2-66+39, SCR_H/2-105 , iTowerDirection);
    
    text->draw( "x: " + std::to_string( x ) ,  500 , 500 );
    text->draw( "y: " + std::to_string( y ) ,  500 , 530 );
}
