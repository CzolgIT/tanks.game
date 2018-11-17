#include "Main.h"

Scene::Scene( SDL_Renderer* renderer )
{
    running = true;
    flagReturn = 1;
    this->renderer = renderer;
}

void Scene::update( float frameTime )
{
    handleEvents();
    //showFPS( frameTime );
    draw();
    showFPS( frameTime );
}

void Scene::showFPS( float frameTime )
{
    //text->setSize(40);
    //text->draw(std::to_string(frameTime),30,SCR_H-30);
}