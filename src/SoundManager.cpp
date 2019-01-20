#include "Main.h"

SoundManager::SoundManager() = default;

void SoundManager::PlayBackgroundMusic()
{
    if (Game::configuration->getSounds())
    {
        if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) < 0)
            std::cout << "Error: " << Mix_GetError() << std::endl;
        Mix_Music *bgm = Mix_LoadMUS("assets/sounds/background_music.mp3");
        if(!Mix_PlayingMusic())
            Mix_PlayMusic(bgm,-1);
        Mix_HaltChannel(2);
        Mix_VolumeMusic(20);
        bgm = nullptr;
        Mix_Quit();
    }
}

void SoundManager::PlayShootSound()
{
    if (Game::configuration->getSounds())
    {
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
            std::cout << "Error: " << Mix_GetError() << std::endl;
        Mix_Chunk *bullet = Mix_LoadWAV("assets/sounds/tank_shot_sound.wav");
        int random = rand() % 15;
        if(random < 5)
        {
            Mix_Chunk *laduj = Mix_LoadWAV("assets/sounds/laduj.wav");
            Mix_PlayChannel(5, laduj, 0);
        }else if(random < 10)
            {
            Mix_Chunk *pakuj = Mix_LoadWAV("assets/sounds/pakuj.wav");
            Mix_PlayChannel(5, pakuj, 0);
        }else
        {
            Mix_Chunk *dawaj = Mix_LoadWAV("assets/sounds/dawaj.wav");
            Mix_PlayChannel(5, dawaj, 0);
        }
        Mix_PlayChannel(1, bullet, 0);
        Mix_Volume(1, 50);
        Mix_Volume(5, 50);
    }
}

void SoundManager::PlayEngineSound()
{
    if (Game::configuration->getSounds())
    {
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
            std::cout << "Error: " << Mix_GetError() << std::endl;
        Mix_AllocateChannels(8);
        Mix_Chunk *engine = Mix_LoadWAV("assets/sounds/engine_sound.wav");
        if(!Mix_Playing(3))
            Mix_PlayChannel(3, engine, -1);
        Mix_Volume(3, 50);
        //Mix_Quit();
    }
}

void SoundManager::PlayTurretSound()
{
    if (Game::configuration->getSounds())
    {
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
            std::cout << "Error: " << Mix_GetError() << std::endl;
        Mix_AllocateChannels(8);
        Mix_Chunk *turret = Mix_LoadWAV("assets/sounds/turret_sound.wav");
        if(!Mix_Playing(4))
            Mix_PlayChannel(4, turret, -1);
        Mix_Volume(4, 50);
    }
}

void SoundManager::PlayMenuMusic()
{
    if (Game::configuration->getSounds())
    {
        if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) < 0)
            std::cout << "Error: " << Mix_GetError() << std::endl;
        Mix_Chunk *menu = Mix_LoadWAV("assets/sounds/menu_sound.wav");
        if(!Mix_Playing(2))
            Mix_PlayChannel(2, menu, 0);
        Mix_Volume(2, 50);
        Mix_Quit();
    }
}
