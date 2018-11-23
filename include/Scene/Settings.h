#ifndef Settings_h
#define Settings_h

#include "Main.h"

class Settings : public Scene
{
public:

    Settings( SDL_Renderer* r , Text* t , Configuration* c );
    void handleEvents( float frameTime );
    void draw( float frameTime );

private:

    int resolution;
    //???

};

#endif
