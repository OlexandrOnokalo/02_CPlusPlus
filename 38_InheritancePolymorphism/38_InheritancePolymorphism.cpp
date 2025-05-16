
#include <iostream>
using namespace std;


    /*Завдання 1:
Створіть клас Shape який містить загальні параметри
будь - якої фігури(ім, я, тип і тд).Визначте віртуальні методи :
•Show – вивід на екран інформації про фігуру; •Show = 0
•GetArea – обчислення площі фігури; (•GetArea = 0)
Визначте похідні класи : прямокутник, коло, прямокутний трикутник, трикутник,
трапеція зі своїми функціями площі.– кожний з яких буде
містити притаманні даній фігурі характеристики та перевизначати(override)
алгоритми методів базового класу Shape.
Також створити функцію TestShape, яка приймає фігуру та відображає її
інформацію включаючи площу.
В main протестувати роботу, передавши в функцію різні фігури.*/

#include <iostream>
using namespace std;
class Shape
{
    string name;
    string type;
public:
    Shape() :name("no name"), type("no type") {};
    Shape(string n, string t) :name(n), type(t) {};
    virtual void Show()
    {
        cout << "Name figure = " << name << endl;
        cout << "Name type = " << type << endl;
    }
    virtual void GetArea()
    {
        cout << "Area of figura " << endl;
    }
};
class Rectungle :public Shape
{
    int a, b;
    void Show()override
    {
        Shape::Show();
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
    void GetArea()override
    {
        cout << "Square = " << a * b << endl;
    }
};










int main()
{
    
}

