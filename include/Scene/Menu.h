#ifndef Menu_h
#define Menu_h

#include "Main.h"

class Menu : public Scene
{
public:

    Menu( SDL_Renderer* r , Text* t , Configuration* c );
    void handleEvents( float frameTime );
    void draw( float frameTime );

private:

    int selected;
    Button* button[4];
    Texture* logo;

};

#endif
