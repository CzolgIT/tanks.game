#include "Main.h"

Debugger::Debugger()
{

}

void Debugger::draw()
{
    if (Game::configuration->getDebug())
    {
        int w = Game::configuration->getDisplayMode()->w;
        int h = Game::configuration->getDisplayMode()->h;
        int f = Game::configuration->getDisplayMode()->refresh_rate;
        int j = (int)((float)h/36);

        std::string resolution = std::to_string( w )+" x "+std::to_string( h )+"  "+std::to_string( f )+"Hz";

        Game::textManager->draw( resolution , j/6 , 35*j , j , C_BLACK , false );
        Game::textManager->draw( "stepTime: " + std::to_string( Game::stepTime ) , j/6 , 34*j , j , C_BLACK, false );
    }
}