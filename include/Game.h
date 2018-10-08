#ifndef Game_h
#define Game_h

class Game {
private:
  std::vector<GameObject*> gameObjects; // WHAT IT'S DOING ?
public:
    SDL_Window * window = NULL;
    SDL_Renderer * renderer = NULL;
    bool Initialize();
    bool CreateWindow(int width, int height,
                    int x = SDL_WINDOWPOS_UNDEFINED,
                    int y = SDL_WINDOWPOS_UNDEFINED);
    //void Start();
    //void Update();
};

#endif
