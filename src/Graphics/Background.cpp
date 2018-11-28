#include "Main.h"

Background::Background()
{
    width=512;
    height=512;
    clip.x = 0;
    clip.y = 0;
    clip.w = width;
    clip.h = height;
}

void Background::draw( int x , int y )
{
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            Game::textureManager->background->draw(x + (i * width),y + (j * height), 1, &clip, 0, nullptr );
}
