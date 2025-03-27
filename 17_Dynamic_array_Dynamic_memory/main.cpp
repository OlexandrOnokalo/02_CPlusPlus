#include <iostream>
using namespace std;

int* createArr(int size);
void fillArrayWithRand(int*& arr, int size);
void printArray(const int* arr, int size);
void addToFront(int element, int*& arr, int& size);
void addToEnd(int element, int*& arr, int& size);
void removeLast(int*& arr, int& size);
void removeFirst(int*& arr, int& size);
void removeAt(int*& arr, int& size, int index);
void insertAt(int*& arr, int& size, int index, int element);
void removeNegatives(int*& arr, int& size);
void addBlock(int*& arr, int& size, const int* block, int sizeBlock);
void removeBlock(int*& arr, int& size, int index, int length);
int* intersect(const int* a, int sizeA, const int* b, int sizeB, int& size);




void main() {
	cout << "Task 3: Dynamic array" << endl;
	int size;
	cout << "Enter size of array:  ";
	cin >> size;

	srand(time(0));
	int* arr = createArr(size);
	fillArrayWithRand(arr, size);
	printArray(arr, size);
	int element;
	cout << "Enter element to add at front: ";
	cin >> element;
	addToFront(element, arr, size);
	printArray(arr, size);
	cout << "Enter element to add to end: ";
	cin >> element;
	addToEnd(element, arr, size);
	printArray(arr, size);
	cout << "Remove last: " << endl;
	removeLast(arr, size);
	printArray(arr, size);
	cout << "Remove first: " << endl;
	removeFirst(arr, size);
	printArray(arr, size);
	cout << "Enter index of element to remove: ";
	int index;
	cin >> index;
	removeAt(arr, size, index);
	printArray(arr, size);
	cout << "Enter index of element to add: ";
	cin >> index;
	cout << "Enter element to add: ";
	cin >> element;
	insertAt(arr, size, index, element);
	printArray(arr, size);
	
	/*5. Визначити функцію видалення усіх від'ємних елементів із динамічного масиву. */
	cout << "Task 5: Removing negative elements" << endl;
	cout << "Enter size of array:  ";
	cin >> size;

	arr = createArr(size);
	srand(time(0) + 3);
	fillArrayWithRand(arr, size);
	printArray(arr, size);
	removeNegatives(arr, size);
	cout << "Result: " << endl;
	printArray(arr, size);

	/*6. Створити функцію, яка дозволяє додати блок елементів у кінець  масиву.*/

	cout << "Task 6: Adding a block to the end of array" << endl;
	int sizeBlock;
	cout << "Enter size of block:  ";
	cin >> sizeBlock;
	int* block = createArr(sizeBlock);
	srand(time(0) + 15);
	fillArrayWithRand(block, sizeBlock);
	printArray(block,sizeBlock);
	addBlock(arr, size, block, sizeBlock);
	cout << "Result: " << endl;
	printArray(arr, size);

	/*7.  Створити функцію, яка дозволяє вилучити  блок елементів, починаючи із  вказаного індекса вказаної  довжини*/
	cout << "Task 7: Removing a block from the array" << endl;
	int	length;
	cout << "Enter index of start remove: ";
	cin >> index;
	cout << "Enter length:  ";
	cin >> length;
	removeBlock(arr, size, index, length);
	cout << "Result: " << endl;
	printArray(arr, size);

	cout << "Task 8: Finding intersection of two arrays" << endl;
	int sizeA;
	int sizeB;
	cout << "Enter numbers of element fot array one, then for array two:  " << endl;
	cin >> sizeA>> sizeB;
	int* A = createArr(sizeA);
	int* B = createArr(sizeB);
	srand(time(0) + 5);
	fillArrayWithRand(A, sizeA);
	srand(time(0) + 10);
	fillArrayWithRand(B, sizeB);
	printArray(A,sizeA);
	printArray(B,sizeB);
	arr = intersect(A,sizeA,B,sizeB,size);
	cout << "Result: " << endl;
	printArray(arr,size);

	delete[] arr;
	delete[] block;


	

}