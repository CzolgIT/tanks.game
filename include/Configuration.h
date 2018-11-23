#ifndef Configuration_h
#define Configuration_h

#include "Main.h"

class Configuration {

public:

    Configuration();

    void setWindow(SDL_Window* window);

    float getQuality();
    void setQuality(float quality);

    bool getAcceleration();
    void setAcceleration( bool acceleration );
    bool getVsync();
    void setVsync( bool vsync );
        Uint32 getRendererFlags();

    int getResolutionWidth();
    int getResolutionHeight();
    void setResolution(int resolutionWidth , int resolutionHeight);

    bool isFullscreen();
    void setFullscreen(bool fullscreen);

private:

    SDL_Window* window;

    float quality; // 0 - 1
    bool acceleration;
    bool vsync;
    Uint32 rendererFlags;

    int resolutionWidth;
    int resolutionHeight;
    bool fullscreen;

    void saveToFile();

};
#endif
