#include <iostream>
using namespace std;

    /*Створити клас «Time», який буде описувати час 3 - ма характеристиками : 
години, хвилини, секунди.

В класі потрібно реалізувати наступні конструктори :
Конструктор по замовчуванню() – встановлюватиме початкові дані
Параметризований(hours, minutes, seconds) – встановлює кожну властивість
Параметризований(seconds) – створює клас перевівши дану кількість секунд 
в години, хвилини, секунди.Наприклад : 5555 = 1год 32хв 35сек
5555 / 3600 - h; 5555 / 60 % 60 – m; 5555 % 60 - s

Також передбачити методи :

Виводу часу на екран в форматі hh : mm:ss
Збільшення часу на одну секунду(11:59 : 59)++ -> 12 : 00 : 00
Клас повинен мати перевантаження наступних бінарних операторів :

+– * / виконується певна арифметична операція 
з часом та повертається результат у 
вигляді нового об'єкту Time

> < >= <=	перевіряється, який об’єкт містить 
більшу / меншу кількість часу та повертається результат у вигляді типу bool
    
== !=		перевіряється чи класи мають не / однаковий час
Використайте explicit для деяких конструкторів*/

class Time {
    int hours;
    int minutes;
    int seconds;

public:
    Time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    explicit Time(int totalSeconds) {
        hours = totalSeconds / 3600;
        minutes = (totalSeconds / 60) % 60;
        seconds = totalSeconds % 60;
    }

    void Print() const {
        cout << (hours < 10 ? "0" : "") << hours << ":"
            << (minutes < 10 ? "0" : "") << minutes << ":"
            << (seconds < 10 ? "0" : "") << seconds << endl;
    }

    int TotalSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    void Tick() {
        int total = TotalSeconds() + 1;
        hours = total / 3600;
        minutes = (total / 60) % 60;
        seconds = total % 60;
    }

    Time operator+(const Time& other) const {
        int total = this->TotalSeconds() + other.TotalSeconds();
        return Time(total);
    }

    Time operator-(const Time& other) const {
        int total = this->TotalSeconds() - other.TotalSeconds();
        if (total < 0) total = 0;
        return Time(total);
    }

    Time operator*(int multiplier) const {
        int total = this->TotalSeconds() * multiplier;
        return Time(total);
    }

    Time operator/(int divisor) const {
        if (divisor == 0) return Time(0);
        int total = this->TotalSeconds() / divisor;
        return Time(total);
    }

    bool operator>(const Time& other) const {
        return this->TotalSeconds() > other.TotalSeconds();
    }

    bool operator<(const Time& other) const {
        return this->TotalSeconds() < other.TotalSeconds();
    }

    bool operator>=(const Time& other) const {
        return this->TotalSeconds() >= other.TotalSeconds();
    }

    bool operator<=(const Time& other) const {
        return this->TotalSeconds() <= other.TotalSeconds();
    }

    bool operator==(const Time& other) const {
        return this->TotalSeconds() == other.TotalSeconds();
    }

    bool operator!=(const Time& other) const {
        return this->TotalSeconds() != other.TotalSeconds();
    }
};

int main() {
    cout << "Testing Time class:\n";

    Time t1;
    cout << "Time t1 (default constructor): ";
    t1.Print();

    Time t2(2, 30, 15);
    cout << "Time t2 (parameterized constructor): ";
    t2.Print();

    Time t3(5555);
    cout << "Time t3 (5555 seconds): ";
    t3.Print();

    cout << "\nAdding t2 + t3: ";
    Time t4 = t2 + t3;
    t4.Print();

    cout << "Subtracting t4 - t2: ";
    Time t5 = t4 - t2;
    t5.Print();

    cout << "Multiplying t2 * 2: ";
    Time t6 = t2 * 2;
    t6.Print();

    cout << "Dividing t6 / 2: ";
    Time t7 = t6 / 2;
    t7.Print();

    cout << "\nTick() t2 + 1 second: ";
    t2.Tick();
    t2.Print();

    cout << "\nComparisons:\n";
    cout << "t2 == t2? " << (t2 == t2) << endl;
    cout << "t2 != t3? " << (t2 != t3) << endl;
    cout << "t2 > t3?  " << (t2 > t3) << endl;
    cout << "t2 < t3?  " << (t2 < t3) << endl;
    cout << "t2 >= t3? " << (t2 >= t3) << endl;
    cout << "t2 <= t3? " << (t2 <= t3) << endl;

    return 0;
}


