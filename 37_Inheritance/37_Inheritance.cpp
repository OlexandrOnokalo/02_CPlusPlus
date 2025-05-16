#include <iostream>
#include <string>
using namespace std;


class Student {
protected:
    string name;
    int age;
    string university;
public:
    Student() : name(""), age(0), university("") {}
    Student(string n, int a, string u) : name(n), age(a), university(u) {}

    void Show() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "University: " << university << endl;
    }
};

class Aspirant : public Student {
private:
    string thesisTitle;
public:
    Aspirant() : Student(), thesisTitle("") {}
    Aspirant(string n, int a, string u, string thesis)
        : Student(n, a, u), thesisTitle(thesis) {
    }

    void Show() {
        Student::Show();
        cout << "Thesis Title: " << thesisTitle << endl;
    }
};



class Passport {
protected:
    string fullName;
    string passportNumber;
    string birthDate;
    string nationality;
public:
    Passport() : fullName(""), passportNumber(""), birthDate(""), nationality("Ukraine") {}
    Passport(string fn, string pn, string bd, string nat = "Ukraine") : fullName(fn), passportNumber(pn), birthDate(bd), nationality(nat) {
    }

    void Show() {
        cout << "Full Name: " << fullName << endl;
        cout << "Passport Number: " << passportNumber << endl;
        cout << "Birth Date: " << birthDate << endl;
        cout << "Nationality: " << nationality << endl;
    }
};

class ForeignPassport : public Passport {
private:
    string foreignNumber;
    string* visas;
    int visaCount;
public:
    ForeignPassport() : Passport(), foreignNumber(""), visaCount(0) {
        visas = new string[10];
    }

    ForeignPassport(string fn, string pn, string bd, string fpn) : Passport(fn, pn, bd), foreignNumber(fpn), visaCount(0) {
        visas = new string[10];
    }

    void AddVisa(string visa) {
        if (visaCount < 10) {
            visas[visaCount++] = visa;
        }
        else {
            cout << "Visa limit reached." << endl;
        }
    }

    void Show() {
        Passport::Show();
        cout << "Foreign Passport Number: " << foreignNumber << endl;
        cout << "Visas:" << endl;
        for (int i = 0; i < visaCount; i++) {
            cout << " - " << visas[i] << endl;
        }
    }

    ~ForeignPassport() {
        delete[] visas;
    }
};
//
//
//int main() {
//    cout << "=== Aspirant ===" << endl;
//    Aspirant a("Ivan Ivanov", 24, "KNU", "Neural Networks in Medicine");
//    a.Show();
//
//    cout << "\n=== Foreign Passport ===" << endl;
//    ForeignPassport fp("Petrenko Olga", "MP123456", "1990-02-01", "FP987654");
//    fp.AddVisa("USA 2023");
//    fp.AddVisa("France 2022");
//    fp.Show();
//
//    return 0;
//}