#ifndef Configuration_h
#define Configuration_h

#include "Main.h"

class Configuration {

public:

    Configuration();

    float getQuality();
    void setQuality(float quality);

    bool getAcceleration();
    void setAcceleration( bool acceleration );
    bool getVsync();
    void setVsync( bool vsync );
        Uint32 getRendererFlags();

    int getResolutionWidth();
    void setResolutionWidth(int resolutionWidth);

    int getResolutionHeight();
    void setResolutionHeight(int resolutionHeight);

    bool isFullscreen();
    void setFullscreen(bool fullscreen);

private:

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
