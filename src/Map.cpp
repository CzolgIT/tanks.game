#include "Main.h"

Map::Map() {

    characters = new char[MAP_WIDTH*MAP_HEIGHT];

    for (int i = 0; i < 37; i++)
    {
        elements[i] = new Sprite(Game::textureManager->map, {160*i,0,160,160}, float(0.41 * Game::configuration->getScale()));
    }
    width=double(64) * Game::configuration->getScale();
    height=double(64) * Game::configuration->getScale();

}

void Map::getMapFromFile()
{
    //w, h - 64

    std::ifstream infile("assets/maps/map2.txt");
    char temp;

    for (int x = 0; x < MAP_WIDTH; x++)
    {
        for (int y = 0; y < MAP_HEIGHT; y++)
        {
            infile >> temp;
            characters[x*MAP_WIDTH+y] = temp;
        }

    }
    infile.close();
}

void Map::draw(int x , int y)
{

    for (int j = 0; j < MAP_HEIGHT; j++)
    {
        for (int i = 0; i < MAP_WIDTH; i++)
        {
            int xPos = int(x+width*double(i));
            int yPos = int(y+height*double(j));
            SDL_Point pos = {xPos,yPos};
            switch (characters[j*MAP_WIDTH+i])
            {
                case '1':
                    elements[0]->draw(pos,0);
                    break;
                case '2':
                    elements[1]->draw(pos,0);
                    break;
                case '3':
                    elements[2]->draw(pos,0);
                    break;
                case '4':
                    elements[3]->draw(pos,0);
                    break;
                case '5':
                    elements[4]->draw(pos,0);
                    break;
                case '6':
                    elements[5]->draw(pos,0);
                    break;
                case '7':
                    elements[6]->draw(pos,0);
                    break;
                case '8':
                    elements[7]->draw(pos,0);
                    break;
                case '9':
                    elements[8]->draw(pos,0);
                    break;
                case '0':
                    elements[9]->draw(pos,0);
                    break;
                case 'A':
                    elements[10]->draw(pos,0);
                    break;
                case 'B':
                    elements[11]->draw(pos,0);
                    break;
                case 'C':
                    elements[12]->draw(pos,0);
                    break;
                case 'D':
                    elements[13]->draw(pos,0);
                    break;
                case 'E':
                    elements[14]->draw(pos,0);
                    break;
                case 'F':
                    elements[15]->draw(pos,0);
                    break;
                case 'G':
                    elements[16]->draw(pos,0);
                    break;
                case 'H':
                    elements[17]->draw(pos,0);
                    break;
                case 'I':
                    elements[18]->draw(pos,0);
                    break;
                case 'J':
                    elements[19]->draw(pos,0);
                    break;
                case 'K':
                    elements[20]->draw(pos,0);
                    break;
                case 'L':
                    elements[21]->draw(pos,0);
                    break;
                case 'M':
                    elements[22]->draw(pos,0);
                    break;
                case 'N':
                    elements[23]->draw(pos,0);
                    break;
                case 'O':
                    elements[24]->draw(pos,0);
                    break;
                case 'P':
                    elements[25]->draw(pos,0);
                    break;
                case 'Q':
                    elements[26]->draw(pos,0);
                    break;
                case 'R':
                    elements[27]->draw(pos,0);
                    break;
                case 'S':
                    elements[28]->draw(pos,0);
                    break;
                case 'T':
                    elements[29]->draw(pos,0);
                    break;
                case 'U':
                    elements[30]->draw(pos,0);
                    break;
                case 'V':
                    elements[31]->draw(pos,0);
                    break;
                case 'W':
                    elements[32]->draw(pos,0);
                    break;
                case 'X':
                    elements[33]->draw(pos,0);
                    break;
                case 'Y':
                    elements[34]->draw(pos,0);
                    break;
                case '-':
                    elements[35]->draw(pos,0);
                    break;
                case '|':
                    elements[36]->draw(pos,0);
                    break;
                default:
                    elements[0]->draw(pos,0);
                    break;
            }
        }
    }
}

void Map::reloadGUI()
{
//    std::cout << "nowa skala: " << 0.4 * Game::configuration->getScale() << "\n";

    for (int i = 0; i < 37; i++)
    {
        delete elements[i];
        elements[i] = nullptr;
        elements[i] = new Sprite(Game::textureManager->map, {160*i,0,160,160}, 0.4 * Game::configuration->getScale());
    }
    width=int(double(64) * Game::configuration->getScale());
    height=int(double(64) * Game::configuration->getScale());
}