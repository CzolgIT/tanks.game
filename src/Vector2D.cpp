#include "Main.h"

Vector2D::Vector2D()
{
    this->x = 0;
    this->y = 0;
}

Vector2D::Vector2D(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vector2D& Vector2D::Add(const Vector2D& vec)
{
	this->x += vec.x;
	this->y += vec.y;

	return *this;
}

Vector2D& Vector2D::Subtract(const Vector2D& vec)
{
	this->x -= vec.x;
	this->y -= vec.y;

	return *this;
}

Vector2D& Vector2D::Multiply(const Vector2D& vec)
{
	this->x *= vec.x;
	this->y *= vec.y;

	return *this;
}

Vector2D& Vector2D::Divide(const Vector2D& vec)
{
	this->x /= vec.x;
	this->y /= vec.y;

	return *this;
}

Vector2D& Vector2D::operator+=(const Vector2D& vec)
{
	return this->Add(vec);
}

Vector2D& Vector2D::operator-=(const Vector2D& vec)
{
	return this->Subtract(vec);
}

Vector2D& Vector2D::operator*=(const Vector2D& vec)
{
	return this->Multiply(vec);
}

Vector2D& Vector2D::operator/=(const Vector2D& vec)
{
	return this->Divide(vec);
}

Vector2D& Vector2D::Perp()
{
    this->x *=-1;
    int pom = this->x;
    this->x = this->y;
    this->y = pom;
    this->Normalize();
    return *this;
}

Vector2D& Vector2D::Normalize(){
	double length = sqrt(x*x+y*y);
    if (length != 0)
	{
    	this->x = (int)( (double)this->x / length );
    	this->y = (int)( (double)this->y / length );
	}
    return *this;
}

float Vector2D::Dot(const Vector2D& vec)
{
    return this->x * vec.x + this->y * vec.y;

}
