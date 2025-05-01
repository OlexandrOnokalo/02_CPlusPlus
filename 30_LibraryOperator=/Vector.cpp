#include "Vector.h"

 Vector::Vector()
{
	points = nullptr;
	countPoint = 0;
}

 Vector::Vector(int a)
{
	points = nullptr;
	countPoint = a;
}

 Vector::Vector(const Vector& other) //Copy constructor - конструктор копіювання (це я для себе залишаю коментар, не звертайте увагу )))))
{
	this->points = new Point[other.countPoint];
	for (int i = 0; i < other.countPoint; i++)
	{
		this->points[i] = other.points[i];
	}
	this->countPoint = other.countPoint;
}

 Vector::Vector(Vector&& other)	//Move constructor - конструктор переносу
{
	this->countPoint = other.countPoint;
	this->points = other.points;
	other.points = nullptr;
}

 Vector& Vector::operator=(const Vector& other) {
	this->countPoint = other.countPoint;
	if (points != nullptr)
		delete[]points;
	this->points = new Point[countPoint];
	for (int i = 0; i < countPoint; i++)
	{
		this->points[i] = other.points[i];
	}
	return *this;
}

 Vector::~Vector()
{
	if (points != nullptr)
	{
		delete[] points;
	}
}

 void Vector::AddPoint(Point point) {
	countPoint++;
	Point* temp = new Point[countPoint];
	for (int i = 0; i < countPoint - 1; i++)
	{
		temp[i] = points[i];
	}
	temp[countPoint - 1] = point;
	if (points != nullptr)
		delete[]points;
	points = temp;
}

 void Vector::Print() const {
	 cout << "Count Points: " << countPoint << endl;
	 for (int i = 0; i < countPoint; i++) {
		 points[i].Show();
		 
		 points[i].ShowAtCoords();
		 cout << endl;
	 }
 }
