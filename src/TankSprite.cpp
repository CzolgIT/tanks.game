#include "Main.h"

TankSprite::TankSprite( SDL_Renderer* r , int color )
{
    renderer = r;
    Texture* texture = new Texture( renderer , "assets/tex_tank.png" );
 
    spriteTrackLeft[0] = new Sprite( renderer , texture , 96+122+122 , 0 , 33 , 158 , 66 , 80 );
    spriteTrackRight[0] = new Sprite( renderer , texture , 96+122+122 , 0 , 33 , 158 , -33 , 80 );
    
    spriteTrackLeft[1] = new Sprite( renderer , texture , 96+122+122+33 , 0 , 33 , 158 , 66 , 80 );
    spriteTrackRight[1] = new Sprite( renderer , texture , 96+122+122+33 , 0 , 33 , 158 , -33 , 80 );
    
    spriteTrackLeft[2] = new Sprite( renderer , texture , 96+122+122+33+33 , 0 , 33 , 158 , 66 , 80 );
    spriteTrackRight[2] = new Sprite( renderer , texture , 96+122+122+33+33 , 0 , 33 , 158 , -33 , 80 );
    
    spriteTrackLeft[3] = new Sprite( renderer , texture , 96+122+122+33+33+33 , 0 , 33 , 158 , 66 , 80 );
    spriteTrackRight[3] = new Sprite( renderer , texture , 96+122+122+33+33+33 , 0 , 33 , 158 , -33 , 80 );
    
    spriteTrackLeft[4] = new Sprite( renderer , texture , 96+122+122+33+33+33+33 , 0 , 33 , 158 , 66 , 80 );
    spriteTrackRight[4] = new Sprite( renderer , texture , 96+122+122+33+33+33+33 , 0 , 33 , 158 , -33 , 80 );
    
    if ( color == 1 )
    {
        spriteBody = new Sprite( renderer , texture , 96 , 0 , 122 , 171 , 61 , 84 );
        spriteTower = new Sprite( renderer , texture , 0 , 0 , 96 , 128 , 48 , 64 );
        spriteBarrel = new Sprite( renderer , texture , 96 , 171+171 , 54 , 131 , 27 , 105 );
    }
    if ( color == 2 )
    {
        spriteBody = new Sprite( renderer , texture , 96 , 171 , 122 , 171 , 61 , 84 );
        spriteTower = new Sprite( renderer , texture , 0 , 128 , 96 , 128 , 48 , 64 );
        spriteBarrel = new Sprite( renderer , texture , 96+54 , 171+171 , 54 , 131 , 27 , 105 );
    }
    if ( color == 3 )
    {
        spriteBody = new Sprite( renderer , texture , 96+122 , 0 , 122 , 171 , 61 , 84 );
        spriteTower = new Sprite( renderer , texture , 0 , 256 , 96 , 128 , 48 , 64 );
        spriteBarrel = new Sprite( renderer , texture , 96+54+54 , 171+171 , 54 , 131 , 27 , 105 );
    }
    if ( color == 4 )
    {
        spriteBody = new Sprite( renderer , texture , 96+122 , 171 , 122 , 171 , 61 , 84 );
        spriteTower = new Sprite( renderer , texture , 0 , 128+256 , 96 , 128 , 48 , 64 );
        spriteBarrel = new Sprite( renderer , texture , 96+54+54+54 , 171+171 , 54 , 131 , 27 , 105 );
    }
    step = 0;
}

void TankSprite::draw( int x , int y , int dir , int dirT , int move )
{
    if ( move < 0 )
    {
        step++;
        if (step == 15)
        {
            step = 0;
        }
    }
    else
    {
        step = 0 ;
    }
    spriteTrackLeft[(int)round(step/3)]->draw( SCR_W/2-66 , SCR_H/2-105+25 , dir);
    spriteTrackRight[(int)round(step/3)]->draw( SCR_W/2-66+99, SCR_H/2-105+25 , dir);
    spriteBody->draw( SCR_W/2-66+5, SCR_H/2-105+21 , dir);
    spriteTower->draw( SCR_W/2-66+18, SCR_H/2-105+41 , dirT);
    spriteBarrel->draw( SCR_W/2-66+39, SCR_H/2-105 , dirT);
}
