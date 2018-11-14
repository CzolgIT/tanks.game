#include "Main.h"

int main( int argc, char* args[] )
{
    Game game;

    NetManager netManager;
    netManager.activate();

    while( game.isRunning())
    {
        game.Update();
    }
    return 0;
}
