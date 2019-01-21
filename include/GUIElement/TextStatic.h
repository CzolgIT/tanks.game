#ifndef TextStatic_h
#define TextStatic_h

#include "_Element.h"
#include "Main.h"

class TextStatic : public _Element
{
public:

    TextStatic( std::string name , float x , float y , float size , float shadow=-1 );
    void draw() override;
    void drawInLine(int line);
    void updateScale() override;
    void loadTexture();

    void setNewName(std::string nname);

private:

    Texture* black;
    Texture* white;
    float shadow;
    float size;

};

#endif
