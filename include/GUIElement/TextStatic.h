#ifndef TextStatic_h
#define TextStatic_h

#include "Main.h"

class TextStatic : public _Element
{
public:

    TextStatic( std::string name , float x , float y , float size , float shadow=-1 );
    void draw();
    void updateScale();
    void loadTexture();

private:

    Texture* black;
    Texture* white;
    float shadow;
    float size;

};

#endif
