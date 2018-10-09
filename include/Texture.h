#include <string>

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
