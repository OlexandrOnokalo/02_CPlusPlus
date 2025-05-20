#include <iostream>
using namespace std;

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
using namespace std;
class Pizza
{
public:
	virtual void Make_pizza() = 0;
};
class MilanPizza :public Pizza
{
public:
	void Make_pizza()override
	{
		cout << "I am cooking Milan Pizza" << endl;
	}
};
class GreecePizza :public Pizza
{
public:
	void Make_pizza()override
	{
		cout << "I am cooking Greece Pizza" << endl;
	}
};
class Souse
{
public:
	virtual void Make_Souse() = 0;
};
class MilanSouse :public Souse
{
public:
	void Make_Souse()override
	{
		cout << "I am cooking Milan Souse" << endl;
	}
};
class GreeceSous :public Souse
{
public:
	void Make_Souse()override
	{
		cout << "I am cooking Greece Souse" << endl;
	}
};
class Factory
{
public:
	virtual Pizza* CreatePiza() = 0;
	virtual Souse* CreateSouse() = 0;
};
class MilanFactory :public Factory
{
public:
	Pizza* CreatePiza()override
	{
		return new MilanPizza();
	}
	Souse* CreateSouse()override
	{
		return new MilanSouse();
	}
};
class GreeceFactory :public Factory
{
public:
	Pizza* CreatePiza()override
	{
		return new GreecePizza();
	}
	Souse* CreateSouse()override
	{
		return new GreeceSous();
	}
};
int main()
{
	Factory* factory = new  MilanFactory();
	Pizza* pizza = factory->CreatePiza();
	pizza->Make_pizza();
	Souse* souse = factory->CreateSouse();
	souse->Make_Souse();
	delete factory;
	delete pizza;
	delete souse;
	factory = new GreeceFactory();
	pizza = factory->CreatePiza();
	pizza->Make_pizza();
	souse = factory->CreateSouse();
	souse->Make_Souse();
	delete factory;
	delete pizza;
	delete souse;
}


