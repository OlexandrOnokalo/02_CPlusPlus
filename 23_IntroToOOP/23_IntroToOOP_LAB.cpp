#include <iostream>
#include <fstream>
#include <string>
using namespace std;

    /*Завдання №2 Реалізуйте клас «Точка».Необхідно зберігати 
координати x, y, z в змінних - членах класу.Реалізуйте функції - 
члени класу для введення даних, виведення даних, реалізуйте аксесор 
для доступу до змінних - членів, реалізуйте збереження в файл і завантаження даних з файлу.*/

class Point {
private:
    
    double x, y, z;

public:
    
    void input() {
        cout << "Enter coordinates of the point (x, y, z): ";
        cin >> x >> y >> z;
    }

    
    void output()  {
        cout << "Point coordinates: (" << x << ", " << y << ", " << z << ")" << endl;
    }

    
    double getX()  { return x; }
    double getY()  { return y; }
    double getZ()  { return z; }

    void SetX(double x) {
        this->x = x;
    }
    void SetY(double y) {
        this->y = y;
    }
    void SetX(double z) {
        this->z = z;
    }


    
    void saveToFile(const string& filename)  {
        ofstream outFile(filename);
        outFile << x << " " << y << " " << z << endl;
        outFile.close();
        cout << "Point data saved to file." << endl;
        

    }

     void loadFromFile(const string& filename) {
        ifstream inFile(filename);
        inFile >> x >> y >> z;
        inFile.close();
        cout << "Point data loaded from file." << endl;

        
    }
};

    /*Завдання №1 Реалізуйте клас «Студент».Необхідно зберігати 
в змінних - членах класу : 
ПІБ, дату народження, контактний телефон, 
місто, країну, назву навчального закладу, 
місто та країну(де знаходиться навчальний заклад), 
номер групи.Реалізуйте функції - 
члени класу для введення даних, виведення даних, 
реалізуйте аксесор для доступу до окремих змінних - членів.*/

class Student {
private:
    string name;
    string dateOfBirth;
    string phoneNumber;
    string city;
    string country;
    string institutionName;
    string institutionCity;
    string institutionCountry;
    int groupNumber;

public:
    void input() {
        cout << "Enter student's name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter student's date of birth (DD/MM/YYYY): ";
        getline(cin, dateOfBirth);
        cout << "Enter student's phone number: ";
        getline(cin, phoneNumber);
        cout << "Enter student's city: ";
        getline(cin, city);
        cout << "Enter student's country: ";
        getline(cin, country);
        cout << "Enter student's educational institution name: ";
        getline(cin, institutionName);
        cout << "Enter institution city: ";
        getline(cin, institutionCity);
        cout << "Enter institution country: ";
        getline(cin, institutionCountry);
        cout << "Enter student's group number: ";
        cin >> groupNumber;
    }

    void output()  {
        cout << "Student's Name: " << name << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "City: " << city << endl;
        cout << "Country: " << country << endl;
        cout << "Educational Institution: " << institutionName << endl;
        cout << "Institution City: " << institutionCity << endl;
        cout << "Institution Country: " << institutionCountry << endl;
        cout << "Group Number: " << groupNumber << endl;
    }


    string getName()  { return name; }


    string getDateOfBirth()  { return dateOfBirth; }


    string getPhoneNumber()  { return phoneNumber; }


    string getCity()  { return city; }


    string getCountry()  { return country; }


    string getInstitutionName()  { return institutionName; }


    string getInstitutionCity()  { return institutionCity; }


    string getInstitutionCountry()  { return institutionCountry; }


    int getGroupNumber()  { return groupNumber; }


    void setName(string name) {
        this->name = name;
    }

    void setDateOfBirth(string dateOfBirth) {
        this->dateOfBirth = dateOfBirth;
    }

    void setPhoneNumber(string phoneNumber) {
        this->phoneNumber = phoneNumber;
    }

    void setCity(string city) {
        this->city = city;
    }

    void setCountry(string country) {
        this->country = country;
    }

    void setInstitutionName(string institutionName) {
        this->institutionName = institutionName;
    }
    
    void setInstitutionCity(string institutionCity) {
        this->institutionName = institutionCity;
    }
    
    void setinstitutionCountry(string institutionCountry) {
        this->institutionCountry = institutionCountry;
    }

    void setПroupNumber(int groupNumber) {
        this->groupNumber = groupNumber;
    }
    



};


int main() {

    Point p1;
    p1.input();  
    p1.output(); 
    p1.saveToFile("point.txt");
    p1.loadFromFile("point.txt"); 


    Student s1;
    s1.input();  
    s1.output(); 

    return 0;
}