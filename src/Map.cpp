#include "Main.h"

Map::Map() {

    characters = new char[MAP_WIDTH*MAP_HEIGHT];

    // Domyslna mapa jesli zadna nie zostala otrzymana

    strcpy(characters,"EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE");

    for (int i = 0; i < 15; i++)
    {
        elements[i] = new Sprite(Game::textureManager->map, {160*i,0,160,160}, Game::configuration->getScale());
    }
    width=160 * Game::configuration->getScale();
    height=160 * Game::configuration->getScale();

}

void Map::loadFromFile( std::vector<_GameObject*> * gameObjects )
{
    std::ifstream infile("assets/maps/map2.txt");
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
                auto * wall = new Wall({ 32+j*64 , 32+i*64 });
                gameObjects->push_back(wall);
            }
        }
    }
    infile.close();
}

void Map::draw(int x , int y)
{
    for (int i = 0; i < MAP_WIDTH; i++)
    {
        for (int j = 0; j < MAP_HEIGHT; j++)
        {
            int xPos = (x+width*i);
            int yPos = (y+height*j);
            SDL_Point pos = {xPos,yPos};
            switch (characters[i*MAP_WIDTH+j])
            {
                case 'X':
                case 'D':
                    elements[12]->draw(pos,0);
                    break;
                case 'E':
                    elements[13]->draw(pos,0);
                    break;
                case 'F':
                    elements[14]->draw(pos,0);
                    break;
                default:
                    break;
            }
        }

    }


}