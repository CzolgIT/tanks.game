#include "Main.h"

Game::Game()
{
    SDL_Init( SDL_INIT_VIDEO );
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    IMG_Init( IMG_INIT_PNG );

    window = SDL_CreateWindow( "Tanks Game", SCR_X , SCR_Y , SCR_W , SCR_H , SDL_WINDOW_SHOWN );
    renderer = SDL_CreateRenderer( window, -1, ACCELERATION | VSYNC );
    text = new Text( renderer , FONT_FILE );
    netManager = new NetManager();
    stepTimer = new Timer();
    stepTimer->start();

    currentScene = new Menu(renderer, text);
    running = true;

}

void Game::Update()
{
    while (currentScene->isRunning())
    {
        float t = stepTimer->getTicks() / 1000.f;
        currentScene->update( t );
        stepTimer->start();
    }
    // przechowuje "flage" z poprzedniej sceny wskazujaca nastepna scene
    int flag = currentScene->getFlag();

    switch( flag )
    {
        case 0: // Menu
            currentScene = new Menu(renderer, text);
            break;
        case 1: // Multiplayer
            currentScene = new Room(renderer, text, netManager);
            break;
        case 2: // Singleplayer
            currentScene = new Manager(renderer, text, flag);
            break;
        case 3: // Settings
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Przykro mi","jeszcze nie ma opcji ustawień :(",NULL);
            currentScene = new Menu(renderer, text);
            break;
        case 4: // Multiplayer-run
            currentScene = new Manager(renderer, text, 1 ); // ta 1 jest wykrywana jako kolor, ale trzeba sie tego stad pozbyc
            break;
        default:
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"SIEMA","ELO",NULL);
            running = false;
            break;
    }
}

Game::~Game()
{
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    window = nullptr;
    renderer = nullptr;
    IMG_Quit();
    SDL_Quit();
}
