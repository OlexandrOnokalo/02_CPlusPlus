
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

template <typename T>
T maxmatrix(T arr[][4], int row, int col)
{
    T max = arr[0][0];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j]>max)
            {
                max = arr[i][j];
            }
        }
    }
    return max;
}



//На додаткові 12 балів:
//Завдання 1. Написати функції, що визначають кількість
//додатних, від'ємних і нульових елементів переданого їй
//масиву.


void numpositive(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]>0)
        {
            count++;
        }
    }
    cout << "Number of positive: " << count << endl;
}

void numnegative(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            count++;
        }
    }
    cout << "Number of negative: " << count << endl;
}

void numzero(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            count++;
        }
    }
    cout << "Number of zero: " << count << endl;
}


    /*Завдання 2. Написати перевантажені функції(int, double,
    char) для виконання таких завдань :
■ Ініціалізація квадратної матриці;
■ Вивід матриці на екран;
■ Визначення максимального й мінімального елемента
на головній діагоналі матриці;
■ Сортування елементів за зростанням окремо для
кожного рядка матриці.*******/


void initmatrix(int matrix[][5], int size) 
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = (rand() % 89)+10;
        }
    }
}


void initmatrix(double matrix[][5], int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = (rand() % 59) +20;
        }
    }
}


void initmatrix(char matrix[][5], int size) 
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = (rand() % 25)+65;
        }
    }
}


template <typename T>
void printmatrix(T matrix[][5], int size) 
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << " " << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


template <typename T>
void findMinMaxDiagonal(T matrix[][5], int size) 
{
    T minEl = matrix[0][0];
    T maxEl = matrix[0][0];
    for (int i = 1; i < size; i++) 
    {
        if (matrix[i][i] < minEl)
        {
            minEl = matrix[i][i];
        }
        if (matrix[i][i] > maxEl)
        {
            maxEl = matrix[i][i];
        }
    }
    cout << "Min/Max: " << minEl << " / " << maxEl << endl;
}


template <typename T>
void sortRows(T matrix[][5], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            for (int k = 0; k < size - j - 1; k++) {
                if (matrix[i][k] > matrix[i][k + 1]) {
                    T temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;
                }
            }
        }
    }
}












int main()
{
    int a = 1, b = 5, c = 10;
    srand(time(0));
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
            matrix[i][j] = rand() % 20;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }  

    cout << "Max matrix = " << maxmatrix(matrix, row, col) << endl;
    cout << endl;

    const int size2 = 15;
    int array2[size2];
    for (int i = 0; i < size2; i++)
    {
        array2[i] = (-10 + rand() % 20);
        cout << " " << array2[i] << " ";
    }

    cout << endl;

    numpositive(array2, size2);
    numnegative(array2, size2);
    numzero(array2, size2);

    
    cout << "\n\n\n\n\n\n\n";

    const int SIZE = 5;

    int intMatrix[SIZE][SIZE];
    double doubleMatrix[SIZE][SIZE];
    char charMatrix[SIZE][SIZE];

    
    initmatrix(intMatrix, SIZE);
    initmatrix(doubleMatrix, SIZE);
    initmatrix(charMatrix, SIZE);

    cout << "Int Matrix: "<<endl;
    printmatrix(intMatrix, SIZE);
    cout << endl;
    cout << "Double Matrix: " << endl;;
    printmatrix(doubleMatrix, SIZE);
    cout << endl;
    cout << "Char Matrix: "<<endl;
    printmatrix(charMatrix, SIZE);
    cout << endl;

   
    cout << endl;
    findMinMaxDiagonal(intMatrix, SIZE);
    findMinMaxDiagonal(doubleMatrix, SIZE);
    findMinMaxDiagonal(charMatrix, SIZE);

    cout << endl;
    
       
    sortRows(intMatrix, SIZE);
    sortRows(doubleMatrix, SIZE);
    sortRows(charMatrix, SIZE);

    cout << endl;
    cout << endl;

    cout << "Resault sorted: "<<endl;
    cout << "Integer Matrix:"<<endl;
    printmatrix(intMatrix, SIZE);
    cout << "Double Matrix:"<<endl;
    printmatrix(doubleMatrix, SIZE);
    cout << "Char Matrix: "<<endl;
    printmatrix(charMatrix, SIZE);
    

        

}

