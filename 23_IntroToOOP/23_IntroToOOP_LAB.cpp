

#include <iostream>
#include <string>
using namespace std;


    /*Завдання №2
Реалізуйте клас «Точка».Необхідно зберігати координати
x, y, z в змінних - членах класу.Реалізуйте функції - члени
класу для введення даних, виведення даних, реалізуйте
аксесор для доступу до змінних - членів, реалізуйте збе -
реження в файл і завантаження даних з файлу.*/

class point
{
    double x, y, z;
public:
    void enter() {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
        cout << "Enter x: ";
        cin >> z;
    }
    void print() {
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
        cout << "z: " << z << endl;
    }
    void setX(double x)
    {
        this->x = x;
    }
    void setY(double Y)
    {
        this->y = y;
    }void setZ(double xz)
    {
        this->z = z;
    }
    double getX() {
        return x;
    }
    double getY() {
        return y;
    }
    double getZ() {
        return z;
    }
    void saveToFile() {

    }

};




int main()
{

    
}

