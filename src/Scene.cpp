#include "Main.h"

Scene::Scene(SDL_Renderer * renderer)
{
    running = true;
    this->renderer = renderer;
}

void Scene::Update() {
    handleEvents();
    draw();
}
