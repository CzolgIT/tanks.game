#ifndef Configuration_h
#define Configuration_h

#include "Main.h"

class Configuration {

public:

    Configuration();
    void init( SDL_Window* window );

    void setQuality( float quality );
    void setDisplayMode( SDL_DisplayMode* displayMode );
    void setFullscreen( bool fullscreen );
    void setAcceleration( bool acceleration );
    void setVsync( bool vsync );

    float getQuality();
    SDL_DisplayMode* getDisplayMode();
    bool isFullscreen();
    bool getAcceleration();
    bool getVsync();

        Uint32 getRendererFlags();
        float getScale();

private:

    SDL_Window* window;

    float quality; // 0 - 1
    SDL_DisplayMode* displayMode;
    bool fullscreen;
    bool acceleration;
    bool vsync;

        Uint32 rendererFlags;
        float scale;

    void writeFile();
    void readFile();

};
#endif
