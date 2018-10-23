#include "Main.h"

Manager::Manager()
{
    SDL_Init( SDL_INIT_VIDEO );
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    IMG_Init( IMG_INIT_PNG );
    TTF_Init();

    window = SDL_CreateWindow( "Tanks Game", SCREEN_X , SCREEN_Y , SCREEN_WIDTH , SCREEN_HEIGHT , SDL_WINDOW_SHOWN );
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

    text = new Text( renderer , "armyrangersexpand.ttf" );
    
    TEX_Tank = new Texture( renderer , "assets/texture.png" );
    //menu = new Menu( renderer );
    player = new Player( renderer , TEX_Tank , 100.0 , 100.0 );
    gameObjects.push_back(player);
    running = true;
}


Manager::~Manager()
{
    TEX_Tank->free();

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

    //menu->draw();
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
    }

    float timeStep = stepTimer.getTicks() / 1000.f;
    for (int i = 0; i < gameObjects.size();i++)
    {
        gameObjects[i]->move( timeStep );
    }
    stepTimer.start();
}

bool Manager::isRunning()
{
    return running;
}
