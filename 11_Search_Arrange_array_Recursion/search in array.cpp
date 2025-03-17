// search in array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int searchKey(int key, int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
    const int SIZE = 7;
    int arr[SIZE] = { 10, 22, 34, 100, 23, -45, 67 };
	int key;
	
	cout << "Enter a key : ";
	cin >> key;
	int index = searchKey(key, arr, SIZE);
	cout << "Index of key = " << index << endl;

}
// Визначити функцію прямого пошуку як шаблон. ПЕревірити роботу функції на масиві цілих, дробових, char,


