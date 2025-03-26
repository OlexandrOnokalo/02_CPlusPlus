#include <iostream>
using namespace std;

		/*3. Створити функції для роботи з динамічним масивом
		- створення  динамічного масиву заданого розміру, розмір приходить як параметр функції
		- заповнення масиву випадковими числами + виконано
		- виведення масиву + виконано
		- доповнення масиву новим елементом(на початок)
		- доповнення масиву новим елементом(у хвіст масиву) + виконано*/

int* createArr(int size) 
{
	int* arr = new int [size] {};
	return arr;
}

void fillArrayWithRand(int * & arr, int size)
{
	static bool firstTime = true;
	if (firstTime) {
		firstTime = false;
		srand(unsigned(time(0)));
	}
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}

void printArray(const int* arr, int size)
{
	cout << "Array: ";
	for (int i = 0; i < size; i++)
	{
		cout << "\t" << arr[i];
	}
}


void addToFront(int element, int * & arr, int& size)
{
	++size;
	int* tmp = new int[size]; 

	for (int i = 0; i < size-1; i++)
	{
		tmp[i+1] = arr[i];
	}
	
	tmp[0] = element;
		
	delete[] arr;
		
	arr = tmp;
}


void addToEnd(int element, int*& arr, int& size)
{
	++size; 
	int* tmp = new int[size]; 

	
	for (int i = 0; i < size - 1; i++)
	{
		tmp[i] = arr[i];
	}
	
	tmp[size - 1] = element;

	
	delete[] arr;

	
	arr = tmp;
}






