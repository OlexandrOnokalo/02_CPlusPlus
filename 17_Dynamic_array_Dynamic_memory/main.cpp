#include <iostream>
using namespace std;

int* createArr(int size);
void fillArrayWithRand(int*& arr, int size);
void printArray(const int* arr, int size);
void addToFront(int element, int*& arr, int& size);
void addToEnd(int element, int*& arr, int& size);


void main() {

	int size;
	cout << "Enter size:  ";
	cin >> size;

	int* arr = createArr(size);
	fillArrayWithRand(arr, size);
	printArray(arr, size);
	int element;
	cout << "Enter element to add at front: ";
	cin >> element;
	





}