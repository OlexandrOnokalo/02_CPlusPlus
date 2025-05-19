#include <iostream>
using namespace std;

    /*Створити абстрактний клас Shape(фігура).Яка містить тип та чисто віртуальний метод Print(), для показу фігури на консоль.

Реалізувати похідні класи :
Line – містить координати початку та кінця(дві точки)
Rectangle – містить координати верхнього лівого кута, ширину та довжину
Polyline – містить масив точок

Всі похідні класи повинні перевизначати метод Print(), друкуючи фігуру на консолі враховуючи її параметри.Додати деструктор  в класи, які його потребують.
Для зручності можна створити структуру struct Point { int x, y };  та скористатися методом gotoxy().*/

struct Point { int x, y; };

class Shape { 
public: 
    virtual void Print()const = 0; 
};

class Line : public Shape
{
    Point p1;
    Point p2;
public:
    Line(Point start, Point end) : p1(start), p2(end) {}
    void Print() const override {
        
    }

};

class Rectangle :public Shape
{
    Point p1;
    int height;
    int width;
public:
    Rectangle(Point p, int h, int w) : p1(p), height(h), width(w) {};
    void Print() const override {

    }
};

class Polyline : public Shape
{
    int size;
    Point* points;
public:
    Polyline(int s, const Point* pts) : size(s), points(new Point[s]) {
        for (int i = 0; i < size; ++i)
            points[i] = pts[i];
    }
    ~Polyline() {
        delete[] points;
    }
    void Print() const override {
        cout << "Polyline with " << size << " points:\n";
        for (int i = 0; i < size; ++i)
            cout << "(" << points[i].x << ", " << points[i].y << ") ";
        cout << endl;
    }
};




















int main()
{
    

