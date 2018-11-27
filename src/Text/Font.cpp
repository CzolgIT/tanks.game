#include <utility>

#include "Main.h"

Font::Font( std::string path , int size , SDL_Color color )
{
    this->path = std::move(path);
    this->size = size;
    this->color = color;
}

std::string Font::getPath() { return path; }
int Font::getSize() { return size; }
int Font::getR() { return color.r; }
int Font::getG() { return color.g; }
int Font::getB() { return color.b; }

void Font::draw(std::string str, int x, int y, bool center)
{
    int posx = x;
    if (center)
    {
        TTF_Font *font = TTF_OpenFont(path.c_str(), size);
        int width;
        TTF_SizeText( font , str.c_str() , &width , nullptr);
        TTF_CloseFont( font );
        posx -= width/2;
    }
    for (char l : str)
    {
        bool found=false;

        for (auto &letter : letters)
        {
            if (letter->getCharacter() == l)
            {
                letter->draw( posx , y );
                posx += letter->getWidth();
                found = true;
                break;
            }
        }
        if (!found)
        {
            auto* newLetter = new Letter( l , path , color , size );
            letters.push_back(newLetter);
            newLetter->draw( posx , y );
            posx += newLetter->getWidth();
        }
    }
}