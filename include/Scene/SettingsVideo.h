#ifndef SettingsVideo_h
#define SettingsVideo_h

#include "Main.h"

class SettingsVideo : public Scene
{
public:

    SettingsVideo();
    void handleEvents();
    void draw();
    void loadDisplayModes();

private:

    std::vector<SDL_DisplayMode*> displayModeList;
    int selected;
    TextStatic* title;
    Button* button[5];

};

#endif
