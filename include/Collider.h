#ifndef Collider_h
#define Collider_h

#include "Main.h"

class Collider {

public:
    Collider(float centerX, float centerY, int width, int height, float angle = 0);
    Collider(Vector2D * points)
    {
    }

    static Vector2D areColliding(Collider col1, Collider  col2);

    Projection * project (Vector2D axis);

    Vector2D * center;

    static Vector2D * getAxes(Collider col);

    std::vector<Vector2D> points;

};
#endif /* Collider_h */
