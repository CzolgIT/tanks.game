#include "Main.h"

TextManager::TextManager()
{
    TTF_Init();
}

TextManager::~TextManager()
{
    TTF_Quit();
}

void TextManager::draw(std::string str, int x, int y, int size, SDL_Color color, bool center , std::string path)
{
    bool found=false;

    for (auto &font : fonts)
    {
        if (font->getR() == color.r)
            if (font->getG() == color.g)
                if (font->getB() == color.b)
                    if (font->getSize() == size)
                        if (font->getPath() == path)
                        {
                            found = true;
                            font->draw(str, x, y, center);
                            break;
                        }
    }
    if (!found)
    {
        auto* newFont = new Font( path , size , color );
        fonts.push_back(newFont);
        newFont->draw(str, x, y, center);
    }
}
/*
int Text::getWidth( std::string str )
{
    int width = 0;
    for (char i : str)
        width += letter[(int) i][size]->getWidth();
    return width;
}
*/