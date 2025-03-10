
#include <iostream>
using namespace std;

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

int factorial(int number) 
{

    int fact =1;
    for (int i = 1; i <= number; i++)
    {
        fact *= i;
    }
    return fact;
}

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


void main()
{
    
    /*Завдання 1. Написати функцію, що виводить на екран
    прямокутник з висотою N і шириною K.*/

    printSquare(5, 6);

    /*Завдання 2. Написати функцію, яка обчислює факторіал
        переданого їй числа.*/

    int resault1 = factorial(5);
    cout << resault1 << endl;

    /*Завдання 3. Написати функцію, яка перевіряє, чи є пере -
        дане їй число простим.Число називається простим, якщо
        воно ділиться без залишку тільки на себе та на одиницю.*/

    bool resault2 = proste(5);
    cout << resault2 << endl;





}


