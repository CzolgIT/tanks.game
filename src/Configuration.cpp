
#include "Main.h"

Configuration::Configuration()
{
    readFile();
    this->window = Game::windowManager->getWindow();
    setQuality( quality );
    setFullscreen( fullscreen );
}

void Configuration::setQuality( float quality )
{
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, std::to_string(quality).c_str() );
    this->quality = quality;
    writeFile();
}

void Configuration::resizeWindow()
{
    SDL_GetWindowSize(window, &this->displayMode->w, &this->displayMode->h);
    this->scale = ((float)this->displayMode->w + (float)this->displayMode->h) / 2000;
}

void Configuration::setFullscreen( bool fullscreen )
{
    if (!fullscreen)
    {
        SDL_ShowCursor(SDL_ENABLE);
        displayMode->w=Game::windowManager->getWidth();
        displayMode->h=Game::windowManager->getHeight();
        displayMode->refresh_rate=60;
        SDL_SetWindowDisplayMode(window, this->displayMode);
        SDL_SetWindowFullscreen( window, SDL_FALSE );
        SDL_SetWindowPosition( window , SDL_WINDOWPOS_UNDEFINED , SDL_WINDOWPOS_UNDEFINED );
    }
    else
    {
        SDL_ShowCursor(SDL_DISABLE);
        SDL_GetDisplayMode(0, 0, this->displayMode);
        SDL_SetWindowDisplayMode(window, this->displayMode);
        SDL_SetWindowFullscreen( window, SDL_TRUE );
    }
    this->scale = ((float)this->displayMode->w + (float)this->displayMode->h) / 2000;
    this->fullscreen = fullscreen;
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

}

void Configuration::readFile()
{
    this->quality = 1;
    this->acceleration = true;
    this->vsync = true;
    this->displayMode = new SDL_DisplayMode{ SDL_PIXELFORMAT_UNKNOWN, 10000, 10000, 0, nullptr };
    this->fullscreen = true;
    this->debug = false;

    std::ifstream infile("config.txt");
    std::string key;

    std::string sval;
    float fval;

    while (infile.good())
    {
        infile >> key;
        sval = "";
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
        if (key == "FULLSCREEN")
        {
            infile >> sval;
            this->fullscreen = (sval != "NO");
        } else
        if (key == "SOUNDS")
        {
            infile >> sval;
            this->sounds = (sval != "NO");
        } else
        if (key == "NAME")
        {
            infile >> sval;
            this->nickname = sval ;
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

bool Configuration::getSounds()
{
    return sounds;
}

std::string Configuration::getNickname() {
    return nickname;
}

void Configuration::setNickname(const std::string &name) {

    std::string pom ("NAME");
    std::ifstream infile("config.txt");
    std::ofstream config("config1.txt");
    std::string line;

    while (std::getline(infile, line))
    {
        if( pom.compare(line.substr(0,4)) == 0)
        {
            config << "NAME " << name;
        }
        else
            config << line << "\n";
    }
    config.close();
    infile.close();

    std::rename("config1.txt","config.txt");

    Configuration::nickname = name;
}

bool Configuration::isNicknameSet() {

    if (nickname.compare("") == 0)
    {
        return false;
    }
    return true;
}

