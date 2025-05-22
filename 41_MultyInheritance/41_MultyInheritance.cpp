

    /*1.Створити клас Піца з чисто віртуальним методом
Приготувати піцу
У класу піца є два наслідники : міланська піца та грецька піца
в яких має бути реалізовано віртуальний метод
батьківського класу
Створити клас Соус з чисто віртуальним методом
Приготувати соус
Наслідники : міланський соус та грецький соус
Створити клас Фабрика по приготуванню піци з
чисто віртуальними методами :
-Приготувати піцу та
- Приготувати  соус
Для класу Фабрика створити два наслідника :
ФабрикаМілан та ФабрикаГреція з реалізацією віртуальних
методів
class Factory
{
    virtual Pizza* CreatePiza() = 0;
    virtual Souse* CreateSouse() = 0;

}
class MilanFactory
{

    void CreatePiza()
    {
        return new MilanPizza();
    }
    void CreateSouse()
    {
        return new MilanSouse();
    }
}
В мейні реалізувати меню для роботи з програмою
2. За бажанням доповнити клас піца та соус інградієнтами*/

#include <iostream>
#include <string>
using namespace std;


class Pizza {
public:
	virtual void Make_pizza() = 0;
	virtual ~Pizza() {}
};

class Souse {
public:
	virtual void Make_Souse() = 0;
	virtual ~Souse() {}
};

class Factory {
public:
	virtual Pizza* CreatePiza() = 0;
	virtual Souse* CreateSouse() = 0;
	virtual ~Factory() {}
};


class MilanPizza : public Pizza {
public:
	void Make_pizza() override {
		cout << "I am cooking Milan Pizza with:\n";
		cout << "- Thin crust\n";
		cout << "- Mozzarella\n";
		cout << "- Tomato sauce\n";
		cout << "- Basil\n\n";
	}
};

class MilanSouse : public Souse {
public:
	void Make_Souse() override {
		cout << "I am cooking Milan Souse with:\n";
		cout << "- Olive oil\n";
		cout << "- Garlic\n";
		cout << "- Oregano\n\n";
	}
};


class GreecePizza : public Pizza {
public:
	void Make_pizza() override {
		cout << "I am cooking Greece Pizza with:\n";
		cout << "- Thick crust\n";
		cout << "- Feta cheese\n";
		cout << "- Olives\n";
		cout << "- Red onions\n\n";
	}
};

class GreeceSous : public Souse {
public:
	void Make_Souse() override {
		cout << "I am cooking Greece Souse with:\n";
		cout << "- Greek yogurt\n";
		cout << "- Cucumber\n";
		cout << "- Garlic\n";
		cout << "- Dill\n\n";
	}
};


class MilanFactory : public Factory {
public:
	Pizza* CreatePiza() override {
		return new MilanPizza();
	}
	Souse* CreateSouse() override {
		return new MilanSouse();
	}
};

class GreeceFactory : public Factory {
public:
	Pizza* CreatePiza() override {
		return new GreecePizza();
	}
	Souse* CreateSouse() override {
		return new GreeceSous();
	}
};


void ShowMenu() {
	cout << "=== Pizza Factory ===\n";
	cout << "1. Make Milan Pizza and Souse\n";
	cout << "2. Make Greece Pizza and Souse\n";
	cout << "0. Exit\n";
	cout << "Your choice: ";
}

int main() {
	int choice;
	do {
		ShowMenu();
		cin >> choice;
		cout << endl;

		Factory* factory = nullptr;
		Pizza* pizza = nullptr;
		Souse* souse = nullptr;

		switch (choice) {
		case 1:
			factory = new MilanFactory();
			break;
		case 2:
			factory = new GreeceFactory();
			break;
		case 0:
			cout << "Goodbye!\n";
			break;
		default:
			cout << "Invalid choice. Try again.\n\n";
			continue;
		}

		if (factory) {
			pizza = factory->CreatePiza();
			souse = factory->CreateSouse();

			pizza->Make_pizza();
			souse->Make_Souse();

			delete pizza;
			delete souse;
			delete factory;
		}

	} while (choice != 0);

	return 0;
}



