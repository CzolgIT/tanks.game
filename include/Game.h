#include <iostream>
#include <SDL2/SDL.h>

class Game {
private:
  int windowHeight, windowWidth;
  SDL_Window * window = NULL;
  SDL_Surface * screenSurface = NULL;
public:
  bool Initialize();
  void CreateWindow(int width, int height);


};
