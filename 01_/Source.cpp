#include<iostream>
using namespace std;


void main() {
    //1.
    //    I
    //    love
    //    you
    //    C++!

	cout << "I" << endl;
	cout << "\tlove" << endl;
	cout << "\t\tyou" << endl;
	cout << "\t\t\tC++!" << endl;

system("pause");

//Вивести резюме виду(підставити свої дані) :
//
//	…:: : RESUME:: : …
//
//	Name : Ivan
//	Surname : Ivanov
//	Last name : Ivanovich
//
//	Date of birth : 22.06.06
//	City : Rivne
//	Age : 17
//
//	Hobby : C++
//	::……………………...................……::

cout << "\n\t...:: : RESUME:: : ...\n\nName:\t\t\tOlexandr\nSurname: \t\tOnokalo \nLast name: \t        Vitaliyovich\n\nDate of birth: \t\t24.08.1988 \nCity: \t\t\tRivne \nAge: \t\t\t36 \n\nHobby: \t\t\tC++\n::...........................::\n\n" << endl;

system("pause");

//3. Дана діагональ телевізора в дюймах.Написати програму,
//що визначає цю ж діагональ у сантиметрах(1 дюйм =
//    2.54 сантиметрів).
//    Нижче представлений приклад для перевірки програ -
//    ми на коректність.
//
//    Вхідними даними є :
//Діагональ телевізора(inch) — > 42

int inch = 42;
float cm = inch * 2.54;
cout << "Diagonal of TV: " << cm << " cm" << endl;

system("pause");

//4. За один день хом'ячок з'їдає K грам корму.Написати
//програму, що визначає закупівлю корму в кілограмах
//на 30 днів.
//
//Нижче представлений приклад для перевірки програ -
//ми на коректність.
//
//Вхідними даними є :
//Витрата корму за 1 день(г) -> 20
//–––––––––––––––––––––––
//Вихідні дані :
//Обсяг корму на 30 днів : 0.6 кг.

int k = 20;
float kg = k * 30 / 1000;
cout << "Amount of food for 30 days: " << kg << " kg" << endl;

system("pause");

//1.Введіть три числа і виведіть на екран їх значення та значення суми цих чисел.
//2.Напишіть програму, яка обраховує середнє арифметичне двох чисел.
//3.Напишіть програму, яка переводить кілометри в метри.Кілометри вводяться з клавіатури.
//4.Ви купили в магазині 4 різні товари.Дані ціни кожного товару(константні значення) та кількість товару, який був придбаний.
//Обрахувати та вивести вартість покупки.
//5.Напишіть програму, яка обраховує квадрат довільного введеного числа
//6.Написати програму, яка переводить дні в хвилини.Дні вводяться з клавіатури.Використати хоч би одну константу!!!

int a = 5, b = 10, c = 15;
int sum = a + b + c;
cout << "a = " << a << ", b = " << b << ", c = " << c << ", sum = " << sum << endl;

int d = 10, e = 20;
float avg = (d + e) / 2;
cout << "Average of " << d << " and " << e << " is " << avg << endl;    

int km;
cout << "Enter km: ";
cin >> km;
int m = km * 1000;
cout << km << " km is " << m << " m" << endl;

const int price1 = 10, price2 = 20, price3 = 30, price4 = 40;   
int count1 = 1, count2 = 2, count3 = 3, count4 = 4; 
int total = price1 * count1 + price2 * count2 + price3 * count3 + price4 * count4;
cout << "Total price: " << total << endl;

int num;    
cout << "Enter number: ";
cin >> num;
int square = num * num;
cout << "Square of " << num << " is " << square << endl;

const int day = 24 * 60;    
int days;
cout << "Enter days: ";
cin >> days;
int minutes = days * day;
cout << days << " days is " << minutes << " minutes" << endl;

system("pause");


}