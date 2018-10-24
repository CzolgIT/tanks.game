#include "Main.h"

Manager::Manager()
{
    SDL_Init( SDL_INIT_VIDEO );
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    IMG_Init( IMG_INIT_PNG );

    window = SDL_CreateWindow( "Tanks Game", SCR_X , SCR_Y , SCR_W , SCR_H , SDL_WINDOW_SHOWN );
    renderer = SDL_CreateRenderer( window, -1, ACCELERATION | VSYNC );
    text = new Text( renderer , FONT_FILE );
    net = new NetManager();

    menu = new Menu( renderer , text );

    player = NULL;
    
    running = true;
}

Manager::~Manager()
{
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    window = NULL;
    renderer = NULL;
    IMG_Quit();
    SDL_Quit();
}

void Manager::updateScreen()
{
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( renderer );

    if (menu != NULL)
        menu->draw();
    
    for (int i = 0; i < gameObjects.size();i++)
    {
      gameObjects[i]->draw();
    }
    
    SDL_RenderPresent( renderer );
}

void Manager::handleEvents()
{
    while( SDL_PollEvent( &eventHandler ) != 0 )
    {
        if( eventHandler.type == SDL_QUIT )
        {
            running = false;
            break;
        }
        for (int i = 0; i < gameObjects.size();i++)
        {
            gameObjects[i]->handleEvent( eventHandler );
        }
        if (menu != NULL)
            if ( menu->handleEvent( eventHandler ) == 69 )
                startGame();
    }

    float timeStep = stepTimer.getTicks() / 1000.f;
    for (int i = 0; i < gameObjects.size();i++)
    {
        gameObjects[i]->move( timeStep );
    }
    stepTimer.start();
}

void Manager::startGame()
{
    delete menu;
    menu = NULL;
    
    player = new Player( renderer , text , 100.0 , 100.0 );
    gameObjects.push_back(player);
}
    
bool Manager::isRunning()
{
    return running;
}
