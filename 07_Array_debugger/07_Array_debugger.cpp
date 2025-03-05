#include<iostream>
using namespace std;

void main() 
{
	/*1.Оголосити одновимірний масив з 10 елементів типу int.
		Заповнити його значеннями з клавіатури, вивести на екран та
		підрахувати добуток елементів масиву*/

	/*const int size = 10;
	int arr[size];
	int product = 1;

	for (int i = 0; i < size; i++)
	{
		cout << "Enter " << i + 1 << " element ";
		cin >> arr[i];
		product *= arr[i];
	}
	
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Product of numbers: " << product << endl;*/

	/*2.Оголосити одновимірний масив з 7 елементів типу int.
		Заповнити його випадковими значеннями в діапазоні[-12.. + 50]
		та вивести на екран.
		Підрахувати кількість відємних та додатніх елементів масиву.*/

	/*const int size = 7;
	int arr[size] = { -9,-5,-7,8,5,2,1 };
	int positive = 0;
	int negative = 0;

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
		if (arr[i]<0)
		{
			negative++ ;
		}
		else
		{
			positive++;
		}
	}
	cout << "\nCount of negative: " << negative << endl;
	cout << "Cont of positive: " << positive << endl;*/

	/*3.Оголосити, проініціалізувати початковими значеннями та вивести
		одновимірний масив з 7 елементів типу long.Визначити суму парних елементів масиву*/

	/*const int size = 7;
	long arr[size] = { -9,-5,-7,8,5,2,1 };
	long sum = 0;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i]<<" ";
		if (arr[i]%2==0)
		{
			sum += arr[i];
		}
	}
	cout << "\nSumm of paired = " << sum << endl;*/

	/*4.Утворити одновимірний масив розміром 30.
		Заповнити його числами, які є степенями 2: (1, 2, 4, 8, 16, ...).
		Вивести елементи масиву на екран у прямому і оберненому порядку.*/

	/*const int size = 30;
	long long arr[size] = { 1 };
	for (int i = 1; i<size; i++)
	{
		arr[i] = arr[i - 1] * 2;
	}
	for (int i = 0; i < size; i++)
	{
		cout<< i<<" " << arr[i] << endl;
	}*/

	/*5.Дано одновимірний масив.Замінити всі від’ємні елементи їх модулями.
		if (arr[i] < 0) arr[i] = arr[i] * -1;*/

	const int size = 7;
	int arr[size] = { -9,-5,-7,8,5,2,1 };

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0) {
			arr[i] = arr[i] * -1;
		}
		cout << arr[i] << " ";
	}

}