
#include <iostream>
#include <string>
#include <fstream>
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




class Abonent {
    string PIB;
    string homePhone;
    string workPhone;
    string mobilePhone;
    string additional;
    static int count;

public:
    Abonent() {
        PIB = "NoName";
        homePhone = "none";
        workPhone = "none";
        mobilePhone = "none";
        additional = "none";
        count++;
    }


    Abonent(string PIB) : Abonent() {
        this->PIB = PIB;
    }

    Abonent(string PIB, string homePhone) : Abonent(PIB) {
        this->homePhone = homePhone;
    }

    Abonent(string PIB, string homePhone, string workPhone) : Abonent(PIB, homePhone) {
        this->workPhone = workPhone;
    }

    Abonent(string PIB, string homePhone, string workPhone, string mobilePhone) : Abonent(PIB, homePhone, workPhone) {
        this->mobilePhone = mobilePhone;
    }

    Abonent(string PIB, string homePhone, string workPhone, string mobilePhone, string additional)
        : Abonent(PIB, homePhone, workPhone, mobilePhone) {
        this->additional = additional;
    }

    void print() {
        cout << "Full name: " << PIB << endl;
        cout << "Home phone: " << homePhone << endl;
        cout << "Work phone: " << workPhone << endl;
        cout << "Mobile phone: " << mobilePhone << endl;
        cout << "Additional: " << additional << endl;
    }

    string getName()   { return PIB; }
    string getHomePhone()   { return homePhone; }
    string getWorkPhone()   { return workPhone; }
    string getMobilePhone()   { return mobilePhone; }


    void saveToFile(ofstream& file)   {
        file << PIB << endl
            << homePhone << endl
            << workPhone << endl
            << mobilePhone << endl
            << additional << endl;
    }


    void loadFromFile(ifstream& file) {
        getline(file, PIB);
        getline(file, homePhone);
        getline(file, workPhone);
        getline(file, mobilePhone);
        getline(file, additional);
    }
};

int Abonent::count = 0;

class PhoneBook {
    Abonent* abonents = nullptr;
    int size = 0;

public:
    void ShowAll() {
        for (int i = 0; i < size; i++) {
            cout << "Abonent #" << (i + 1) << ":" << endl;
            abonents[i].print();
            cout << "---------------------" << endl;
        }
    }

    void AddAbonent(  Abonent& abonent) {
        size++;
        Abonent* temp = new Abonent[size];
        for (int i = 0; i < size - 1; i++) {
            temp[i] = abonents[i];
        }
        temp[size - 1] = abonent;
        if (abonents != nullptr)
            delete[] abonents;
        abonents = temp;
    }

    void Delete(string phone) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (abonents[i].getHomePhone() == phone ||
                abonents[i].getWorkPhone() == phone ||
                abonents[i].getMobilePhone() == phone) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            Abonent* temp = new Abonent[size - 1];
            for (int i = 0, j = 0; i < size; i++) {
                if (i != index) {
                    temp[j++] = abonents[i];
                }
            }
            delete[] abonents;
            abonents = temp;
            size--;
            cout << "Abonent deleted." << endl;
        }
        else {
            cout << "Abonent not found." << endl;
        }
    }

    void SearchByName(string name) {
        for (int i = 0; i < size; i++) {
            if (abonents[i].getName() == name) {
                abonents[i].print();
                return;
            }
        }
        cout << "Abonent not found." << endl;
    }

    void SearchByPhone(string phone) {
        for (int i = 0; i < size; i++) {
            if (abonents[i].getHomePhone() == phone ||
                abonents[i].getWorkPhone() == phone ||
                abonents[i].getMobilePhone() == phone) {
                abonents[i].print();
                return;
            }
        }
        cout << "Abonent not found." << endl;
    }

    


    void SaveOneAbonent(string filename) {
        ofstream file(filename);
        if (file.is_open() && size > 0) {
            abonents[0].saveToFile(file);
            file.close();
            cout << "First abonent saved to file." << endl;
        }
        else {
            cout << "Cannot save to file." << endl;
        }
    }


    void LoadOneAbonent(string filename) {
        ifstream file(filename);
        if (file.is_open()) {
            Abonent a;
            a.loadFromFile(file);
            AddAbonent(a);
            file.close();
            cout << "Abonent loaded from file." << endl;
        }
        else {
            cout << "Cannot open file." << endl;
        }
    }

    ~PhoneBook() {
        if (abonents != nullptr)
            delete[] abonents;
    }
};





void main() {
    PhoneBook book;

    Abonent ab1("Ivan", "+8(0362)223344", "+8(067)223344", "+8(096)223344", "Kum-brat-svat");
    book.AddAbonent(ab1);

    book.ShowAll();

    book.SaveOneAbonent("abonent.txt");
    book.LoadOneAbonent("abonent.txt");

    book.ShowAll();

    



}

