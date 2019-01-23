#include "Main.h"

int main( int argc, char* args[] )
{
    Game game;
    while( game.isRunning())
    {
        game.Update();
    }
    return 0;
}




