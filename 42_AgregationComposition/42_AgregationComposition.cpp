#include <iostream>
using namespace std;


class Driver {
    string name;
    int age;
    int experience;
public:
    Driver():name("none"),age(0), experience(0){}
    Driver(string n, int a, int e):name(n), age(a), experience(e){}
    void Show()const
    {
        cout << "----Driver----" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Experience: " << experience << endl;
    }

};

class Engine {
    float volume;
public:
    Engine():volume(0){}
    Engine(float v):volume(v){}
    void Show()const 
    {
        cout << "Engine volume: " << volume << endl;
    }
};

class Body {
    string type;
public:
    Body():type("None"){}
    Body(string t):type(t){}
    void Show() {
        cout << "Body type: " << type << endl;
    }
};

class Wheel {
    int diameter;
public:
    Wheel() :diameter(0) {}
    Wheel(int d) :diameter(d) {}
    void Show() {
        cout << "Wheel diameter: " << diameter << endl;
    }
};

class Door {
    string type;
public:
    Door():type("none"){}
    Door(string t):type(t){}
    void Show() {
        cout << "Door type: " << type<<endl;
    }
};

class Headlight {
    string color;
public:
    Headlight():color("none"){}
};


class Car {
    Engine engine;
    Body body;
    Wheel* wheels;
    int countWheels;
    Door* doors;
    int countDoors;
    Headlight* headlines;
    int countHeadlines;
public:
    Car() :wheels(nullptr),countWheels(0), doors(nullptr), countDoors(0), headlines(nullptr), countHeadlines(0) {}
    Car(float volume, string btype, int wdiameter, string dtype, string hcolor)
    {

    }
};













int main()
{
    
}


