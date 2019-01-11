#include "Main.h"

SoundManager::SoundManager() = default;

void SoundManager::PlayBackgroundMusic()
{
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) < 0)
        std::cout << "Error: " << Mix_GetError() << std::endl;
    Mix_Music *bgm = Mix_LoadMUS("assets/jedyna_sluszna_muzyka.mp3");
    if(!Mix_PlayingMusic())
        Mix_PlayMusic(bgm,-1);
    Mix_VolumeMusic(120);
    bgm = nullptr;
    Mix_Quit();
}

void SoundManager::PlayShootSound()
{
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048)<0)
        std::cout << "Error: " << Mix_GetError() << std::endl;
    Mix_Chunk *bullet2 = Mix_LoadWAV("assets/Tank_Shot.wav");
    Mix_PlayChannel(1, bullet2, 0);
    Mix_Volume(1,50);
    Mix_Quit();
}
