#include <iostream>
#include <string>
#include <windows.h> 
using namespace std;


class Animal {
protected:
    string type;
    double speed;
    double weight;
    string habitat;

public:
    Animal() : type(""), speed(0), weight(0), habitat("") {}
    Animal(string t, double s, double w, string h) : type(t), speed(s), weight(w), habitat(h) {}

    void Move() {
        cout << type << " moves at speed " << speed << " km/h." << endl;
    }

    void Show() {
        cout << "Type: " << type << endl;
        cout << "Speed: " << speed << " km/h" << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Habitat: " << habitat << endl;
    }

    void Say() {
        cout << type << " makes a sound..." << endl;
        Beep(750, 300); 
    }
};


class Bird : public Animal {
protected:
    double wingspan;
public:
    Bird() : Animal(), wingspan(0) {}
    Bird(string t, double s, double w, string h, double ws)
        : Animal(t, s, w, h), wingspan(ws) {
    }

    void Show() {
        Animal::Show();
        cout << "Wingspan: " << wingspan << " m" << endl;
    }
};


class Eagle : public Bird {
public:
    Eagle() : Bird("Eagle", 160, 6.5, "Mountains", 2.2) {}
};


class Reptile : public Animal {
protected:
    bool venomous;
public:
    Reptile() : Animal(), venomous(false) {}
    Reptile(string t, double s, double w, string h, bool v)
        : Animal(t, s, w, h), venomous(v) {
    }

    void Show() {
        Animal::Show();
        cout << "Venomous: " << (venomous ? "Yes" : "No") << endl;
    }
};


class Cobra : public Reptile {
public:
    Cobra() : Reptile("Cobra", 20, 5, "Jungle", true) {}
};


class Fish : public Animal {
protected:
    bool freshwater;
public:
    Fish() : Animal(), freshwater(true) {}
    Fish(string t, double s, double w, string h, bool f)
        : Animal(t, s, w, h), freshwater(f) {
    }

    void Show() {
        Animal::Show();
        cout << "Freshwater: " << (freshwater ? "Yes" : "No") << endl;
    }
};


class Salmon : public Fish {
public:
    Salmon() : Fish("Salmon", 25, 4.2, "Rivers", true) {}
};


int main() {
    Eagle eagle;
    Cobra cobra;
    Salmon salmon;

    cout << "=== EAGLE ===" << endl;
    eagle.Show();
    eagle.Move();
    eagle.Say();
    cout << endl;

    cout << "=== COBRA ===" << endl;
    cobra.Show();
    cobra.Move();
    cobra.Say();
    cout << endl;

    cout << "=== SALMON ===" << endl;
    salmon.Show();
    salmon.Move();
    salmon.Say();
    cout << endl;

    return 0;
}
