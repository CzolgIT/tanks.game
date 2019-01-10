#include "Main.h"

Debugger::Debugger()
{
    second=0;
    count=0;
    fps=0;
}

void Debugger::draw()
{
    if (Game::configuration->getDebug())
    {
        int w = Game::configuration->getDisplayMode()->w;
        int h = Game::configuration->getDisplayMode()->h;
        int f = Game::configuration->getDisplayMode()->refresh_rate;
        int j = (int)((float)h/36);

        //Game::textManager->draw( "scale: " + std::to_string(Game::configuration->getScale()) , j/6 , 33*j , j , C_BLACK , false );

        //std::string resolution = std::to_string( w )+" x "+std::to_string( h )+"  "+std::to_string( f )+"Hz";
        //Game::textManager->draw( resolution , j/6 , 35*j , j , C_BLACK , false );

        second+= Game::windowManager->getStepTime();
        count++;

        if (second>=1)
        {
            fps=count;
            second-=1;
            count=0;
        }

        Game::textManager->draw( "fps: " + std::to_string( fps ) , j/6 , 34*j , j , C_BLACK, false );
        //Game::textManager->draw( "letters: " + std::to_string( Game::textManager->lettersCount() ) , j/6 , 30*j , j , C_BLACK, false );
        //Game::textManager->draw( "fonts: " + std::to_string( Game::textManager->fontsCount() ) , j/6 , 31*j , j , C_BLACK, false );

    }
}