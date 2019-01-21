#include "Main.h"

TankSprite::TankSprite( int color , float scale )
{
    this->color = color%6;

    spriteBarrel = new Sprite( Game::textureManager->barrel , { 256*this->color , 0 , 256 , 256 } , TANKSCALE*scale );
    spriteBody = new Sprite( Game::textureManager->body , { 256*this->color , 0 , 256 , 256 } , TANKSCALE*scale );
    spriteTower = new Sprite( Game::textureManager->tower , { 256*this->color , 0 , 256 , 256 } , TANKSCALE*scale );
    for (int i=0; i<5; i++)
        spriteTracks[i] = new Sprite( Game::textureManager->tracks , { 256*i , 0 , 256 , 256 } , TANKSCALE*scale );

    step = 0;
}

void TankSprite::draw( SDL_Point position , int dir , int dirT , int move , SDL_Point turretposition )
{
    if (turretposition.x == 0 && turretposition.y == 0)
        turretposition = position;

    if (move > 0)
        step += Game::windowManager->getStepTime()*move/5;
    if (move < 0)
        step -= Game::windowManager->getStepTime()*move/5;

    while (int(step)<0) step+=5;
    while (int(step)>4) step-=5;

    spriteTracks[int(step)]->draw( position , dir );
    spriteBody->draw( position , dir);
    spriteTower->draw( position , dirT);
    spriteBarrel->draw( turretposition , dirT);
}

void TankSprite::reloadGUI()
{
    spriteBarrel = new Sprite( Game::textureManager->barrel , { 256*color , 0 , 256 , 256 } , TANKSCALE * Game::configuration->getScale() );
    spriteBody = new Sprite( Game::textureManager->body , { 256*color , 0 , 256 , 256 } , TANKSCALE * Game::configuration->getScale() );
    spriteTower = new Sprite( Game::textureManager->tower , { 256*color , 0 , 256 , 256 } , TANKSCALE * Game::configuration->getScale() );
    for (int i=0; i<5; i++)
        spriteTracks[i] = new Sprite( Game::textureManager->tracks , { 256*i , 0 , 256 , 256 } , TANKSCALE * Game::configuration->getScale() );
}