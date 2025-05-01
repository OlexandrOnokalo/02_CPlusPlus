#pragma once
#include <iostream>
#include <windows.h> 
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point();
    Point(int x, int y);
    Point operator++(int);
    Point operator--(int);
    bool operator >(const Point& other);
    bool operator <(const Point& other);
    void Show() const;
    void ShowAtCoords() const;
};

