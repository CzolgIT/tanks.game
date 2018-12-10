#ifndef TextManager_h
#define TextManager_h

//#include "GUIElement/TextStatic.h"
#include "Main.h"

class TextManager
{
public:

    TextManager();
    ~TextManager();
    void draw( std::string str , int x , int y , int size=20 , SDL_Color color={ 0 , 0 , 0 } , bool center=false , std::string path="assets/font.ttf");

private:

    std::vector<Font*> fonts;

};

#endif
