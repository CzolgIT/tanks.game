#ifndef SettingsVideo_h
#define SettingsVideo_h

#include "Main.h"

class SettingsVideo : public _Menu
{
public:

    SettingsVideo();

    void actionLeft( int s );
    void actionRight( int s );

    std::string strActualDisplayMode();
    std::string strActualQuality();

private:

    std::vector<SDL_DisplayMode*> displayModeList;
    SDL_DisplayMode* newDisplayMode;

};

#endif
