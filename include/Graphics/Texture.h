#ifndef Texture_h
#define Texture_h

#include "Main.h"

class Texture
{
public:

    Texture();
    Texture( std::string path );
    ~Texture();

    bool loadFromFile( std::string path );
    bool loadFromRenderedText( TTF_Font *gFont , std::string textureText, SDL_Color textColor );

    void setColor( Uint8 r , Uint8 g , Uint8 b );
    void setBlendMode( SDL_BlendMode blending );
    void setAlpha( Uint8 alpha );
    void setAlignCenter( bool alignCenter );

    void draw(float x, float y, float scale = 1, SDL_Rect *clip = nullptr, double angle = 0, SDL_Point *center = nullptr);

    int getWidth();
    int getHeight();

private:

    SDL_Texture* mTexture;

    void* mPixels;
    int mPitch;
    int mWidth;
    int mHeight;
    bool alignCenter;

};

#endif
