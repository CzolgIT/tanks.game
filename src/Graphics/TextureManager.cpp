#include "Main.h"

TextureManager::TextureManager()
{
    // user interface
    this->button = new Texture( "assets/button.png" );
    this->button->setAlignCenter( true );
    this->youdied = new TextStatic("you died! please enter to respawn",32,17,2,0.1);

    // map elements
    this->background = new Texture( "assets/map.png" );
    this->map = new Texture("assets/city_strip.png");
    this->mapmin = new Texture("assets/mapmin.png");

    // tank sprites
    this->barrel = new Texture( "assets/tank/tank_barrel.png" );
    this->body = new Texture( "assets/tank/tank_body.png" );
    this->tower = new Texture( "assets/tank/tank_tower.png" );
    this->tracks = new Texture( "assets/tank/tank_tracks.png" );

    // gameobjects
    this->bullet = new Texture( "assets/bullet.png" );
    this->powerups = new Texture("assets/powerups.png");

    // animation sheets
    this->tankdrive = new Texture( "assets/animation/tank_drive.png" );
    this->tankshoot = new Texture( "assets/animation/tank_shoot.png" );
    this->tankexplode = new Texture( "assets/animation/tank_explode.png" );
    this->bulletexplode = new Texture( "assets/animation/bullet_explode.png" );
}

void TextureManager::reloadGUI()
{
    delete this->youdied;
    this->youdied = nullptr;
    this->youdied = new TextStatic("you died! please enter to respawn",32,17,2,0.1);
}