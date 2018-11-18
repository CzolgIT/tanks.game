#include "Main.h"

Collider::Collider(int centerX, int centerY, int width, int height, float angle){

        angle = angle/180 * M_PI;
        Vector2D p1;
        p1.x = centerX + (width/2  * cos(angle)) - (height/2  * sin(angle));
        p1.y = centerY + (width/2 * sin(angle)) + (height/2 * cos(angle));
        points.push_back(p1);
        Vector2D p2;
        p2.x = centerX + (-width/2  * cos(angle)) - (height/2  * sin(angle));
        p2.y = centerY + (-width/2 * sin(angle)) + (height/2 * cos(angle));
        points.push_back(p2);
        Vector2D p3;
        p3.x = centerX + (-width/2  * cos(angle)) - (-height/2  * sin(angle));
        p3.y = centerY + (-width/2 * sin(angle)) + (-height/2 * cos(angle));
        points.push_back(p3);
        Vector2D p4;
        p4.x = centerX + (width/2  * cos(angle)) - (-height/2  * sin(angle));
        p4.y = centerY + (width/2 * sin(angle)) + (-height/2 * cos(angle));
        points.push_back(p4);

}


bool Collider::areColliding(Collider col1, Collider  col2)
{
    Vector2D * axes1 = col1.getAxes();
    Vector2D * axes2 = col2.getAxes();
    for (int i = 0; i < col1.points.size(); i++)
    {
        Projection * p1 = col2.project(axes1[i]);
        Projection * p2 = col1.project(axes1[i]);

        if (p1->overlap(p2))
          return false;
    }

    for (int i = 0; i < col2.points.size(); i++)
    {
        Projection * p1 = col2.project(axes2[i]);
        Projection * p2 = col1.project(axes2[i]);

        if (p1->overlap(p2))
            return false;
    }

    return true;
}

Projection * Collider::project (Vector2D axis)
{
    int min = axis.Dot(this->points[0]);
    int max = min;

    for (int i = 1; i < points.size(); i++) {
      int p = axis.Dot(points[i]);
      if (p < min) {
        min = p;
      } else if (p > max) {
        max = p;
      }
    }

    Projection * proj = new Projection(min, max);

    return proj;
}

Vector2D * Collider::getAxes(){

    Vector2D * axes = NULL;
    axes = new Vector2D[points.size()];
    for (int i = 0; i < points.size(); i++)
    {
        Vector2D p1 = points[i];
        Vector2D p2 = points[i + 1 == points.size() ? 0 : i + 1];
        Vector2D edge = p1.Subtract(p2);
        Vector2D normal = edge.Perp();
        axes[i] = normal;
    }
    return axes;
}
