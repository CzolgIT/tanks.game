#include "Main.h"

TextureManager::TextureManager()
{
    // user interface
    this->button = new Texture( "assets/button.png" );
    this->button->setAlignCenter( true );

    // map elements
    this->wall = new Texture( "assets/block.png" );
    this->background = new Texture( "assets/map.png" );
    this->city = new Texture( "assets/city_strip.png");

    // tank sprites
    this->barrel = new Texture( "assets/tank/tank_barrel.png" );
    this->body = new Texture( "assets/tank/tank_body.png" );
    this->tower = new Texture( "assets/tank/tank_tower.png" );
    this->tracks = new Texture( "assets/tank/tank_tracks.png" );

    this->bullet = new Texture( "assets/bullet.png" );

    // animation sheets
    this->tankdrive = new Texture( "assets/animation/tank_drive.png" );
    this->tankshoot = new Texture( "assets/animation/tank_shoot.png" );
    this->tankexplode = new Texture( "assets/animation/tank_explode.png" );
    this->bulletexplode = new Texture( "assets/animation/bullet_explode.png" );

    this->map = new Texture("assets/city_strip.png");

}