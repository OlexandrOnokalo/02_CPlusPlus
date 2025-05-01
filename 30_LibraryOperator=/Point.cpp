#include "Point.h"

Point::Point() {
    x = y = 0;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point Point::operator++(int) {
    this->x++;
    this->y++;
    return *this;
}

Point Point::operator--(int) {
    this->x--;
    this->y--;
    return *this;
}

bool Point::operator>(const Point& other) {
    return (this->x * this->x + this->y * this->y) > (other.x * other.x + other.y * other.y);
}

bool Point::operator<(const Point& other) {
    return (this->x * this->x + this->y * this->y) < (other.x * other.x + other.y * other.y);
}

void Point::Show() const {
    cout << "X: " << x << " Y: " << y << endl;
}

void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Point::ShowAtCoords() const {
    gotoxy(x, y);
    cout << "*";
}
