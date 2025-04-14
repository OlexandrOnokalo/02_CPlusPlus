
#include <iostream>
using namespace std;


	/*Завдання 1 :(практична робота на уроці)
Створіть додаток «Телефонна книга».Необхідно збері -
гати дані про абонента(ПІБ, домашній телефон, 
робочий	телефон, 
мобільний телефон, 
додаткова інформація про контакт) всередині відповідного класу(Abonent).

Наповніть клас
	змінними - членами, функціями - членами, конструкторами.
	Створити статичну змінну для
	кількості абонентів.Використати делегування конструкторів.
	Завдання 2:(домашня робота)
	class PhoneBook
{
	Abonent* abonents
		int countAbonent;
	void Add(Abonent a) {}
	void Delete(string phone) {}
	void SearchByName(string name) {}
	void SearchByPhone(string phone{}
		void ShowAll() {}
}
Надайте користувачеві можливість додавати нових абонентів,
видаляти абонентів,
шукати абонентів за ПІБ, показувати всіх абонентів.

*** зберігати інформацію в файл і завантажувати з файлу(записати у файл треба 1 абонента і
	зчитати з файлу треба 1 абонета).*/


class Abonent
{
	string PIB;
	string homePhone;
	string workPhone;
	string additional;
	static int count;
public:
	Abonent()
	{
		PIB = "NoName";
		homePhone = "none";
		workPhone = "none";
		additional = "none";
		count++;
	}
	Abonent(string PIB) :Abonent()
	{
		this->PIB = PIB;
	}
	Abonent(string PIB, string homePhone) :Abonent(PIB)
	{
		this->homePhone = homePhone;
	}
	Abonent(string PIB, string homephone, string workPhone) :Abonent(PIB, homePhone)
	{
		this->workPhone = workPhone;
	}
	Abonent(string PIB, string homephone, string workPhone, string additional) :Abonent(PIB, homePhone, workPhone)
	{
		this->additional = additional;
	}
	void print() {
		cout << "PIB: " << PIB << endl;
		cout << "homePhone: " << homePhone << endl;
		cout << "workPhone: " << workPhone << endl;
		cout << "additional: " << additional << endl;
	}

};

int Abonent::count = 0;

class PhoneBook
{
	Abonent* abonents;
	int size;


public:
	void printBook() {
		for (int i = 0; i < size; i++)
		{
			abonents[i].print();
		}
	}
	void AddAbonent(Abonent abonent)
	{
		size++;
		Abonent* temp = new Abonent[size];
		for (int i = 0; i < size - 1; i++)
		{
			temp[i] = abonents[i];
		}
		temp[size - 1] = abonent;
		if (abonents != nullptr)
			delete[] abonents;
		abonents = temp;
	}



};



int main()
{
	Abonent ab1;
	ab1.print();
}
