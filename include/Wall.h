#ifndef Wall_h
#define Wall_h

#include "Main.h"

class Wall : public GameObject
{
public:
    Wall(SDL_Renderer* r , int x , int y , int width, int height);
    //void move( float timeStep );
    void draw( int x0 , int y0 );
    //void handleEvent(SDL_Event& e) override {}
    //void update() override {}

private:
    Texture* texture;

};

#endif
