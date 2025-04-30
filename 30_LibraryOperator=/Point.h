#pragma once
class Point
{
	int x;
	int y;
public:
	Point()
	{
		x = y = 0;
	}
    Point operator++(int a)
    {
        this->x++;
        this->y++;
        return *this;
    }
    Point operator--(int)
    {
        this->x--;
        this->y--;
        return *this;
    }
    bool operator >(const Point& other)
    {
        return  (this->x + this->y) > (other.x + other.y);
    }
    bool operator <(const Point& other)
    {
        return  (this->x + this->y) < (other.x + other.y);
    }

};

