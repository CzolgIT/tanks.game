#ifndef Element_h
#define Element_h

#include "Main.h"

class _Element
{
public:

    _Element( std::string name , float x , float y ); // x=(0-64) y=(0-36)
    virtual void updateScale(){};
    virtual void draw(){};
    virtual int getFlag(){ return 0; };

    virtual void setActive( bool a ){};
    virtual void setComment( std::string comment ){};

protected:

    std::string name;
    float x,y,xScale,yScale;

};


#endif
