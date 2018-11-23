#ifndef Settings_h
#define Settings_h

#include "Main.h"

class Settings : public Scene
{
public:

    Settings( SDL_Renderer* r , Text* t , Configuration* c );
    void handleEvents( float frameTime );
    void draw( float frameTime );
    void loadDisplayModes();

private:

    std::vector<SDL_DisplayMode*> displayModeList;
    int resolution;
    //???

};

#endif
