#include "Main.h"

TankSprite::TankSprite( int color )
{
    Texture* texTracks = Game::textureManager->tracks;
    //texTower = Game::textureManager->tower[color];

    Texture* texture = new Texture( "assets/tex_tank.png" );
 
    for (int i=0; i<5; i++)
    {
        spriteTrackLeft[i] = new Sprite( texTracks , 2+i*35 , 2 , 33 , 158 , 66*TANKSCALE , 80*TANKSCALE );
        spriteTrackRight[i] = new Sprite( texTracks , 2+i*35 , 2 , 33 , 158 , -33*TANKSCALE , 80*TANKSCALE );
    }
    spriteBody = new Sprite( texture , 96+(color>2 ? 122 : 0) , ((color+1)%2)*171 , 122 , 171 , 61*TANKSCALE , 84*TANKSCALE );
    spriteTower = new Sprite( texture , 0 , (color-1)*128 , 96 , 128 , 48*TANKSCALE , 64*TANKSCALE );
    spriteBarrel = new Sprite( texture , 42+(54*color) , 171+171 , 54 , 131 , 27*TANKSCALE , 105*TANKSCALE );
    step = 1;
}

void TankSprite::draw( int x , int y , int dir , int dirT , int move )
{
    if (move > 0)
        step++;
    if (move < 0)
        step --;
    if (step == 199) step = 0; else if (step == 0) step = 199;

    spriteTrackLeft[(int)round(abs(step)/40)]->draw( x-66*TANKSCALE , y+(-105+25)*TANKSCALE , dir);
    spriteTrackRight[(int)round(abs(step)/40)]->draw( x+(-66+99)*TANKSCALE, y+(-105+25)*TANKSCALE , dir);

    //SDL_Point* texcenter = new SDL_Point()
    //texTower->render( renderer , x, y , NULL , dir - 90 );

    spriteBody->draw( x+(-66+5)*TANKSCALE, y+(-105+21)*TANKSCALE , dir);

    spriteTower->draw( x+(-66+18)*TANKSCALE, y+(-105+41)*TANKSCALE , dirT);
    spriteBarrel->draw( x+(-66+39)*TANKSCALE, y-105*TANKSCALE , dirT);
}
