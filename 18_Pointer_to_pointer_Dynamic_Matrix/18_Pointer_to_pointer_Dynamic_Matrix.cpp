#include <iostream>
using namespace std;



void printMatrix(int** m, int r, int c)
{
	if (m == nullptr)
	{
		cout << "Empty matrix!\n";
		return;
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << m[i][j] << "\t";
		}
		cout << endl;
	}
}

void removeMatrix(int**& m, int r)
{
	for (int i = 0; i < r; i++)
	{
		delete[] m[i]; // вилучаємо кожен рядок у циклі
	}
	delete[] m;  // вилучаємо масив вказівників

	m = nullptr;
}

void addRow(int**& m, int& r, int c, int value)
{
	++r; // збільшили кількість рядків + 1
	int** tmp = new int* [r]; // створили маси вказівників на рядки більшого розміру +1

	for (int i = 0; i < r - 1; i++)
	{
		tmp[i] = m[i]; // перечипили старі рядки у новий масив вказівників 
	}

	tmp[r - 1] = new int[c]; // створили новий рядок як останній у новій матриці
	for (int j = 0; j < c; j++)
	{
		tmp[r - 1][j] = value; //заповнили новий рядок однаковими значеннями value
	}

	delete[] m;
	m = tmp;
}


	/*2. Написати функцію створення динамічної матриці за двома розмірами.*/

int** createMatrix(int rows, int cols) {
	int** matrix = new int* [rows] ;
	for (int i = 0; i < rows; i++)
	{
		int* row = new int[cols] {};
		matrix[i] = row;

	}
	
	return matrix;
}















    /*3. Написати функцію, яка отримує вказівник на дин.матрицю, \
    розміри матриці, деяке значення(value) та додає новий рядок, 
    заповнений value як перший.*/


void addRowToFront(int**& m, int& r, int c, int value)
{
	++r; 
	int** tmp = new int* [r]; 

	for (int i = 0; i < r - 1; i++)
	{
		tmp[i+1] = m[i]; 
	}

	tmp[r - 1] = new int[c]; 
	for (int j = 0; j < c; j++)
	{
		tmp[0][j] = value; 
	}

	delete[] m;
	m = tmp;
}





