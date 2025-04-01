
#include <iostream>
using namespace std;



template <typename T1, typename T2>
void print(const T1 arr[], T2 size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << arr[i];
    }
    cout << endl;
}

    /*Завдання 1.
Визначити функції зображення на екрані  квадрату та  трикутника(можна прямокутного).
void squre(int side);
void trian(int height);
Викликати функції  з  використанням вказівника на функцію.
Cкористатися для  оголошення нового імені для типу вказівника на функцію using FUN = ....;*/

using FUN = void(*)(int);

void square(int side) {
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void trian(int height) {
    for (int i = 1; i <= height; i++) {
        for (int j = 0; j < i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}



    /*Завдання 2. Завершити завдання з класної роботи.
Визначити функцію, яка отримує одновимірний масив та замінює 
всі елементи масиву за певним правилом(подвоює, збільшує на 1  чи інше).
Правило зміни задавати як вказівник на функцію з прототипом 
int func(int) або void func(int&).
Визначити допоміжні функції для зміни одного елемента, 
наприклад void inc(int&) для збільшення числа на 1  та ін.*/

void changeArray(int* arr, int size, int func(int))
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = func(arr[i]);
    }
}
int plusOne(int a) { return a + 1; }
int doubling(int a) { return a * 2; }
int squareValue(int a) { return a * a; }


    /*Завдання 3. Визначити  функцію arraysAction(масив1, масив2, масив3, розмір, 
функціяДія), яка приймає як аргументи покажчики на три масиви однакові за розміром, 
їх розмір та вказівник на функцію.Функція arraysAction() повинна виконати операцію, 
передану через вказіваник на функцію
над відповідними елементами перших двох масивів, 
та занести результат у відповіний елемент треього масиву.
Для перевірки роботи функції arraysAction створити функції для виконання дій над пароб чисел
(наприклад додавання, віднімання, множення, середнє, максимальне з двох).*/

void arraysAction(int arr1[], int arr2[], int arr3[], int size, int func(int, int)) {
    for (int i = 0; i < size; i++) {
        arr3[i] = func(arr1[i], arr2[i]);
    }
}

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int average(int a, int b) { return (a + b) / 2; }
int maxVal(int a, int b) { return (a > b) ? a : b; }




int main()
{
    
    
    const int size = 10;
    cout << "Task 1" << endl;
    FUN ptrFun;

    cout << "Square (side = 5):" << endl;
    ptrFun = square;
    ptrFun(5);

    cout << "Triangle (height = 5):" << endl;
    ptrFun = trian;
    ptrFun(5);
    
       
    cout << "Task 2" << endl;
    
    int arr[size] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    print(arr, size);

    int (*ptr)(int);
    ptr = plusOne;
    changeArray(arr, size, ptr);
    print(arr, size);

    ptr = doubling;
    changeArray(arr, size, ptr);
    print(arr, size);

    ptr = squareValue;
    changeArray(arr, size, ptr);
    print(arr, size);

    cout << "Task 3" << endl;
    int arr1[size] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    int arr2[size] = { 11, 10, 9, 9, 7, 6, 5, 4, 3, 2 };
    int arr3[size] = {};

    cout << "Array 1:" << endl;
    print(arr1, size);

    cout << "Array 1:" << endl;
    print(arr2, size);

    cout << "Addition:" << endl;
    arraysAction(arr1, arr2, arr3, size, add);
    print(arr3, size);

    cout << "Subtraction:" << endl;
    arraysAction(arr1, arr2, arr3, size, subtract);
    print(arr3, size);

    cout << "Multiplication:" << endl;
    arraysAction(arr1, arr2, arr3, size, multiply);
    print(arr3, size);

    cout << "Average:" << endl;
    arraysAction(arr1, arr2, arr3, size, average);
    print(arr3, size);

    cout << "Max value:" << endl;
    arraysAction(arr1, arr2, arr3, size, maxVal);
    print(arr3, size);
    
      
    return 0;








}
