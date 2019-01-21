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
        case 5:
            Game::setNickname("");
            currentScene = new MainMenu();
            break;
        case 7: // Settings - Game
            currentScene = new SettingsGame();
            break;
        case 8: // Multiplayer run
            currentScene = new MpManager();
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

bool Game::isNicknameSet() {

    std::ifstream infile("config.txt");
    std::string name ("NAME");

    std::string line;
    while (std::getline(infile, line))
    {
        if( name.compare(line.substr(0,4)) == 0)
        {
            if (line.length() <=5)
            {
                infile.close();
                return false;
            }
        }
    }
    infile.close();
    return true;
}

void Game::setNickname(std::string name) {

    std::string pom ("NAME");
    std::ifstream infile("config.txt");
    std::ofstream config("config1.txt");
    std::string line;

    while (std::getline(infile, line))
    {
        if( pom.compare(line.substr(0,4)) == 0)
        {
           config << "NAME " << name;
        }
        else
            config << line << "\n";
    }
    config.close();
    infile.close();

    std::rename("config1.txt","config.txt");
}

