#include "Main.h"

TankSprite::TankSprite( SDL_Renderer* r , int color )
{
    renderer = r;
    Texture* texture = new Texture( renderer , "assets/tex_tank.png" );
 
    for (int i=0; i<5; i++)
    {
        spriteTrackLeft[i] = new Sprite( renderer , texture , 96+122+122+(i*33) , 0 , 33 , 158 , 66 , 80 );
        spriteTrackRight[i] = new Sprite( renderer , texture , 96+122+122+(i*33) , 0 , 33 , 158 , -33 , 80 );
    }
    spriteBody = new Sprite( renderer , texture , 96+(color>2 ? 122 : 0) , ((color+1)%2)*171 , 122 , 171 , 61 , 84 );
    spriteTower = new Sprite( renderer , texture , 0 , (color-1)*128 , 96 , 128 , 48 , 64 );
    spriteBarrel = new Sprite( renderer , texture , 42+(54*color) , 171+171 , 54 , 131 , 27 , 105 );
    step = 0;
}

void TankSprite::draw( int x , int y , int dir , int dirT , int move )
{
    if ( move < 0 )
    {
        step++;
        if (step == 15)
            step = 0;
    }
    else
        step = 0 ;
    
    spriteTrackLeft[(int)round(step/3)]->draw( x-66 , y-105+25 , dir);
    spriteTrackRight[(int)round(step/3)]->draw( x-66+99, y-105+25 , dir);
    spriteBody->draw( x-66+5, y-105+21 , dir);
    spriteTower->draw( x-66+18, y-105+41 , dirT);
    spriteBarrel->draw( x-66+39, y-105 , dirT);
}
