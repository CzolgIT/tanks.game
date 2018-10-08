#include <iostream>
#include <SDL2/SDL.h>
#include "ECS.h"
#include "Game.h"


int main(int argc, char * argv[])
{
  Game * game = new Game();
  if (game->Initialize())
    game->CreateWindow(600, 400);
  else std::cout << "MEH" << std::endl;
  return 0;
}
