#include "Main.h"

class Vector2D
{
public:
    int x, y;

    Vector2D();
    Vector2D(int x, int y);

    Vector2D& Add(const Vector2D& vec);
	Vector2D& Subtract(const Vector2D& vec);
	Vector2D& Multiply(const Vector2D& vec);
	Vector2D& Divide(const Vector2D& vec);

    Vector2D& operator+=(const Vector2D& vec);
	Vector2D& operator-=(const Vector2D& vec);
	Vector2D& operator*=(const Vector2D& vec);
    Vector2D& operator/=(const Vector2D& vec);
    Vector2D& Perp();
    int Dot(const Vector2D& vec);

};
