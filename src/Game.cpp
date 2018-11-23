#include "Main.h"

Game::Game()
{
    configuration = new Configuration();

    SDL_Init( SDL_INIT_VIDEO );
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    IMG_Init( IMG_INIT_PNG );

    window = SDL_CreateWindow( "Tanks Game", SDL_WINDOWPOS_UNDEFINED , SDL_WINDOWPOS_UNDEFINED ,
            configuration->getResolutionWidth() , configuration->getResolutionHeight() , SDL_WINDOW_SHOWN );
    renderer = SDL_CreateRenderer( window, -1, configuration->getRendererFlags() );


    text = new Text( renderer , FONT_FILE );
    netManager = new NetManager();

    stepTimer = new Timer();
    stepTimer->start();

    currentScene = new Menu(renderer, text , configuration);
    running = true;
}

void Game::Update()
{
    while (currentScene->isRunning())
    {
        float t = stepTimer->getTicks() / 1000.f;
        stepTimer->start();
        currentScene->update( t );
    }

    int flag = currentScene->getFlag();
    switch( flag )
    {
        case 0: // Menu
            currentScene = new Menu(renderer, text, configuration);
            break;
        case 1: // Multiplayer
            currentScene = new Room(renderer, text, configuration , netManager);
            break;
        case 2: // Singleplayer
            currentScene = new Manager(renderer, text, configuration );
            break;
        case 3: // Settings
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Przykro mi","jeszcze nie ma opcji ustawień :(",nullptr);
            currentScene = new Menu(renderer, text , configuration );
            break;
        case 4: // Multiplayer-run
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"NIE MA GRANIA","przerzucam do menu!",nullptr);
            netManager->disconnectPlayer();
            currentScene = new Menu(renderer, text , configuration );
            break;
        default:
            netManager->disconnectPlayer();
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"SIEMA","ELO", nullptr);
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
