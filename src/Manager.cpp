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
    background = NULL;
    
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
    else
    {
        background->draw( SCR_W/2-player->getX() , SCR_H/2-player->getY() );
        for (int i = 0; i < gameObjects.size();i++)
        {
          gameObjects[i]->draw();
        }
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
        {
            int flag = menu->handleEvent( eventHandler );
            if ( flag == 69 )
                startGame();
            if ( flag == 22 )
                running = false;
        }
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
    
    background = new Background( renderer );
    player = new Player( renderer , text , SCR_W/2 - 50 , SCR_H/2 - 50 );
    gameObjects.push_back(player);
}
    
bool Manager::isRunning()
{
    return running;
}
