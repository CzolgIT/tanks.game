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
    std::cout << "Nastepna scena!" << std::endl;
    if (typeid(*currentScene) == typeid(Menu))
    {
        std::cout << "Przechodzimy do roomu!" << std::endl;
        currentScene = new Room(renderer, text);
    }
     else if (typeid(*currentScene) == typeid(Room))
    {
        std::cout << "Przechodzimy do gry! kolor: " << pom << std::endl;
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
