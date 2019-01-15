#include "Main.h"

Background::Background()
{
    width=512;
    height=512;
    clip.x = 0;
    clip.y = 0;
    clip.w = width;
    clip.h = height;

    clip2 = { 0 , 0 , 160 , 160 };
}

void Background::draw( int x , int y )
{
    double scale = Game::configuration->getScale();


    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            Game::textureManager->background->draw(x + (i * width),y + (j * height), 1, &clip, 0, nullptr );

    for (int i=0; i<10 ; i++)
    {
        Game::textureManager->city->draw(x + (i * 64 * scale), y, 0.4 * scale, &clip2, 0, nullptr);
        Game::textureManager->city->draw(x + (i * 64 * scale), y + (64 * scale), 0.4 * scale, new SDL_Rect{8 * 160, 0, 160, 160}, 0, nullptr);
        Game::textureManager->city->draw(x + (i * 64 * scale), y + (128 * scale), 0.4 * scale, new SDL_Rect{9 * 160, 0, 160, 160}, 0, nullptr);
        Game::textureManager->city->draw(x + (i * 64 * scale), y + (192 * scale), 0.4 * scale, new SDL_Rect{8 * 160, 0, 160, 160}, 0, nullptr);
        Game::textureManager->city->draw(x + (i * 64 * scale), y + (256 * scale), 0.4 * scale, new SDL_Rect{2 * 160, 0, 160, 160}, 0, nullptr);
    }
}
