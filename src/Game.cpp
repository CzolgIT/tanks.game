#include "Main.h"

Game::Game()
{
    configuration = new Configuration();
    SDL_Init( SDL_INIT_VIDEO );
    IMG_Init( IMG_INIT_PNG );
    window = SDL_CreateWindow("Tanks Game",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,800,600,SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    configuration->init( window );
    renderer = SDL_CreateRenderer( window, -1, configuration->getRendererFlags() );
    text = new Text( renderer , FONT_FILE );
    netManager = new NetManager();
    textureManager = new TextureManager( renderer );
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
            currentScene = new Menu(renderer, text, configuration );
            break;
        case 1: // Multiplayer
            currentScene = new Room(renderer, text, configuration , netManager);
            break;
        case 2: // Singleplayer
            currentScene = new Manager(renderer, text, configuration );
            break;
        case 3: // Settings
            currentScene = new Settings(renderer, text , configuration );
            break;
        case 4: // Settings - Graphics
            currentScene = new Settings(renderer, text , configuration );
            break;
        case 5: // Settings - Audio
            currentScene = new Settings(renderer, text , configuration );
            break;
        case 6: // Settings - Control
            currentScene = new Settings(renderer, text , configuration );
            break;
        case 7: // Settings - Game
            currentScene = new Settings(renderer, text , configuration );
            break;
        case 8: // Multiplayer-run
            netManager->disconnectPlayer();
            currentScene = new Menu(renderer, text , configuration );
            break;
        default:
            netManager->disconnectPlayer();
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
