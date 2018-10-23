#ifndef GameObject_h
#define GameObject_h

#include "Main.h"

class GameObject
{
public:
    GameObject();
    
    // virtual void Start()
    // virtual void update();
    
    virtual void draw(){}
    
    int getX();
    int getY();
   
protected:
    SDL_Renderer* renderer;
    int x,y,width,height;
    
};

#endif /* GameObject_h */
