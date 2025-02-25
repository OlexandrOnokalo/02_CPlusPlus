#include<iostream>
using namespace std;


void main() {


	cout << "I" << endl;
	cout << "\tlove" << endl;
	cout << "\t\tyou" << endl;
	cout << "\t\t\tC++!" << endl;

system("pause");



cout << "\n\t...:: : RESUME:: : ...\n\nName:\t\t\tOlexandr\nSurname: \t\tOnokalo \nLast name: \t        Vitaliyovich\n\nDate of birth: \t\t24.08.1988 \nCity: \t\t\tRivne \nAge: \t\t\t36 \n\nHobby: \t\t\tC++\n::...........................::\n\n" << endl;

system("pause");



int inch = 42;
float cm = inch * 2.54;
cout << "Diagonal of TV: " << cm << " cm" << endl;

system("pause");



int k = 20;
float kg = k * 30 / 1000;
cout << "Amount of food for 30 days: " << kg << " kg" << endl;

system("pause");



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