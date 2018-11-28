#ifndef SettingsVideo_h
#define SettingsVideo_h

#include "Main.h"

class SettingsVideo : public _Scene
{
public:

    SettingsVideo();
    void handleEvents();
    void draw();
    void loadDisplayModes();
    std::string strActualDisplayMode();
    void updateGUI();

private:

    std::vector<SDL_DisplayMode*> displayModeList;
    int selected;
    TextStatic* title;
    TextStatic* info;
    Button* button[6];

    SDL_DisplayMode* newDisplayMode;
    bool newFullscreen;
    float newQuality;
    bool newVsync;

};

#endif
