#ifndef TextManager_h
#define TextManager_h

#include "Main.h"

class TextManager
{
public:

    TextManager();
    ~TextManager();
    void draw( std::string str , int x , int y , int size=90 , SDL_Color color={ 0 , 0 , 0 } , bool center=false , std::string path="assets/font.ttf");

private:

    std::vector<Font*> fonts;

};

#endif
