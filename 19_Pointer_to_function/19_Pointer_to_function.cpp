
#include <iostream>
using namespace std;

// 1. Визначити функції обчислення суми, різниці, добутку, частки двох дробових 
//чисел. Викликати функції через вказівник функції.

double addition(double a, double b) {
    return a + b;
}
double subtraction(double a, double b) {
    return a - b;
}double product(double a, double b) {
    return a * b;
}double division(double a, double b) {
    return a / b;
}



/*Визначити функцію, яка отримує одновимірний
масив та замінює всі елементи масиву за певним правилом
(подвоює, збільшує на 1  чи інше). Правило зміни задавати як
вказівник на функцію з прототипом int func(int) або void func(int&).
Визначити допоміжні функції для зміни одного елемента,
наприклад void inc(int&) для збільшення числа на 1  та ін.*/

void changeArray(int* arr, int size, int func(int)) 
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = func(arr[i]);
    }
}

int plusOne(int a) {
    return a + 1;
}

int doubling(int a) {
    return a * 2;
}

int square(int a) {
    return a * a;
}

void print(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << arr[i];
    }
    cout << endl;
}


/*4. Визначити  функцію arraysAction(масив1, масив2, масив3,
функціяДія), яка приймає як аргументи покажчики
на три масиви однакові за розміром, їх розмір
та вказівник на функцію.Функція arraysAction()
повинна виконати операцію, передану через
вказіваник на функцію над відповідними
елементами перших двох масивів, та занести результат у
відповіний елемент треього масиву.
Створити функції для виконання дій (наприклад додавання, 
віднімання, множення, середнє, максимальне з двох).*/

void arraysAction(int arr1[], int arr2[], int arr3[], int size, int func(int, int)) {
    for (int i = 0; i < size; i++)
    {
        arr3[i] = func(arr1[i], arr2[i]);
    }
    print(arr3, size);
}





int main()
{
    //double a, b;
    //double(*ptr)(double,double);
    //cout << "Enter a, b :" << endl;
    //cin >> a >> b;
    //ptr = addition;
    //cout << a << " + " << b << " = " << ptr(a, b) << endl;

    //ptr = subtraction;
    //cout << a << " - " << b << " = " << ptr(a, b) << endl;

    //ptr = product;
    //cout << a << " * " << b << " = " << ptr(a, b) << endl;

    //ptr = division;
    //cout << a << " / " << b << " = " << ptr(a, b) << endl;


    //    /*2. Організувати меню за допомогою масиву 
    //вказівників на функції  обчислення суми, 
    //        різниці, добутку, частки двох дробових чисел.*/

    //const int SIZE = 4;
    //double (*arrFun[SIZE]) (double, double) = { addition, subtraction, product,division };
    //int choice;
    //while (true)
    //{
    //    cout << "\n\n1) + \n2) - \n3) * \n4) /  \n0)Exit " << endl;
    //    cin >> choice;
    //    if (choice >= 1 and choice <= SIZE)
    //    {
    //        cout << "Result = " << arrFun[choice - 1](a,b) << endl;
    //    }
    //    else if (choice == 0)
    //    {
    //        cout << "Bye-bye!\n";
    //        break;
    //    }
    //}

        /*Визначити функцію, яка отримує одновимірний 
  масив та замінює всі елементи масиву за певним правилом
  (подвоює, збільшує на 1  чи інше). Правило зміни задавати як 
  вказівник на функцію з прототипом int func(int) або void func(int&).
  Визначити допоміжні функції для зміни одного елемента, 
  наприклад void inc(int&) для збільшення числа на 1  та ін.*/

    const int size = 10;
    int arr[size] = { 10,20,30,40,50,60,70,80,90,100 };
    print(arr,size);
    int(*ptr)(int);
    ptr = plusOne;
    changeArray(arr, size, ptr);
    print(arr, size);

    ptr = doubling;
    changeArray(arr, size, ptr);
    print(arr, size);

    ptr = square;
    changeArray(arr, size, ptr);
    print(arr, size);

        /*4. Визначити  функцію arraysAction(масив1, масив2, масив3, 
    функціяДія), яка приймає як аргументи покажчики 
    на три масиви однакові за розміром, їх розмір 
    та вказівник на функцію.Функція arraysAction() 
    повинна виконати операцію, передану через 
    вказіваник на функцію над відповідними 
    елементами перших двох масивів, та занести результат у 
    відповіний елемент треього масиву.*/

    int arr1[size] = {2,3,4,5,6,7,8,9,10,11};
    int arr2[size] = { 11,10,9,9,7,6,5,4,3,2 };
    int arr3[size] = {};
    print(arr1, size);
    print(arr2, size);








}
