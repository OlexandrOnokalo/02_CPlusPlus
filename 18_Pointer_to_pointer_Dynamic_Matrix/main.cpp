#include <iostream>
using namespace std;

int** createMatrix(int rows, int cols);
void fillMatrixWithRand(int**& matrix, int row, int cols);
void printMatrix(int** m, int r, int c);
void addRowToFront(int**& m, int& r, int c, int value);
void removeRowbyIndex(int**& matrix, int& rows, int index);
void addRowbyIndex(int**& matrix, int& rows, int cols, int index, int value);
int** createTrianMatrix(int rows);
void printTrianMatrix(int** m, int rows);
void fillRandTrianMatrix(int** m, int rows, int left = 0, int right = 100);


void main() {
    srand(time(0));

    int rows, cols;
    cout << "Create matrix\nEnter rows and cols: ";
    cin >> rows >> cols;

    int** matrix = createMatrix(rows, cols);
    fillMatrixWithRand(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    cout << "New row added to the front\n";
    addRowToFront(matrix, rows, cols, -1);
    printMatrix(matrix, rows, cols);

    int index;
    cout << "Enter index of the row to delete from matrix: ";
    cin >> index;
    removeRowbyIndex(matrix, rows, index);
    printMatrix(matrix, rows, cols);

    cout << "Enter index to insert a new row: ";
    cin >> index;
    addRowbyIndex(matrix, rows, cols, index, -2);
    printMatrix(matrix, rows, cols);

    cout << "\nTriangle matrix test\nEnter number of rows: ";
    cin >> rows;

    int** triMatrix = createTrianMatrix(rows);
    fillRandTrianMatrix(triMatrix, rows);
    printTrianMatrix(triMatrix, rows);

    // Освобождение памяти
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
        delete[] triMatrix[i];
    }
    delete[] matrix;
    delete[] triMatrix;

    
}