#include <iostream>
using namespace std;

void printMatrix(int** m, int r, int c);
void removeMatrix(int**& m, int r);
void addRow(int**& m, int& r, int c, int value);
int** createMatrix(int rows, int cols);


void main()
{
	  /*1. Знайти суму та добуток трьох числових даних.Виконати через вказівники на вкаазівники.*/
	int* a = new int{ 5 };
	int** a2 = &a;

	int* b = new int{ 10 };
	int** b2 = &b;

	int* c = new int{ 15 };
	int** c2 = &c;

	cout << "a = " << **a2 << endl;
	cout << "b = " << **b2 << endl;
	cout << "c = " << **c2 << endl;

	cout << "Product = " << **a2 * **b2 * **c2 << endl;


	/*2. Написати функцію створення динамічної матриці за двома розмірами.*/

	cout << "Task 2:" << endl;

	int rows;
	int cols;
	cout << "Enter number of rows : ";
	cin >> rows;

	cout << "Enter number of columns : ";
	cin >> cols;

	int** matrix = createMatrix(rows,cols);

	printMatrix(matrix, rows, cols);




	


	




}