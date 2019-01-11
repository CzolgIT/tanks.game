#include "Main.h"

WindowManager* Game::windowManager = nullptr;
Configuration* Game::configuration = nullptr;
SDL_Renderer* Game::renderer = nullptr;
TextManager* Game::textManager = nullptr;
TextureManager* Game::textureManager = nullptr;
Debugger* Game::debugger = nullptr;
NetManager* Game::netManager = nullptr;
SoundManager* Game::soundManager = nullptr;

Game::Game()
{
    SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    IMG_Init( IMG_INIT_PNG );

    windowManager = new WindowManager();
    configuration = new Configuration();
    renderer = SDL_CreateRenderer( windowManager->getWindow() , -1, configuration->getRendererFlags() );
    textManager = new TextManager();
    textureManager = new TextureManager();
    debugger = new Debugger();
    soundManager = new SoundManager();

    currentScene = new MainMenu();
    running = true;
}

void Game::Update()
{
    while (currentScene->isRunning())
    {
        Game::windowManager->update();
        currentScene->update();
    }

    int flag = currentScene->getFlag();
    delete currentScene;
    switch( flag )
    {
        case 0: // Main Menu
            currentScene = new MainMenu();
            break;
        case 1: // Play on Sigma
            currentScene = new Room( SIGMAIP );
            break;
        case 2: // Play on LAN
            currentScene = new Room( LOCALIP );
            break;
        case 3: // Settings
            currentScene = new Settings();
            break;
        case 4: // Settings - Graphics
            currentScene = new SettingsVideo();
            break;
        case 5: // Settings - Audio
            currentScene = new SettingsAudio();
            break;
        case 6: // Settings - Controller
            currentScene = new SettingsController();
            break;
        case 7: // Settings - Game
            currentScene = new SettingsGame();
            break;
        case 8: // Multiplayer-run
        {
            currentScene = new MpManager();
            break;
        }
            break;
        default:
            if (netManager!=nullptr)
                netManager->disconnectPlayer();
            running = false;
            break;
    }
}

Game::~Game()
{
    SDL_DestroyRenderer( renderer );
    renderer = nullptr;
    IMG_Quit();
    SDL_Quit();
}
