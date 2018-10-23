#include "Main.h"

int main( int argc, char* args[] )
{
    
    Manager manager;
    //NetManager netManager;
    //netManager.activate( "153.19.7.230" , 1616 );

    while( manager.isRunning() )
    {
        manager.handleEvents();
        manager.updateScreen();
    }

    manager.close();
    //netManager.close();
    
    return 0;
}
