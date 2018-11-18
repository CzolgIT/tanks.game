#ifndef BULLET_H
#define BULLET_H


class Bullet: public GameObject
{
public:

    Bullet(SDL_Renderer* r , int x , int y , int dir);
    void draw( int x0 , int y0 );

private:

    int direction;
    Texture* texture;

};


#endif //BULLET_H
