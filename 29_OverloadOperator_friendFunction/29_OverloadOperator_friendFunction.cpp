#include <iostream>
#include <string>
using namespace std;


    /*ТЕМА: OPERATORS OVERLOADING
Завдання 1 :
    Створити клас Airplane(літак), який буде мати наступні характеристики :
• Модель
• Тип
• Кількість пасажирів
• Максимальна кількість пасажирів
За допомогою перевантаження операторів реалізувати :
1. Перевірку на рівність типів літаків(операція == ) friend
2. Збільшення і зменшення пасажирів в салоні літака(операції ++ та --
    в префіксній формі)
    3. Порівняння двох літаків по максимально можливій кількості пасажирів
    на борту(операція > ) friend
    4. Збільшити кількість пасажирів на певне значення(оператор(15))
    Перевантаження логічних операцій виконати за допомогою дружніх функцій.
    При виконанні операцій, потрібно перевіряти чи не перебільшено максимальну
    кількість пасажирів.
    !Результат завантажити у вигляді.cpp файла.*/


class Airplane
{
    string model;
    string type;
    int passengers;
    int maxPassengers;
public:
    Airplane()
    {
        model = "";
        type = "";
        passengers = 0;
        maxPassengers = 0;
    }
    Airplane(string model, string type, int passengers, int maxPassengers)
    {
        this->model = model;
        this->type = type;
        this->passengers = passengers;
        this->maxPassengers = maxPassengers;
        if (this->passengers > this->maxPassengers)
            this->passengers = this->maxPassengers;
    }
    friend bool operator==(const Airplane& a1, const Airplane& a2);
    friend bool operator>(const Airplane& a1, const Airplane& a2);

    Airplane& operator++()
    {
        if (passengers < maxPassengers)
            passengers++;
        return *this;
    }

    Airplane& operator--()
    {
        if (passengers > 0)
            passengers--;
        return *this;
    }


    void operator()(int value)
    {
        passengers += value;
        if (passengers > maxPassengers)
            passengers = maxPassengers;
        if (passengers < 0)
            passengers = 0;
    }

    void Print() const
    {
        cout << "Model: " << model << endl;
        cout << "Type: " << type << endl;
        cout << "Passengers: " << passengers << "/" << maxPassengers << endl;
    }
};



bool operator==(const Airplane& a1, const Airplane& a2)
{
    return a1.type == a2.type;
}

bool operator>(const Airplane& a1, const Airplane& a2)
{
    return a1.maxPassengers > a2.maxPassengers;
}







void main()
{
    Airplane plane1("Boeing 737", "Passenger", 120, 160);
    Airplane plane2("Airbus A320", "Passenger", 130, 150);
    Airplane plane3("Cessna 172", "Private", 3, 4);

    cout << "Plane 1:" << endl;
    plane1.Print();
    cout << endl;

    cout << "Plane 2:" << endl;
    plane2.Print();
    cout << endl;

    cout << "Plane 3:" << endl;
    plane3.Print();
    cout << endl;

    cout << "Check if Plane1 and Plane2 have same type: ";
    cout << (plane1 == plane2 ? "Yes" : "No") << endl;

    cout << "Check if Plane1 has more max passengers than Plane3: ";
    cout << (plane1 > plane3 ? "Yes" : "No") << endl;

    cout << endl << "Increasing passengers in Plane1:" << endl;
    ++plane1;
    plane1.Print();

    cout << endl << "Decreasing passengers in Plane2 :" << endl;
    --plane2;
    plane2.Print();

    cout << endl << "Adding 10 passengers to Plane1 :" << endl;
    plane1(10);
    plane1.Print();

  



}