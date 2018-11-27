#include "Main.h"

TextureManager::TextureManager()
{
    this->logo = new Texture( "assets/logo.png" );
    this->button = new Texture( "assets/button.png" );

    this->bullet = new Texture( "assets/bullet.png" );
    this->wall = new Texture( "assets/block2.png" );
    this->background = new Texture( "assets/tex_map.png" );

    this->tracks = new Texture( "assets/tank/tank_tracks.png" );

    this->tower[0] = new Texture( "assets/tank/tower1.png" );
    this->tower[1] = new Texture( "assets/tank/tower2.png" );
    this->tower[2] = new Texture( "assets/tank/tower3.png" );
    this->tower[3] = new Texture( "assets/tank/tower4.png" );

}