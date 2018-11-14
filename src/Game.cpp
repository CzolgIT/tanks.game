#include "Main.h"

Game::Game()
{
    SDL_Init( SDL_INIT_VIDEO );
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    IMG_Init( IMG_INIT_PNG );

    window = SDL_CreateWindow( "Tanks Game", SCR_X , SCR_Y , SCR_W , SCR_H , SDL_WINDOW_SHOWN );
    renderer = SDL_CreateRenderer( window, -1, ACCELERATION | VSYNC );
    text = new Text( renderer , FONT_FILE );
    net = new NetManager();

    currentScene = new Menu(renderer, text);
    running = true;

}

void Game::Update()
{

    while (currentScene->isRunning())
    {
        currentScene->Update();

    }
    // przechowuje "flage" z poprzedniej sceny
    int pom = currentScene->getFlag();

    if (pom  < 0)
        running = false;
    if (typeid(*currentScene) == typeid(Menu))
    {
        currentScene = new Room(renderer, text);
    }
     else if (typeid(*currentScene) == typeid(Room))
    {
         currentScene = new Manager(renderer, text, pom);
    }  else running = false;

}

Game::~Game()
{
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    window = NULL;
    renderer = NULL;
    IMG_Quit();
    SDL_Quit();
}
