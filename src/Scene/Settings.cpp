#include "Main.h"

Settings::Settings( SDL_Renderer* renderer , Text* text ) : Scene( renderer , text )
{
    this->resolution = 1;
}