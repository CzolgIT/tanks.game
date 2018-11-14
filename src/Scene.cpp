#include "Main.h"

Scene::Scene(SDL_Renderer * renderer)
{
    running = true;
    flagReturn = 1;
    this->renderer = renderer;
}

void Scene::Update() {
    handleEvents();
    draw();
}
