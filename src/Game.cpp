#include "Main.h"

Game::Game()
{
    configuration = new Configuration();
    SDL_Init( SDL_INIT_VIDEO );
    IMG_Init( IMG_INIT_PNG );
    window = SDL_CreateWindow("Tanks Game",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,800,600,SDL_WINDOW_SHOWN);
    configuration->init( window );
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
        {
            currentScene = new Room(renderer, text, configuration , netManager);
            Manager *manager = new Manager(renderer, text, configuration);
            Uint32 globalTime = 0;
            netManager->connect(manager->getPlayer(),"127.0.0.1",7777,globalTime);
            break;
        }
        case 2: // Singleplayer
            currentScene = new Manager(renderer, text, configuration );
            break;
        case 3: // Settings
            currentScene = new Settings(renderer, text , configuration );
            break;
        case 4: // Multiplayer-run
//            netManager->disconnectPlayer();
//todo: put player here
            currentScene = new Menu(renderer, text , configuration );
            break;
        default:
//            netManager->disconnectPlayer();
//todo: put player here
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
