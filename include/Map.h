#ifndef Map_h
#define Map_h

#include "Main.h"

class Map
{
public:

    Map( SDL_Renderer* renderer );
    void loadFromFile( std::vector<GameObject*> * gameObjects );
private:
    SDL_Renderer* renderer;
};

#endif
