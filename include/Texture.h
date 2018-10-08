#ifndef Texture_h
#define Texture_h

// w tej klasie będą ładowane pliki do SDL_Texture poprzez SDL_Surface

class Texture
{
public:
    Texture();
    ~Texture();
    bool load( SDL_Renderer* renderer , std::string path );
    void free();
    void render( SDL_Renderer* renderer , int x, int y, SDL_Rect* clip = NULL );
    int width;
    int height;
private:
    SDL_Texture* texture; // faktyczna tekstura z biblioteki
};

#endif
