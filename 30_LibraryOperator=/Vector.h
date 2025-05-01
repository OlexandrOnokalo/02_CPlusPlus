#pragma once
#include"Point.h"

class Vector
{
	Point* points;
	int countPoint;
public:
	Vector();
	explicit Vector(int a);
	Vector(const Vector& other);
	Vector(Vector&& other);
	Vector& operator=(const Vector& other);
	~Vector();
	void AddPoint(Point point);
	void Print() const;
};

