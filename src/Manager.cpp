#include "Main.h"

Manager::Manager()
{
    SDL_Init( SDL_INIT_VIDEO );
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    IMG_Init( IMG_INIT_PNG );
    TTF_Init();

    window = SDL_CreateWindow( "Tanks Game", SCREEN_X , SCREEN_Y , SCREEN_WIDTH , SCREEN_HEIGHT , SDL_WINDOW_SHOWN );
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

    text = new Text( renderer , FONT_FILE );

    //menu = new Menu( renderer );
    player = new Player( renderer , 100.0 , 100.0 );

    gameObjects.push_back(player);

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

    //menu->draw();
    for (int i = 0; i < gameObjects.size();i++)
    {
      gameObjects[i]->draw();
    }
    
    text->setColor( C_RED );
    text->setSize( 50 );
    text->draw( "Somebody" , 300 , 100 );
    text->draw( "once told me" , 340 , 130 );
    
    text->setColor( C_BLUE );
    text->setSize( 30 );
    text->draw( "the world" , 300 , 160 );
    text->draw( "is gonna roll me" , 340 , 190 );
    
    text->draw( "x: " + std::to_string( player->getX() ) ,  500 , 500 );
    text->draw( "y: " + std::to_string( player->getY() ) ,  500 , 530 );
    
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
