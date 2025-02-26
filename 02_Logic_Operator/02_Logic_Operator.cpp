#include<iostream>
using namespace std;

void main()
{

     //      class work assignment from the file hw1.txt


///*1.дано сторони трикутника.
//визначити якого вигляду це трикутник(рівносторонній, 
//рівнобедрений, прямокутний).*/


float n1, n2, n3;
cout << "enter first side: " << endl;
cin >> n1;
cout << "enter second side: " << endl;
cin >> n2;
cout << "enter third side: " << endl;
cin >> n3;
if (n1==n2==n3)
{
	cout << "tkikutnuk rivnostoronnij" << endl;
}
else if ((n1==n2)||(n2==n3)||(n1==n3))
{
	cout << "tkikutnuk rivnobedrenij" << endl;
}
else if ((n1*n1==n2*n2+n3*n3)||(n2*n2==n1*n1+n3*n3)||(n3*n3==n1*n1+n2*n2))
{
	cout << "tkikutnuk priamokytnij" << endl;
}
else
{
	cout << "tkikutnuk ne rivnostoronnij, ne rivnobedrenij, ne priamokytnij" << endl;
}
system("pause");


///*2.дано розміри цегли і отвору у стіні.
//	визначити чи цегла пройде у отвір*/

float h1, w1, h2, w2;
cout << "enter heigth of the hole: " << endl;
cin >> h1;
cout << "enter width of the hole: " << endl;
cin >> w1;
cout << "enter heigth of the brick: " << endl;
cin >> h2;
cout << "enter width of the brick: " << endl;
cin >> w2;
if ((h1>h2) && (w1>w2))
{
	cout << "brick fit the hole" << endl;
}
else
{
	cout << "brick will not fit the hole" << endl;
}
system("pause");


///*3.дано 3 числа.визначити 
//	чи є серед них додатні.*/

int a, b, c;
cout << "enter first number: " << endl;
cin >> a;
cout << "enter second number: " << endl;
cin >> b;
cout << "enter third number: " << endl;
cin >> c;
if (a>0)
{
	cout << "first nuumber is dodatne  " << endl;
}
if (b > 0)
{
	cout << "second nuumber is dodatne " << endl;
}
if (c > 0)
{
	cout << "third nuumber is dodatne  " << endl;
}
else
{
	cout << "there is no dodanti numbers" << endl;
}
system("pause");

///*4.дано число.визначити чи лежить воно за межами відрізків[2, 5] та[-1, 1].*/

    int number;
    cout << "enter number" << endl;
    cin >> number;
    if ((2 < number && number < 5) || (-1 < number && number < 1))
    {
        cout << "number in [2,5] or in [-1,1]" << endl;
    }

    else
    {
        cout << "number not in [2,5] or [-1,1]" << endl;

    }

    system("pause");
    
    //5.дано три числа.визначити чи рівні вони між собою.
    
    int q, w, e;
    cout << "enter first number: " << endl;
    cin >> q;
    cout << "enter second number: " << endl;
    cin >> w;
    cout << "enter third number: " << endl;
    cin >> e;
    if (q==w==e)
    {
    	cout << "the numbers are equal." << endl;
    }
    else
    {
    	cout << "the numbers are not equal" << endl;
    }


                        //Class work assignment from the file HW1.txt
                                        //For extra points


    ///*Завдання 1. Користувач вводить з клавіатури відстань
    //	до аеропорту і час, за який потрібно доїхати.Обчислити
    //	швидкість, з якою йому потрібно їхати.*/


    int distance, minutes, speed;
    cout << "Enter distanse to aeroport in km:" << endl;
    cin >> distance;
    cout << "Enter time in minutes:" << endl;
    cin >> minutes;
    if (minutes <= 0) {
    	cout << "Time must be greater than zero." << endl;
    }
    else {
    	speed = distance / (minutes / 60);
    	cout << "You need to go at " << speed << " km/h." << endl;
    }

    //Завдання 2. Користувач вводить з клавіатури час початку
    //і час завершення використання скутера(години, хвилини
    //	та секунди).Порахувати вартість подорожі, якщо вартість
    //	хвилини — 2 гривні.

    int startHours, startMinutes, startSeconds;
    int endHours, endMinutes, endSeconds;

    cout << "Enter start time (hours minutes seconds): " << endl;
    cin >> startHours >> startMinutes >> startSeconds;

    cout << "Enter end time (hours minutes seconds): " << endl;
    cin >> endHours >> endMinutes >> endSeconds;

    int startTotal = startHours * 3600 + startMinutes * 60 + startSeconds;
    int endTotal = endHours * 3600 + endMinutes * 60 + endSeconds;

    int durationInSeconds = endTotal - startTotal;
    if (durationInSeconds < 0) {
    	cout << "End time must be after start time!" << endl;
    }
    else {
    	int durationInMinutes = durationInSeconds / 60;
    	float cost = durationInMinutes * 2;
    	cout << "Total cost is " << cost << " grn" << endl;
    }

    //Завдання 3. Користувач вводить з клавіатури відстань,
    //витрату бензину на 100 км і вартість трьох видів бензину.
    //Вивести на екран порівняльну таблицю з вартістю подо -
    //рожі на різних видах палива.
    
    int dist, vutrata, price1, price2, price3;
    cout << "Enter distance" << endl;
    cin >> dist;
    cout << "Enter vutraty of your car" << endl;
    cin >> vutrata;
    cout << "Enter price of first fuel" << endl;
    cin >> price1;
    cout << "Enter price of second fuel" << endl;
    cin >> price2;
    cout << "Enter price of third fuel" << endl;
    cin >> price3;
    
    float fuelNeeded = (dist / 100.0) * vutrata;
    float cost1 = fuelNeeded * price1;
    float cost2 = fuelNeeded * price2;
    float cost3 = fuelNeeded * price3;
    
    
    cout << "\nComparison table of travel costs:\n";
    cout << "-----------------------------------\n";
    cout << "Fuel Type | Total Cost (UAH)\n";
    cout << "-----------------------------------\n";
    cout << "Fuel 1    | " << cost1 << " UAH\n";
    cout << "Fuel 2    | " << cost2 << " UAH\n";
    cout << "Fuel 3    | " << cost3 << " UAH\n";
    cout << "-----------------------------------\n";



    //      Homework assignment from the file HW2.txt

    //1.Дано сторони прямокутника.Визначити чи прямокутник є квадратом.



        int side1, side2, side3;
        int side4;

        cout << "enter first side: " << endl;
        cin >> side1;
        cout << "enter second side: " << endl;
        cin >> side2;
        cout << "enter third side: " << endl;
        cin >> side3;
        cout << "enter fourth side: " << endl;
        cin >> side4;

        if (side1 == side2 && side2 == side3 && side3 == side4)  
        {  
            cout << "It is square" << endl;  
        }  
        else  
        {  
            cout << "It is not a square" << endl;  
        }  



    //2.Дано вік дитини.Виначити чи дитина по віку може навчатися у школі, чи може відвідувати дитсадок і т.і.

    int age;
    cout << "Enter age:" << endl;
    cin >> age;
    if (age<=0)
    {
        cout << "Age cant be zero or less then zero" << endl;
    }
    else if (age<3)
    {
        cout << "Child must be with mom at home" << endl;
    }
    else if (age<7)
    {
        cout << "Child should go to kindergarden"<<endl;
    }
    else if (age<18)
    {
        cout << "Child should go to school" << endl;
    }
    else
    {
        cout << "It isn*t a child any more )))" << endl;
    }

    //3.Дано 3 числа.Визначити чи рівно два серед них від’ємні.

    int r, t, y; 
    int cnt = 0;
    cout << "enter first number: " << endl;
    cin >> r;
    cout << "enter second number: " << endl;
    cin >> t;
    cout << "enter third number: " << endl;
    cin >> y;
    if (r<0)
    {
        cnt++;
    }
    if (t<0)
    {
        cnt++;
    }
    if (y<0)
    {
        cnt++;
    }
    if (cnt==2)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    //4.Дано число.Визначити чи належить воно відрізку[2, 5] або[-1, 1].

    int number;
    cout << "enter number" << endl;
    cin >> number;
       if (2 < number && number < 5)
    {
    	cout << "number in [2,5]" << endl;
    }
    else if (-1<number && number <1)
    {
    	cout << "number in [-1,1]" << endl;
    
    }
    else
    {
    	cout << "number not in [2,5] or [-1,1]" << endl;
    
    }

//5.Дано три числа.Визначити чи тільки два з них рівні між собою.

    int u, i, o; 

    cout << "enter first number: " << endl;
    cin >> u;
    cout << "enter second number: " << endl;
    cin >> i;
    cout << "enter third number: " << endl;
    cin >> o;
    if ((u == i && u != o) || (u == o && u != i) || (i == o && i != u)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

//6.Дано 3 числа.Визначити чи всі числа непарні.Числа вводяться з клавіатури

int s, d, f;
int couunt=0;
cout << "enter first number: " << endl;
cin >> s;
cout << "enter second number: " << endl;
cin >> d;
cout << "enter third number: " << endl;
cin >> f;
if (s%2!=0)
{
    couunt++;
}
if (d % 2 != 0)
{
    couunt++;
}
if (f % 2 != 0)
{
    couunt++;
}

if (couunt==3)
{
    cout << "Yes" << endl;
}
else
{
    cout << "No" << endl;
}




//          Homework assignment from the file HW2.txt
//                      For extra points




//7.Дано два числа.Якщо вони різні, то поміняти іх місцями.

int a7, b7;
cout << "Enter first number: " << endl;
cin >> a7;
cout << "Enter second number: " << endl;
cin >> b7;
if (a7!=b7)
{
    swap(a7, b7);
}
cout << "new first: " << a7 << "   new second: " << b7 << endl;


//8.Дано натуральне число а(а > 100 && a < 999).
//   Напишіть програму, що визначає кількість цифр 
//    в цьому числі, суму його цифр, 
//    і яка виводить на екран першу 
//    и останню цифру через два пропуски.


int a8;
cout << "Enter number (100 < a < 999): ";
cin >> a8;

if (a8 > 100 && a8 < 999) {
    int first_digit = a8 / 100;
    int last_digit = a8 % 10;
    int middle_digit = (a8 / 10) % 10;
    int sum = first_digit + middle_digit + last_digit;

    cout << "3 digits, sum = " << sum << endl;
    cout << first_digit << "  " << last_digit << endl;
}
else {
    cout << "The number is out of range!" << endl;

}

//9.Дано час(години, хвилини, секунди).Визначити чи час допустимий(наприклад, 25.61.60 – недопустимий).

int hours, minutes, seconds;
cout << "Enter time (hours minutes seconds): ";
cin >> hours >> minutes >> seconds;

if ((hours >= 0 && hours < 24) && (minutes >= 0 && minutes < 60) && (seconds >= 0 && seconds < 60)) {
    cout << "Yes" << endl;
}
else {
    cout << "No" << endl;
}

//10.Написати програму яка в залежності від введеної години виводить : good night, good day, good evening, good morning.

int hours10;
cout << "Enter hour (0-23): ";
cin >> hours10;

if (hours10 >= 0 && hours10 < 6) {
    cout << "Good night" << endl;
}
else if (hours10 >= 6 && hours10 < 12) {
    cout << "Good morning" << endl;
}
else if (hours10 >= 12 && hours10 < 18) {
    cout << "Good day" << endl;
}
else if (hours10 >= 18 && hours10 < 24) {
    cout << "Good evening" << endl;
}
else {
    cout << "Invalid hour" << endl;
}


//11.Написати програму, яка обчислює та виводить мінімум з трьох введених користувачем чисел

int a11, b11, c11;
cout << "Enter three numbers: ";
cin >> a11 >> b11 >> c11;

int min11;
if (a11 <= b11 && a11 <= c11) {
    min11 = a11;
}
else if (b11 <= a11 && b11 <= c11) {
    min11 = b11;
}
else {
    min11 = c11;
}

cout << "Minimum: " << min11 << endl;


}
