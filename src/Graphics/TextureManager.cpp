#include "Main.h"

TextureManager::TextureManager( SDL_Renderer* r )
{
    this->logo = new Texture( r , "assets/logo.png" );
    this->button = new Texture( r , "assets/button.png" );
}