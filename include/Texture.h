#include <string>
#include <SDL2/SDL.h>
#ifdef __APPLE__
#include <SDL2_image/SDL_image.h>
#include <SDL2_net/SDL_net.h>
#else
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_net.h>
#endif

#ifndef Texture_h
#define Texture_h

class Texture
{
public:
    Texture();
    ~Texture();
    bool load( SDL_Renderer* renderer , std::string path );
    void free();
    int getWidth();
    int getHeight();
private:
    int width;
    int height;
    SDL_Texture* texture; // sdl handler to actual texture
};

#endif
