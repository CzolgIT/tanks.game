#include "Main.h"

TankSprite::TankSprite( SDL_Renderer* r )
{
    renderer = r;
    Texture* texture = new Texture( renderer , "assets/tex_tank.png" );
    
    spriteTrackLeft = new Sprite( renderer , texture , 96+122+122 , 0 , 33 , 158 , 66 , 80 );
    spriteTrackRight = new Sprite( renderer , texture , 96+122+122 , 0 , 33 , 158 , -33 , 80 );
    spriteBody = new Sprite( renderer , texture , 96 , 0 , 122 , 171 , 61 , 84 );
    spriteTower = new Sprite( renderer , texture , 0 , 0 , 96 , 128 , 48 , 64 );
    spriteBarrel = new Sprite( renderer , texture , 96 , 171+171 , 54 , 131 , 27 , 105 );
}


void TankSprite::draw( int x , int y , int dir , int dirT )
{
    /* RYSOWANIE PO CALYM OKNIE
     spriteTrackLeft->draw( x , y+25 , iDirection);
     spriteTrackRight->draw( x+99, y+25 , iDirection);
     spriteBody->draw( x+5, y+21 , iDirection);
     spriteTower->draw( x+18, y+41 , iTowerDirection);
     spriteBarrel->draw( x+39, y , iTowerDirection);
     */
    
    // RYSOWANIE NA SRODKU OKNA
    spriteTrackLeft->draw( SCR_W/2-66 , SCR_H/2-105+25 , dir);
    spriteTrackRight->draw( SCR_W/2-66+99, SCR_H/2-105+25 , dir);
    spriteBody->draw( SCR_W/2-66+5, SCR_H/2-105+21 , dir);
    spriteTower->draw( SCR_W/2-66+18, SCR_H/2-105+41 , dirT);
    spriteBarrel->draw( SCR_W/2-66+39, SCR_H/2-105 , dirT);
    
    //text->draw( "x: " + std::to_string( x ) ,  500 , 500 );
    //text->draw( "y: " + std::to_string( y ) ,  500 , 530 );
}
