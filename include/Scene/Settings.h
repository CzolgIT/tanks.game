#ifndef Settings_h
#define Settings_h

#include "Main.h"

class Settings : public Scene
{
public:

    Settings();
    void handleEvents();
    void draw();
    void loadDisplayModes();

private:

    std::vector<SDL_DisplayMode*> displayModeList;
    int selected;
    Button* button[5];

};

#endif
