#ifndef Map_h
#define Map_h

#include "Main.h"

class Map
{
public:

    explicit Map( SDL_Renderer* r );
    void loadFromFile( std::vector<GameObject*> * gameObjects );

private:

    SDL_Renderer* renderer;

};

#endif
