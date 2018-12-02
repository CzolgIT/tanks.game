#include "Main.h"

SettingsVideo::SettingsVideo() : _Menu(5)
{
    // najpierw buttony
    elements.push_back( new Button("fullscreen", 32, 13.5, 4, Game::configuration->isFullscreen() ? "yes" : "no") );
    elements.push_back( new Button("quality", 32, 17.5, 4, strActualQuality() ) );
    elements.push_back( new Button("vsync", 32, 21.5, 4, Game::configuration->getVsync() ? "yes" : "no") );
    elements.push_back( new Button("max fps", 32, 25.5, 4, "disabled") );
    elements.push_back( new Button("back", 32, 30, 3) );
    elements.push_back( new TextStatic("Video", 32, 3, 4, 0.2) );

    elements[selected]->setActive(true);
}

void SettingsVideo::actionLeft( int s )
{
    switch( s )
    {
        case 0:
            Game::configuration->setFullscreen( !Game::configuration->isFullscreen() );
            elements[0]->setComment( Game::configuration->isFullscreen() ? "yes" : "no" );
            break;
        case 1:
            if ( Game::configuration->getQuality() == 0.5 ) Game::configuration->setQuality( 0 );
            else if ( Game::configuration->getQuality() == 1 ) Game::configuration->setQuality( 0.5 );
            else if ( Game::configuration->getQuality() == 0 ) Game::configuration->setQuality( 1 );
            elements[1]->setComment( strActualQuality() );
            break;
        case 2:
            Game::configuration->setVsync( !Game::configuration->getVsync() );
            elements.push_back( new TextStatic( "restart required" , 32 , 7.5 , 1 , 0.1 ) );
            elements[2]->setComment( Game::configuration->getVsync() ? "yes" : "no" );
            break;
        case 3:
            // fps
            break;
        default:
            break;
    }
}
void SettingsVideo::actionRight( int s )
{
    switch( s )
    {
        case 0:
            Game::configuration->setFullscreen( !Game::configuration->isFullscreen() );
            elements[0]->setComment( Game::configuration->isFullscreen() ? "yes" : "no" );
            break;
        case 1:
            if ( Game::configuration->getQuality() == 0.5 )
                Game::configuration->setQuality( 1 );
            else if ( Game::configuration->getQuality() == 1 )
                Game::configuration->setQuality( 0 );
            else if ( Game::configuration->getQuality() == 0 )
                Game::configuration->setQuality( 0.5 );
            elements[1]->setComment( strActualQuality() );
            break;
        case 2:
            Game::configuration->setVsync( !Game::configuration->getVsync() );
            elements.push_back( new TextStatic( "restart required" , 32 , 7.5 , 1 , 0.1 ) );
            elements[2]->setComment( Game::configuration->getVsync() ? "yes" : "no" );
            break;
        case 3:
            // fps
            break;
        default:
            break;
    }
}
std::string SettingsVideo::strActualQuality()
{
    std::string q="error";
    if (Game::configuration->getQuality() == 0) q="low";
    if (Game::configuration->getQuality() == 0.5) q="medium";
    if (Game::configuration->getQuality() == 1) q="high";
    return q;
}