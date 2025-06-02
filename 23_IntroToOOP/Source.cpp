#include <iostream>
#include <string>
using namespace std;


class Animal
{
protected:
	string name;	
	int age;
public:
	Animal() : name("none"), age(0) {};
	Animal(string n, int a) :name(n), age(a) {};
	void setName(string n) {
		this->name = n;
	}
	string getName() { return name; };
	void show() {
		cout << "Name: " << name << "\nAge" << age << endl;
	}
};

class Rabit:public Animal 
{
	int speed;
public:
	Rabit() :Animal(), speed(0) {};
	Rabit(string n, int a, int s) :Animal(n, a), speed(0) {};
	void show() {
		Animal::show;
		cout << "Speed: " << speed << endl;
	}

};



