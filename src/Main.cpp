#include "Main.h"

int main( int argc, char* args[] )
{
    Manager manager;

    NetManager netManager;
    netManager.activate();

    while( manager.isRunning() )
    {
        manager.handleEvents();
        manager.updateScreen();
    }
    return 0;
}
