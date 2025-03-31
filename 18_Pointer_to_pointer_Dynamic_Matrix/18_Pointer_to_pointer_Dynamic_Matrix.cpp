#include <iostream>
using namespace std;


	/*Функція створення динамічної матриці розміром row x col, 
	де row та col - аргументи функції.
	Функція повертає адресу створеної матриці*/

int** createMatrix(int rows, int cols) {
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		int* row = new int[cols] {};
		matrix[i] = row;

	}

	return matrix;
}

	/*Функція заповнення матриці*/

void fillMatrixWithRand(int**& matrix, int row, int cols) {
	srand(time(0));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = ((rand() % 20) - 10);
		}
	}
}


	/*Функція виводу матриці*/

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

		/*Функція доповнення матриці новим рядком
		(новий рядок додається як перший у матрицю)*/

void addRowToFront(int**& m, int& r, int c, int value) {
	int** tmp = new int* [r + 1];
	tmp[0] = new int[c];
	for (int j = 0; j < c; j++) {
		tmp[0][j] = value;
	}
	for (int i = 0; i < r; i++) {
		tmp[i + 1] = m[i];
	}
	delete[] m;
	m = tmp;
	r++;
}


	/*Функція видалення з матриці рядка за вказаним індексом*/


void removeRowbyIndex(int**& matrix, int& rows, int index) {
	if (index < 0 || index >= rows) return;
	delete[] matrix[index];
	for (int i = index; i < rows - 1; i++) {
		matrix[i] = matrix[i + 1];
	}
	rows--;
}


	/*Функція вставки нового рядка за вказаним індексом*/


void addRowbyIndex(int**& matrix, int& rows, int cols, int index, int value) {
	if (index < 0 || index > rows) return;
	int** tmp = new int* [rows + 1];

	for (int i = 0; i < index; i++) {
		tmp[i] = matrix[i];
	}

	tmp[index] = new int[cols];
	for (int j = 0; j < cols; j++) {
		tmp[index][j] = value;
	}

	for (int i = index; i < rows; i++) {
		tmp[i + 1] = matrix[i];
	}

	delete[] matrix;
	matrix = tmp;
	rows++;
}


	/*2) Створити функції  для роботи з  трикутною матрицею*/


	/*2.1) int** createTrianMatrix(int rows) - 
	функція отримує  число рядків та повертає  
	динамічну матрицю,
	у якій 1 - рядок містить 1 елемент, 2 - й - два елементи і т.д.*/

int** createTrianMatrix(int rows) {
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[i + 1] {};
	}
	return matrix;
}

	/*2.2) void printTrianMatrix(int** m, int rows) виведення на екран*/

void printTrianMatrix(int** m, int rows) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j <= i; j++) {
			cout << m[i][j] << "\t";
		}
		cout << endl;
	}
}



	/*2.3) void fillRandTrianMatrix(int** m, int rows, int left = 0, int right = 100) 
	- заповнення   випадковими числами у вказаному користувачем діапазоні*/


void fillRandTrianMatrix(int** m, int rows, int left = 0, int right = 100) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j <= i; j++) {
			m[i][j] = left + rand() % (right - left + 1);
		}
	}
}


