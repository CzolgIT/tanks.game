#ifndef Configuration_h
#define Configuration_h

#include "Main.h"

class Configuration {

public:

    Configuration();
    void init(SDL_Window* window);

    void setQuality(float quality);
    void setFullscreen(bool fullscreen);
    void setResolution(int resolutionWidth , int resolutionHeight);




    float getQuality();
    bool getAcceleration();
    void setAcceleration( bool acceleration );
    bool getVsync();
    void setVsync( bool vsync );
        Uint32 getRendererFlags();
    int getResolutionWidth();
    int getResolutionHeight();
    bool isFullscreen();


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
