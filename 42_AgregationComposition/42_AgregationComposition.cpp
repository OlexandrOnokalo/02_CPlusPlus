#include <iostream>
using namespace std;

class Driver {
    string name;
    string surname;
    int age;
    int experience;
public:
    Driver() : name("none"), surname("none"), age(0), experience(0) {}
    Driver(string n, string s, int a, int e) : name(n), surname(s), age(a), experience(e) {}
    void Show() const {
        cout << "---- Driver Info ----" << endl;
        cout << "Name: " << name << " " << surname << endl;
        cout << "Age: " << age << " years\n";
        cout << "Driving experience: " << experience << " years\n";
    }
};

class Engine {
    float volume;
public:
    Engine() : volume(0) {}
    Engine(float v) : volume(v) {}
    void Show() const {
        cout << "Engine volume: " << volume << "L\n";
    }
};

class Body {
    string type;
public:
    Body() : type("None") {}
    Body(string t) : type(t) {}
    void Show() const {
        cout << "Body type: " << type << endl;
    }
};

class Wheel {
    int diameter;
public:
    Wheel() : diameter(0) {}
    Wheel(int d) : diameter(d) {}
    void Show() const {
        cout << "Wheel diameter: " << diameter << " inches\n";
    }
};

class Door {
    string type;
public:
    Door() : type("none") {}
    Door(string t) : type(t) {}
    void Show() const {
        cout << "Door type: " << type << endl;
    }
};

class Headlight {
    string color;
public:
    Headlight() : color("none") {}
    Headlight(string c) : color(c) {}
    void Show() const {
        cout << "Headlight color: " << color << endl;
    }
};

class Car {
    Engine engine;
    Body body;
    Wheel* wheels;
    int countWheels;
    Door* doors;
    int countDoors;
    Headlight* headlights;
    int countHeadlights;
    Driver* driver; 
public:
    Car(Engine e, Body b, Wheel* w, int cw, Door* d, int cd, Headlight* h, int ch)
        : engine(e), body(b), countWheels(cw), countDoors(cd), countHeadlights(ch), driver(nullptr) {
        wheels = new Wheel[countWheels];
        for (int i = 0; i < countWheels; i++)
            wheels[i] = w[i];

        doors = new Door[countDoors];
        for (int i = 0; i < countDoors; i++)
            doors[i] = d[i];

        headlights = new Headlight[countHeadlights];
        for (int i = 0; i < countHeadlights; i++)
            headlights[i] = h[i];
    }

    
    Car(Engine e, Body b, Wheel* w, int cw, Door* d, int cd, Headlight* h, int ch, Driver* dr)
        : Car(e, b, w, cw, d, cd, h, ch) {
        driver = dr;
    }

    
    void AddDriver(Driver* dr) {
        driver = dr;
    }

    void Show() const {
        cout << "===== Car Info =====\n";
        engine.Show();
        body.Show();

        cout << "-- Wheels --\n";
        for (int i = 0; i < countWheels; i++)
            wheels[i].Show();

        cout << "-- Doors --\n";
        for (int i = 0; i < countDoors; i++)
            doors[i].Show();

        cout << "-- Headlights --\n";
        for (int i = 0; i < countHeadlights; i++)
            headlights[i].Show();

        if (driver)
            driver->Show();
        else
            cout << "-- No driver assigned to this car --\n";
    }

    ~Car() {
        delete[] wheels;
        delete[] doors;
        delete[] headlights;
        
    }
};


int main() {

    Driver d("Ivan", "Petrenko", 35, 10);


    Engine e(2.0f);
    Body b("Sedan");

    Wheel wheels[4] = { Wheel(16), Wheel(16), Wheel(16), Wheel(16) };
    Door doors[4] = { Door("Front Left"), Door("Front Right"), Door("Back Left"), Door("Back Right") };
    Headlight headlights[2] = { Headlight("White"), Headlight("White") };


    Car car1(e, b, wheels, 4, doors, 4, headlights, 2);
    car1.Show();

    cout << "\nAdding driver to car...\n";
    car1.AddDriver(&d);
    car1.Show();

    cout << "\nCreating another car with driver in constructor...\n";
    Car car2(e, b, wheels, 4, doors, 4, headlights, 2, &d);
    car2.Show();

    return 0;
}
