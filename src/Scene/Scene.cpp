#include "Main.h"

Scene::Scene( SDL_Renderer* r , Text* t , Configuration* c )
{
    running = true;
    flagReturn = 1;
    this->renderer = r;
    this->text = t;
    this->configuration = c;
}

void Scene::update( float frameTime )
{
    handleEvents( frameTime );
    draw( frameTime );
}