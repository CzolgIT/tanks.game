#include "Main.h"

Scene::Scene( SDL_Renderer* renderer , Text* text )
{
    running = true;
    flagReturn = 1;
    this->renderer = renderer;
    this->text = text;
}

void Scene::update( float frameTime )
{
    handleEvents( frameTime );
    draw( frameTime );
}