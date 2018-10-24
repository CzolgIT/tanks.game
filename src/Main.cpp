#include "Main.h"

int main( int argc, char* args[] )
{
    Manager manager;
    while( manager.isRunning() )
    {
        manager.handleEvents();
        manager.updateScreen();
    }
    return 0;
}
