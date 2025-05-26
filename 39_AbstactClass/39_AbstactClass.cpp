

    /*Створити абстрактний клас Shape (фігура). Яка містить тип та чисто віртуальний метод Print(), для показу фігури на консоль.

Реалізувати похідні класи:
•	Line – містить координати початку та кінця (дві точки)
•	Rectangle – містить координати верхнього лівого кута, ширину та довжину
•	Polyline – містить масив точок

Всі похідні класи повинні перевизначати метод Print(), друкуючи фігуру на консолі враховуючи її параметри. Додати деструктор  в класи, які його потребують.
Для зручності можна створити структуру struct Point { int x, y };  та скористатися методом gotoxy().

*Додати метод Save() для запису фігури в файл.
*/
 
#include <iostream>
#include <fstream>
#include <windows.h> 
using namespace std;


struct Point {
    int x, y;
};


void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


class Shape {
protected:
    string type;
public:
    Shape(string t = "Unknown") : type(t) {}
    virtual void Print() const = 0;
    virtual void Save(ofstream& fout) const = 0;
    virtual ~Shape() {}
};


class Line : public Shape {
    Point start, end;
public:
    Line(Point s, Point e) : Shape("Line"), start(s), end(e) {}

    void Print() const override {
        cout << "Drawing Line from (" << start.x << "," << start.y << ") to ("
            << end.x << "," << end.y << ")" << endl;

        
        if (start.y == end.y) { 
            for (int x = min(start.x, end.x); x <= max(start.x, end.x); ++x) {
                gotoxy(x, start.y);
                cout << "-";
            }
        }
        else if (start.x == end.x) { 
            for (int y = min(start.y, end.y); y <= max(start.y, end.y); ++y) {
                gotoxy(start.x, y);
                cout << "|";
            }
        }
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
    }

    void Save(ofstream& fout) const override {
        fout << type << " " << start.x << " " << start.y << " "
            << end.x << " " << end.y << endl;
    }

    ~Line() {}
};


class MyRectangle : public Shape {
    Point topLeft;
    int width, height;
public:
    MyRectangle(Point p, int w, int h)
        : Shape("Rectangle"), topLeft(p), width(w), height(h) {
    }

    void Print() const override {
        cout << "Drawing Rectangle at (" << topLeft.x << "," << topLeft.y
            << ") width = " << width << ", height = " << height << endl;

        for (int x = topLeft.x; x <= topLeft.x + width; ++x) {
            gotoxy(x, topLeft.y);
            cout << "-";
            gotoxy(x, topLeft.y + height);
            cout << "-";
        }
        for (int y = topLeft.y; y <= topLeft.y + height; ++y) {
            gotoxy(topLeft.x, y);
            cout << "|";
            gotoxy(topLeft.x + width, y);
            cout << "|";
        }
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
    }

    void Save(ofstream& fout) const override {
        fout << type << " " << topLeft.x << " " << topLeft.y
            << " " << width << " " << height << endl;
    }

    ~MyRectangle() {}
};


class MyPolyline : public Shape {
    Point* points;
    int size;
public:
    MyPolyline(Point* pts, int sz) : Shape("Polyline"), size(sz) {
        points = new Point[size];
        for (int i = 0; i < size; ++i)
            points[i] = pts[i];
    }

    void Print() const override {
        cout << "Drawing Polyline with " << size << " points." << endl;
         for (int i = 0; i < size; ++i) {
            gotoxy(points[i].x, points[i].y);
            cout << "*";
        }
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
    }

    void Save(ofstream& fout) const override {
        fout << type << " " << size;
        for (int i = 0; i < size; ++i)
            fout << " " << points[i].x << " " << points[i].y;
        fout << endl;
    }

    ~MyPolyline() {
        delete[] points;
    }
};
//
//
//int main() {
//    
//    Point p1 = { 10, 5 };
//    Point p2 = { 30, 5 };
//    Line l(p1, p2);
//
//    Point topLeft = { 5, 10 };
//    MyRectangle r(topLeft, 15, 6);
//
//    Point pts[4] = { {10,22}, {12,24}, {14,23}, {16,25} };
//    MyPolyline pl(pts, 4);
//
//    
//    l.Print();
//    r.Print();
//    pl.Print();
//
//    
//    ofstream fout("shapes.txt");
//    if (fout.is_open()) {
//        l.Save(fout);
//        r.Save(fout);
//        pl.Save(fout);
//        fout.close();
//        cout << "\nShapes saved to shapes.txt" << endl;
//    }
//    else {
//        cout << "Failed to open file for writing." << endl;
//    }
//
//    return 0;
//}

