#include "Main.h"

TankSprite::TankSprite( int color , float scale )
{
    color = color%6;

    spriteBarrel = new Sprite( Game::textureManager->barrel , { 256*color , 0 , 256 , 256 } , TANKSCALE*scale );
    spriteBody = new Sprite( Game::textureManager->body , { 256*color , 0 , 256 , 256 } , TANKSCALE*scale );
    spriteTower = new Sprite( Game::textureManager->tower , { 256*color , 0 , 256 , 256 } , TANKSCALE*scale );
    for (int i=0; i<5; i++)
        spriteTracks[i] = new Sprite( Game::textureManager->tracks , { 256*i , 0 , 256 , 256 } , TANKSCALE*scale );

    step = 1;
}

void TankSprite::draw( SDL_Point position , int dir , int dirT , int move )
{
    if (move > 0)
        step++;
    if (move < 0)
        step --;
    if (step == 199) step = 0; else if (step == 0) step = 199;

    spriteTracks[(int)round(abs(step)/40)]->draw( position , dir );
    spriteBody->draw( position , dir);
    spriteTower->draw( position , dirT);
    spriteBarrel->draw( position , dirT);
}
