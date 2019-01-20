#ifndef Map_h
#define Map_h

#include "Main.h"

#define MAP_WIDTH  32
#define MAP_HEIGHT  32

class Map
{
public:
    char * characters;
    explicit Map();
    void loadFromFile( std::vector<_GameObject*> * gameObjects );

    void draw(int x , int y);

    Sprite * elements[15] ;
    int width , height;

    void reloadGUI();

};

#endif
