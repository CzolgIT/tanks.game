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
        Mix_VolumeMusic(120);
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
        Mix_Volume(1, 50);
        Mix_Quit();
    }
}

void SoundManager::PlayMenuMusic()
{
    if (Game::configuration->getSounds())
    {
        if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) < 0)
            std::cout << "Error: " << Mix_GetError() << std::endl;
        Mix_AllocateChannels(8);
        Mix_Chunk *menu = Mix_LoadWAV("assets/sounds/menu_sound.wav");
        if(!Mix_Playing(2))
            Mix_PlayChannel(2, menu, 0);
        Mix_Volume(2, 50);
        Mix_Quit();
    }
}
