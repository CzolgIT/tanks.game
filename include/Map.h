#ifndef Map_h
#define Map_h

#include "Main.h"

#define MAP_WIDTH  64
#define MAP_HEIGHT  64

class Map
{
public:
    char * characters;
    explicit Map();

    void getMapFromFile();

    void draw(int x , int y);

    Sprite * elements[37] ;
    double width , height;

    void reloadGUI();

};

#endif
