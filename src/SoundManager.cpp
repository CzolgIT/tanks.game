#include "Main.h"

SoundManager::SoundManager() = default;

void SoundManager::PlayBackgroundMusic()
{
    if (Game::configuration->getSounds())
    {
        if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) < 0)
            std::cout << "Error: " << Mix_GetError() << std::endl;
        Mix_Music *bgm = Mix_LoadMUS("assets/sounds/Desert-Mayhem.mp3");
        if(!Mix_PlayingMusic())
            Mix_PlayMusic(bgm,-1);
        Mix_HaltChannel(2);
        Mix_VolumeMusic(30);
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
        Mix_PlayChannel(1, bullet, 0);
        Mix_Volume(1, 15);
    }
}

void SoundManager::PlayClickSound()
{
    if (Game::configuration->getSounds())
    {
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
            std::cout << "Error: " << Mix_GetError() << std::endl;
        Mix_AllocateChannels(8);
        Mix_Chunk *click = Mix_LoadWAV("assets/sounds/click.wav");
        Mix_PlayChannel(6, click, 0);
    }
}

void SoundManager::PlayPowerUpSound()
{
    if (Game::configuration->getSounds())
    {
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
            std::cout << "Error: " << Mix_GetError() << std::endl;
        Mix_AllocateChannels(8);
        Mix_Chunk *power = Mix_LoadWAV("assets/sounds/power-up.wav");
        Mix_PlayChannel(7, power, 0);
        Mix_Volume(7, 20);
    }
}

void SoundManager::PlayExplosionSound()
{
    if (Game::configuration->getSounds())
    {
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
            std::cout << "Error: " << Mix_GetError() << std::endl;
        Mix_AllocateChannels(9);
        Mix_Chunk *explode = Mix_LoadWAV("assets/sounds/Explosion.wav");
        Mix_PlayChannel(8, explode, 0);
        Mix_Volume(8, 40);
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
        Mix_Volume(3, 40);
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
        Mix_Chunk *menu = Mix_LoadWAV("assets/sounds/Urban-Assault.mp3");
        if(!Mix_Playing(2))
            Mix_PlayChannel(2, menu, -1);
        Mix_Volume(2, 50);
        Mix_Quit();
    }
}
