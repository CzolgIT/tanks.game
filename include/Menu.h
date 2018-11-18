#ifndef Menu_h
#define Menu_h

#include "Main.h"

class Menu : public Scene
{
public:

    Menu( SDL_Renderer* r , Text* t );

    void handleEvents( float frameTime );
    void draw( float frameTime );

private:

    int selected;

};

#endif /* Menu_h */
