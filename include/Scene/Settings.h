#ifndef Settings_h
#define Settings_h

#include "Main.h"

class Settings : public Scene
{
public:

    Settings( SDL_Renderer* renderer , Text* text );
    void handleEvents( float frameTime );
    void draw( float frameTime );

private:

    int resolution;
    //???

};

#endif
