#include "Main.h"

Scene::Scene()
{
    running = true;
    flagReturn = 1;
}

void Scene::update()
{
    handleEvents();
    draw();
}
