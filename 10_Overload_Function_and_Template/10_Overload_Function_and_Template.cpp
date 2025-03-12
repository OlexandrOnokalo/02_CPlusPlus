
#include <iostream>
using namespace std;

//1.Реалізуйте перевантажені функції для
//■ Знаходження максимального значення двох цілих;
//■ Знаходження максимального значення трьох цілих.
//■ Знаходження мінімального значення двох цілих;
//■ Знаходження мінімального значення трьох цілих.

int max(int a, int b)
{
    return a > b ? a : b;
}

int max(int a, int b, int c)
{
    if (a>b && a>c)
    {
        return a;
    }
    else if (b>a && b>c)
    {
        return b;
    }
    else
    {
        return c;
    }
}


int min(int a, int b)
{
    return a < b ? a : b;
}


int min(int a, int b, int c)
{
    if (a < b && a < c)
    {
        return a;
    }
    else if (b < a && b < c)
    {
        return b;
    }
    else
    {
        return c;
    }
}


//1. Написати шаблон функції для пошуку середнього
//арифметичного значення масиву.

template <typename T>
T average(T arr[], int size)
{
    T sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum / size;
}

//2.Написати шаблонні функції і протестувати їх в ос -
//новній програмі :
//
//■ Знаходження максимального значення в однови -
//мірному масиві;
//■ Знаходження максимального значення у двовимір -
//ному масиві;

template <typename T>
T maxarr(T arr[], int size)
{
    T max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}




int main()
{
    int a = 1, b = 5, c = 10;
    
    cout << "Max2: " << max(a, b) << endl;
    cout << "Max3: " << max(a, b, c) << endl;

    cout << "Min2: " << min(a, b) << endl;
    cout << "Min3: " << min(a, b, c) << endl;
    
    const int size = 6;
    double arr[] = { 2.0,3.0,4.0,5.0,6.0,7.0 };
    cout << "Average = " << average(arr,size) << endl;

    cout << "Max array = " << maxarr(arr, size) << endl;

    const int row = 4;
    const int col = 4;
    int matrix[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = rand() % 4;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }  




    

        

}

