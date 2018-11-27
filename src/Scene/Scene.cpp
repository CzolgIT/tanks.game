#include "Main.h"

Scene::Scene(Text* t , Configuration* c )
{
    running = true;
    flagReturn = 1;
    this->renderer = Game::renderer;
    this->text = t;
    this->configuration = c;
}

void Scene::update( float frameTime )
{
    handleEvents( frameTime );
    draw( frameTime );
}
