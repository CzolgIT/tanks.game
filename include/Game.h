#include <iostream>
#include <SDL2/SDL.h>
#include <ECS.h>

class Game {
private:
  int windowHeight, windowWidth;
  SDL_Window * window = NULL;
  SDL_Surface * screenSurface = NULL;
  std::vector<GameObject*> gameObjects;
public:
  bool Initialize();
  void CreateWindow(int width, int height);
  void Start();
  void Update();



};
