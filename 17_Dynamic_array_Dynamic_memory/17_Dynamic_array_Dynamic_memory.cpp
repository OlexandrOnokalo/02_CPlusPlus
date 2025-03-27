#include <iostream>
using namespace std;

		/*3. Створити функції для роботи з динамічним масивом
		- створення  динамічного масиву заданого розміру, розмір приходить як параметр функції
		- заповнення масиву випадковими числами + виконано
		- виведення масиву + виконано
		- доповнення масиву новим елементом(на початок)
		- доповнення масиву новим елементом(у хвіст масиву) + виконано
		- вилучення із  масиву останнього елементу
		- вилучення із  масиву першого елементу
		- вилучення елемента за вказаним індексом
		- вставки нового елемента за вказаним індексом */

int* createArr(int size) 
{
	int* arr = new int [size] {};
	return arr;
}

void fillArrayWithRand(int * & arr, int size)
{
    for (int i = 0; i < size; i++)
	{
		arr[i] = ((rand() % 20) - 10);;
	}
}

void printArray(const int* arr, int size)
{
	cout << "Array: ";
	for (int i = 0; i < size; i++)
	{
		cout << " " << arr[i];
	}
    cout << endl;
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

void removeLast(int*& arr, int& size) 
{
    if (size <= 0) {
        cout << "Error" << endl;
        return;
    }
    --size;
    int* tmp = new int[size];
    for (int i = 0; i < size; i++) {
        tmp[i] = arr[i];
    }
    delete[] arr;
    arr = tmp;
}


void removeFirst(int*& arr, int& size) 
{
    if (size <= 0) 
    {
        cout << "Error" << endl;
        return;
    }
    --size;
    int* tmp = new int[size];
    for (int i = 0; i < size; i++) {
        tmp[i] = arr[i + 1];
    }
    delete[] arr;
    arr = tmp;
}


void removeAt(int*& arr, int& size, int index) 
{
    if (index < 0 || index >= size)
    {
        cout << "Error" << endl;
        return;
    }
    --size;
    int* tmp = new int[size];
    for (int i = 0, j = 0; i < size + 1; i++) {
        if (i != index) {
            tmp[j++] = arr[i];
        }
    }
    delete[] arr;
    arr = tmp;
}


void insertAt(int*& arr, int& size, int index, int element)
{
    if (index < 0 || index > size) {
        cout << "Error" << endl;
        return;
    }
    ++size;
    int* tmp = new int[size];
    for (int i = 0, j = 0; i < size; i++) {
        if (i == index) {
            tmp[i] = element;
        }
        else {
            tmp[i] = arr[j++];
        }
    }
    delete[] arr;
    arr = tmp;
}


        /*Додаткові завдання(за бажанням)*/

    /*5. Визначити функцію видалення усіх від'ємних елементів із динамічного масиву. */

void removeNegatives(int*& arr, int& size) 
{
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0) newSize++;
    }
    int* tmp = new int[newSize];
    for (int i = 0, j = 0; i < size; i++) {
        if (arr[i] >= 0) {
            tmp[j++] = arr[i];
        }
    }
    size = newSize;
    delete[] arr;
    arr = tmp;
}

    /*6. Створити функцію, яка дозволяє додати блок елементів у кінець  масиву.*/

void addBlock(int*& arr, int& size, const int* block, int sizeBlock) 
{
    int newSize = size + sizeBlock;
    int* tmp = new int[newSize];
    for (int i = 0; i < size; i++) {
        tmp[i] = arr[i];
    }
    for (int i = 0; i < sizeBlock; i++) {
        tmp[size + i] = block[i];
    }
    size = newSize;
    delete[] arr;
    arr = tmp;
}

    /*7.  Створити функцію, яка дозволяє вилучити  блок елементів, починаючи із  вказаного індекса вказаної  довжини*/

void removeBlock(int*& arr, int& size, int index, int length) 
{
    if (index < 0 || index >= size || length <= 0) {
        cout << "Error" << endl;
        return;
    };
    if (index + length > size) length = size - index;
    int newSize = size - length;
    int* tmp = new int[newSize];
    for (int i = 0, j = 0; i < size; i++) {
        if (i < index || i >= index + length) {
            tmp[j++] = arr[i];
        }
    }
    size = newSize;
    delete[] arr;
    arr = tmp;
}



    /*8. Дано два масиви : А[M] і B[N](M і N вводяться з клавіатури).
    Необхідно створити третій масив
мінімально можливого розміру, 
у якому потрібно зібрати спільні 
елементи двох масивів без повторень.*/


int* intersect(const int* a, int sizeA, const int* b, int sizeB, int& size) 
{
    int tempSize = sizeA < sizeB ? sizeA : sizeB;
    int* temp = new int[tempSize];
    size = 0;

    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (a[i] == b[j]) {
                bool found = false;
                for (int k = 0; k < size; k++) {
                    if (temp[k] == a[i]) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    temp[size++] = a[i];
                }
            }
        }
    }

    int* result = new int[size];
    for (int i = 0; i < size; i++) {
        result[i] = temp[i];
    }
    delete[] temp;
    return result;
}






