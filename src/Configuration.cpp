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
    setDisplayMode( this->displayMode );
    setFullscreen( isFullscreen() );
}
void Configuration::setQuality( float quality )
{
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, std::to_string(quality).c_str() );
    this->quality = quality;
    writeFile();
}

// todo: trzeba umożliwić graczowi zmianę rozmiaru okna
// dzięki temu wysokość w trybie okna sama się ograniczy do pulpitu

void Configuration::setDisplayMode( SDL_DisplayMode* displayMode )
{
    this->displayMode = displayMode;
    if (fullscreen)
    {
        SDL_ShowCursor(SDL_DISABLE);
        if (SDL_GetClosestDisplayMode(0, displayMode, this->displayMode) == nullptr)
            SDL_GetDisplayMode(0, 0, this->displayMode);
        SDL_SetWindowDisplayMode(window, this->displayMode);
    }
    if (!fullscreen)
    {
        setWindowSize();
    }
    this->scale = ((float)this->displayMode->w + (float)this->displayMode->h) / 2000;
    writeFile();
}
void Configuration::setWindowSize()
{
    auto* mode = new SDL_DisplayMode{ SDL_PIXELFORMAT_UNKNOWN, 0, 0, 0, nullptr };
    SDL_GetDesktopDisplayMode(0, mode);
    if (this->displayMode->w < 640) this->displayMode->w = 640;
    if (this->displayMode->h < 480) this->displayMode->h = 480;
    if (this->displayMode->w > mode->w) this->displayMode->w = mode->w;
    if (this->displayMode->h > mode->h) this->displayMode->h = mode->h;
    SDL_SetWindowPosition( window , 0 , 0 );
    SDL_SetWindowSize(window, this->displayMode->w, this->displayMode->h);
    SDL_GetCurrentDisplayMode(0,displayMode);
    SDL_GetWindowSize(window, &this->displayMode->w, &this->displayMode->h);
}
void Configuration::setFullscreen( bool fullscreen )
{
    if (fullscreen)
    {
        SDL_SetWindowFullscreen( window, SDL_TRUE );

    }
    else
    {
        SDL_SetWindowFullscreen( window, SDL_FALSE );
        setWindowSize();
    }

    setDisplayMode( this->displayMode );
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
bool Configuration::getDebug() { return debug; }

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
        // it should be over all possible resolutions
        this->displayMode = new SDL_DisplayMode{ SDL_PIXELFORMAT_UNKNOWN, 10000, 10000, 0, nullptr };
    this->fullscreen = true;
    this->debug = false;

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
            this->quality = fval;
        } else
        if (key == "ACCELERATION")
        {
            infile >> sval;
            this->acceleration = (sval != "NO");
        } else
        if (key == "VSYNC")
        {
            infile >> sval;
            this->vsync = (sval != "NO");
        } else
        if (key == "WIDTH")
        {
            infile >> ival;
            this->displayMode->w = ival;
        } else
        if (key == "HEIGHT")
        {
            infile >> ival;
            this->displayMode->h = ival;
        } else
        if (key == "FULLSCREEN")
        {
            infile >> sval;
            this->fullscreen = (sval != "NO");
        } else
        if (key == "DEBUG")
        {
            infile >> sval;
            this->debug = (sval == "YES");
        } else
            infile >> sval;
    }

    infile.close();
    this->rendererFlags = (acceleration ? SDL_RENDERER_ACCELERATED : 0) | (vsync ? SDL_RENDERER_PRESENTVSYNC : 0);
}