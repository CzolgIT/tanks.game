#include "Main.h"

Configuration::Configuration()
{
    this->window = nullptr;
    readFile();
}
void Configuration::init(SDL_Window* window)
{
    this->window = window;
    setQuality( quality );
    SDL_GetDisplayMode(0, 0, this->displayMode);
    setDisplayMode( this->displayMode );
    setFullscreen( isFullscreen() );
}
void Configuration::setQuality( float quality )
{
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, std::to_string(quality).c_str() );
    this->quality = quality;
    writeFile();
}
void Configuration::setDisplayMode( SDL_DisplayMode* displayMode )
{
    SDL_SetWindowDisplayMode( window , displayMode );
    //SDL_GetWindowDisplayMode( window , displayMode );
    this->displayMode = displayMode;
    this->scale = ((float)displayMode->w + (float)displayMode->h) / 2000;
    writeFile();
}
void Configuration::setFullscreen( bool fullscreen )
{
    fullscreen ? SDL_SetWindowFullscreen( window, SDL_TRUE ) : SDL_SetWindowFullscreen( window, SDL_FALSE );
    this->fullscreen = fullscreen;
    writeFile();
}
void Configuration::setAcceleration( bool acceleration )
{
    this->acceleration = acceleration;
    writeFile();
}
void Configuration::setVsync(bool vsync)
{
    this->vsync = vsync;
    writeFile();
}

float Configuration::getQuality() { return quality; }
SDL_DisplayMode* Configuration::getDisplayMode() { return displayMode; }
bool Configuration::isFullscreen() { return fullscreen; }
bool Configuration::getAcceleration() { return acceleration; }
bool Configuration::getVsync() { return vsync; }

    Uint32 Configuration::getRendererFlags() { return rendererFlags; }
    float Configuration::getScale() { return this->scale; }

void Configuration::writeFile()
{
    // zapisywanie wszystkich obecnych ustawien
}

void Configuration::readFile()
{
    // set default values
    this->quality = 1;
    this->acceleration = true;
    this->vsync = true;

    this->displayMode = new SDL_DisplayMode{ SDL_PIXELFORMAT_UNKNOWN, 1300, 700, 0, nullptr };
    //SDL_GetDisplayMode(0, 0, this->displayMode); // ładuje domyślną rozdzielczość

    this->fullscreen = true;

    // load from file
    std::ifstream infile("config.txt");
    std::string key;

    std::string sval;
    float fval;
    int ival;

    while (infile.good())
    {
        infile >> key;

        if (key == "QUALITY")
        {
            infile >> fval;
            //this->quality = fval;
        } else
        if (key == "ACCELERATION")
        {
            infile >> sval;
            //this->acceleration = !(sval == "NO");
        } else
        if (key == "VSYNC")
        {
            infile >> sval;
            //this->vsync = !(sval == "NO");
        } else
        if (key == "WIDTH")
        {
            infile >> ival;
            //this->displayMode.w = ival;
        } else
        if (key == "HEIGHT")
        {
            infile >> ival;
            //this->displayMode.h = ival;
        } else
        if (key == "FULLSCREEN")
        {
            infile >> sval;
            //this->fullscreen = !(sval == "NO");
        } else
            infile >> sval;
    }

    infile.close();
    this->rendererFlags = (acceleration ? SDL_RENDERER_ACCELERATED : 0) | (vsync ? SDL_RENDERER_PRESENTVSYNC : 0);
}