// binary search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
int main();
void print(const int arr[], int size);
void fillRandomUp(int arr[], int size, int left = 0, int right = 100);
void  selectSort(int arr[], int size);
void  bubbleSort(int arr[], int size);


int main()
{
    const int SIZE = 10;
    int arr[SIZE];
    fillRandomUp(arr, SIZE);
    print(arr, SIZE);
   // selectSort(arr, SIZE);
    bubbleSort(arr, SIZE);
    print(arr, SIZE);

    
}

void print(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << arr[i];
    }
    cout << endl;
}

void fillRandomUp(int arr[], int size, int left, int right)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        arr[i] =  rand() % (right - left + 1);
    }
}

void selectSort(int arr[], int size)
{
    for (int step = 0; step < size - 1; step++) // ????  
    {
        int min = arr[step];
        int indexMin = step;
        for (int i = step + 1; i < size; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
                indexMin = i;
            }
        }
        cout << "Min " << min << "\tindex = " << indexMin << endl;
        std::swap(arr[indexMin], arr[step]);
        print(arr, size);
    }
}

void bubbleSort(int arr[], int size)
{
    bool flag = true;
    for (int step = 0; step < size - 1; step++)
    {
        flag = false;
        for (int j = 0; j < size - 1 - step; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                print(arr, size);
                flag = true;
            }
        }
        if (flag == false)
            break;
        cout << "______end of iteration #"  << step + 1 << "___________________________\n";
    }
}


