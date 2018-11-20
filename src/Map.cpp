#include "Main.h"

Map::Map( SDL_Renderer* r )
{
    renderer = r;
}

void Map::loadFromFile( std::vector<GameObject*> * gameObjects )
{
    std::ifstream infile("assets/maps/map1.txt");
    int w,h;
    infile >> w >> h;
    char c;

    for(int i =0; i<h; i++)
    {
        for(int j =0; j<w; j++)
        {
            infile >> c;
            if (c == '#')
            {
                Wall * wall = new Wall( renderer , 32+j*64 , 32+i*64, 64, 64 );
                gameObjects->push_back(wall);
            }
        }
    }
}