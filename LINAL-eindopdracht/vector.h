#pragma once

struct Vector {
	float x, y;
	Vector(float x, float y);
	Vector operator*(float scalar);
	Vector operator+(const Vector& v);
	Vector operator-(const Vector& v);
	~Vector();
};