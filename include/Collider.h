#ifndef Collider_h
#define Collider_h

#include "Main.h"

class Collider {

public:
    Collider(int centerX, int centerY, int width, int height, float angle = 0);
    Collider(Vector2D * points)
    {
    }

    static bool areColliding(Collider col1, Collider  col2);

    Projection * project (Vector2D axis);

    Vector2D * getAxes();

    std::vector<Vector2D> points;

};
#endif /* Collider_h */
