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

class Time
{
    int hours;
    int minutes;
    int seconds;
    int total;
public:
    Time()
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
        total = 0;
    }
    Time(int hours, int minutes,int seconds)
    {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
        total = 0;
    }
    Time(int seconds)
    {
        this->hours = seconds / 3600;
        this->minutes = seconds / 60 % 60;
        this->seconds = seconds % 60;
        total = 0;
    }
    Time operator +(Time& other) const
    {
        Time res((*this).totalSeconds() + other.totalSeconds());
        return res;
    }
    int totalSeconds() {
        return hours * 3600 + minutes * 60 + seconds;
    }
    void ToHMS() {
        this->hours = total / 3600;
        this->minutes = total / 60 % 60;
        this->seconds = total % 60;
    }



}









void main()
{
    
}


