#include "vector.h"

Vector::Vector(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector Vector::operator*(float scalar)
{
	return Vector(x * scalar, y * scalar);
}

Vector Vector::operator+(const Vector& v)
{
	return Vector(x + v.x, y + v.y);
}

Vector Vector::operator-(const Vector& v)
{
	return Vector(x - v.x, y - v.y);
}

Vector::~Vector()
{
}
