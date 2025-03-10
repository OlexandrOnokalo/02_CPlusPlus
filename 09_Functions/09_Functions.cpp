
#include <iostream>
using namespace std;

/*Завдання 1. Написати функцію, що виводить на екран
прямокутник з висотою N і шириною K.*/

void printSquare(int N, int K) 
{   
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            cout << " * ";
        }
        cout << endl;
    }
    cout << endl;
}


/*Завдання 2. Написати функцію, яка обчислює факторіал
    переданого їй числа.*/

int factorial(int number) 
{

    int fact =1;
    for (int i = 1; i <= number; i++)
    {
        fact *= i;
    }
    return fact;
}

/*Завдання 3. Написати функцію, яка перевіряє, чи є пере -
        дане їй число простим.Число називається простим, якщо
        воно ділиться без залишку тільки на себе та на одиницю.*/

bool proste(int a) {
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
        
    }
    return true;
}

//Завдання 4. Написати функцію, яка повертає куб числа.

int cube(int a) 
{
    int res = a * a * a;
    return res;
}

//Завдання 5. Написати функцію для знаходження найбільшого з двох чисел.

int great(int a, int b)
{
    return a > b ? a : b;
}

//Завдання 6. Написати функцію, яка повертає істину, якщо передане значення додатне, та брехню, якщо від’ємне.

bool positive(int a)
{
    if (a>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


                                /*Додаткові завдання*/

//Завдання 1. Написати функцію, що визначає мінімум і максимум(значення й номер) елементів переданого їй масиву.


int resaultarray[4];

void MaxMin(int arr[], int size)
{
    resaultarray[0] = arr[0];
    resaultarray[1] = 0;
    resaultarray[2] = arr[0];
    resaultarray[3] = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i]>resaultarray[0])
        {
            resaultarray[0] = arr[i];
            resaultarray[1] = i;
        }
        if (arr[i]<resaultarray[2])
        {
            resaultarray[2] = arr[i];
            resaultarray[3] = i;

        }
        
    }
}

//Завдання 2. Написати функцію, яка міняє порядок елементів переданого їй масиву на протилежний.

void opposite(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        swap(arr[i], arr[size - 1 - i]); 
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//Завдання 3. Написати функцію, яка повертає кількість простих чисел у переданому їй масиві.

int prostiAgain(int arr[],int size)
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if (proste(arr[i])==true)
        {
            counter++;
        }

    }
    return counter;
    
}









void main()
{
    
    printSquare(5, 6);

    int resault2 = factorial(5);
    cout << resault2 << endl;
  

    bool resault3 = proste(4);
    cout << "proste?  "<< resault3 << endl;

    int resault4 = cube(3);
    cout << resault4 << endl;

    int resault5 = great(5,20);
    cout << resault5 << endl;

    int resault6 = positive(-20);
    cout << resault6 << endl;

    const int size = 8;
    int arr[size] = { 10,5,7,6,11,9,55,4 };
    MaxMin(arr, size);
    cout << "Max = " << resaultarray[0] << ", by index = " << resaultarray[1] << endl;
    cout << "Min = " << resaultarray[2] << ", by index = " << resaultarray[3] << endl;

    opposite(arr, size);

    int resault9 = prostiAgain(arr,size);
    cout << resault9 << endl;



}


