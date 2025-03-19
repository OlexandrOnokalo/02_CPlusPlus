#include <iostream>
using namespace std;


void ShowArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
}




/*1.Дано три числа.Оголосити ссилки на ці числа.
	Отримати добуток трьох заданих чисел, середє арифметичне, найменше з них,
	користуючись непрямим доступом до чисел(через ссилку)*/

void first(int& a, int& b, int& c, int& product, int& average, int& min) {
	product = a * b * c;
	average = (a + b + c) / 3;
	if (a<b && a<c)
	{
		min = a;
	}
	else if (b<a && b<c)
	{
		min = b;
	}
	else
	{
		min = c;
	}
}

/*2.Написати функцію, яка замінює всі від’ємні елементи переданого масиву нулями.*/

void fillZero(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		if (*(arr+i)<0)
		{
			*(arr + i) = 0;
		}
	}
}






/*3.Написать функцію(або шаблон), яка приймає дві ссилки на змінні і
	виконує обмін значень.За допомогою написаної функції поміняти місцями
	у матриці перший та другий стовпці.*/

template <typename T>
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

void ShowMatrix(int arr[][5], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void SwapColumns(int arr[][5], int row) {
	for (int i = 0; i < row; i++) {
		int& a = arr[i][0];
		int& b = arr[i][1];
		Swap(a,b); 
	}								
}





int main()
{
   
	/*1.Дано три числа.Оголосити ссилки на ці числа.
		Отримати добуток трьох заданих чисел, середє арифметичне, найменше з них,
		користуючись непрямим доступом до чисел(через ссилку)*/

	int a = 5, b = 10, c = 15;
	int product=1, average=0, min=0;
	int& la = a, lb = b, lc = c;
	int& lproduct = product; 
	int& laverage = average;
	int& lmin = min;
	first(la, lb, lc, lproduct, laverage, lmin);
	cout << "Product = " << product << "\nAverage = " << average << "\nMinimum = " << min << endl;
	cout << endl;


	/*2.Написати функцію, яка замінює всі від’ємні елементи переданого масиву нулями.*/

	const int size = 6;
	int arr[size] = { 10,-20,30,-40,50,-60 };
	ShowArr(arr, size);
	fillZero(arr, size);
	cout << "Magic!!" << endl;
	ShowArr(arr, size);
	cout << endl;

	/*3.Написать функцію(або шаблон), яка приймає дві ссилки на змінні і
		виконує обмін значень.За допомогою написаної функції поміняти місцями
		у матриці перший та другий стовпці.*/

	const int row = 2;
	const int col = 5;
	int matrix[row][col] = { {1,2,3,4,5},{6,7,8,9,10} };
	cout << "Matrix: " << endl;
	ShowMatrix(matrix, row, col);
	SwapColumns(matrix, row);
	cout << "Resault: " << endl;
	ShowMatrix(matrix, row, col);

}

