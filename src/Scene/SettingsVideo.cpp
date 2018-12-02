#include "Main.h"

SettingsVideo::SettingsVideo() : _Menu(6)
{
    // najpierw buttony
    elements.push_back( new Button("resolution", 32, 9.5, 4, Game::configuration->isFullscreen() ? strActualDisplayMode() : "manual resizable" ) );
    elements.push_back( new Button("fullscreen", 32, 13.5, 4, Game::configuration->isFullscreen() ? "yes" : "no") );
    elements.push_back( new Button("quality", 32, 17.5, 4, strActualQuality() ) );
    elements.push_back( new Button("vsync", 32, 21.5, 4, Game::configuration->getVsync() ? "yes" : "no") );
    elements.push_back( new Button("max fps", 32, 25.5, 4, "option disabled") );
    elements.push_back( new Button("back", 32, 30, 3) );
    elements.push_back( new TextStatic("Video", 32, 3, 4, 0.2) );

    elements[selected]->setActive(true);
}

void SettingsVideo::actionLeft( int s )
{
    int n = SDL_GetNumDisplayModes(0);
    SDL_DisplayMode t = { SDL_PIXELFORMAT_UNKNOWN, 0, 0, 0, nullptr };
    SDL_DisplayMode* a = Game::configuration->getDisplayMode();

    switch( s )
    {
        case 0:
            if (Game::configuration->isFullscreen())
            {
                for(int i=0; i< n ; i++)
                {
                    SDL_GetDisplayMode(0, i, &t);
                    if ((t.w<a->w)||(t.w==a->w && t.h<a->h)||(t.w==a->w && t.h==a->h && t.refresh_rate<a->refresh_rate))
                    {
                        a->w = t.w;
                        a->h= t.h;
                        a->refresh_rate = t.refresh_rate;
                        Game::configuration->setDisplayMode( a );
                        Game::configuration->setWindowSize();
                        updateGUI();
                        elements[0]->setComment( strActualDisplayMode() );
                        break;
                    }
                }
            }
            break;
        case 1:
            Game::configuration->setFullscreen( !Game::configuration->isFullscreen() );
            elements[0]->setComment( Game::configuration->isFullscreen() ? strActualDisplayMode() : "manual resizable" );
            elements[1]->setComment( Game::configuration->isFullscreen() ? "yes" : "no" );
            break;
        case 2:
            if ( Game::configuration->getQuality() == 0.5 )
                Game::configuration->setQuality( 0 );
            else if ( Game::configuration->getQuality() == 1 )
                Game::configuration->setQuality( 0.5 );
            else if ( Game::configuration->getQuality() == 0 )
                Game::configuration->setQuality( 1 );
            elements[2]->setComment( strActualQuality() );
            break;
        case 3:
            Game::configuration->setVsync( !Game::configuration->getVsync() );
            elements.push_back( new TextStatic( "restart required" , 32 , 7.5 , 1 , 0.1 ) );
            elements[3]->setComment( Game::configuration->getVsync() ? "yes" : "no" );
            break;
    }
}
void SettingsVideo::actionRight( int s )
{
    int n = SDL_GetNumDisplayModes(0);
    SDL_DisplayMode t = { SDL_PIXELFORMAT_UNKNOWN, 0, 0, 0, nullptr };
    SDL_DisplayMode* a = Game::configuration->getDisplayMode();

    switch( s )
    {
        case 0:
            if (Game::configuration->isFullscreen())
            {
                for(int i=n-1; i>=0 ; i--)
                {
                    SDL_GetDisplayMode(0, i, &t);
                    if ((t.w>a->w)||(t.w==a->w && t.h>a->h)||(t.w==a->w && t.h==a->h && t.refresh_rate>a->refresh_rate))
                    {
                        a->w = t.w;
                        a->h= t.h;
                        a->refresh_rate = t.refresh_rate;
                        Game::configuration->setDisplayMode( a );
                        Game::configuration->setWindowSize();
                        updateGUI();
                        elements[0]->setComment( strActualDisplayMode() );
                        break;
                    }
                }
            }
            break;
        case 1:
            Game::configuration->setFullscreen( !Game::configuration->isFullscreen() );
            elements[0]->setComment( Game::configuration->isFullscreen() ? strActualDisplayMode() : "manual resizable" );
            elements[1]->setComment( Game::configuration->isFullscreen() ? "yes" : "no" );
            break;
        case 2:
            if ( Game::configuration->getQuality() == 0.5 )
                Game::configuration->setQuality( 1 );
            else if ( Game::configuration->getQuality() == 1 )
                Game::configuration->setQuality( 0 );
            else if ( Game::configuration->getQuality() == 0 )
                Game::configuration->setQuality( 0.5 );
            elements[2]->setComment( strActualQuality() );
            break;
        case 3:
            Game::configuration->setVsync( !Game::configuration->getVsync() );
            elements.push_back( new TextStatic( "restart required" , 32 , 7.5 , 1 , 0.1 ) );
            elements[3]->setComment( Game::configuration->getVsync() ? "yes" : "no" );
            break;
    }
}


std::string SettingsVideo::strActualDisplayMode()
{
    return std::to_string(Game::configuration->getDisplayMode()->w) + " x " + std::to_string(Game::configuration->getDisplayMode()->h) + " " +
            std::to_string(Game::configuration->getDisplayMode()->refresh_rate) + "hz";
}

std::string SettingsVideo::strActualQuality()
{
    std::string q="error";
    if (Game::configuration->getQuality() == 0) q="low";
    if (Game::configuration->getQuality() == 0.5) q="medium";
    if (Game::configuration->getQuality() == 1) q="high";
    return q;
}