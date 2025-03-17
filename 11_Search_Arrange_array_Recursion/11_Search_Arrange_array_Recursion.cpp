
#include <iostream>
using namespace std;



void print(const int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "\t" << arr[i];
	}
	cout << endl;
}

void fillRandomUp(int arr[], int size, int left, int right)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		arr[i] = (rand() % (right - left)+left);
	}
}





// Визначити функцію прямого пошуку як шаблон. ПЕревірити роботу функції на масиві цілих, дробових, char,

	/*template <typename T>
	int searchKey(T key, T arr[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i]==key)
			{
				return i;
			}
		}
		return -1;
	}*/

// 2.Визначити функцію(шаблон) для покращеного лінійного пошуку у впорядкованому масиві

	/*template <typename T>
	T searchKey(T key, T arr[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == key)
			{
				return i;
			}
			else if (arr[i]>key)
			{
				return -1;
			}
			cout << arr[i] << endl;
		}
		return -1;
	}*/





		   /*         Homework from file Homework C plus - sorting.txt*/

	/*Завдання 1
	Написати функцію або шаблон функції, яка сортує масив за зростанням або за спаданням методом вибору(Selection Sort),
	залежно від третього параметра функції.
	Якщо він дорівнює true, сортування йде за зростанням, якщо false — за спаданням.
	Перші 2 параметри функції — це масив і його розмір, третій параметр за замовчуванням дорівнює true.*/




	template <typename T>
	void selectionSort(T arr[], int size, bool ascending = true) {
		for (int i = 0; i < size - 1; ++i) {
			int index = i;

			for (int j = i + 1; j < size; ++j) {
				if (ascending)
				{
					if (arr[j] < arr[index]) {
						index = j;
					}
				}
				else
				{
					if (arr[j] > arr[index]) {
						index = j;
					}
				}
			}
			swap(arr[i], arr[index]);
		}
	}


	/*Завдання 2
Написати функцію або шаблон функції, яка сортує першу половину масиву за спаданням, а другу — за зростанням,
використовуючи алгоритм бульбашки або камінця.*/

	void bubbleSort(int arr[], int start, int end, bool ascending) {
		for (int i = start; i < end; ++i) {
			for (int j = start; j < end - (i - start); ++j) {
				if (ascending) {
					if (arr[j] > arr[j + 1]) {
						swap(arr[j], arr[j + 1]);
					}
				}
				else {
					if (arr[j] < arr[j + 1]) {
						swap(arr[j], arr[j + 1]);
					}
				}
			}
		}
	}

	void customSort(int arr[], int size) {
		int mid = size / 2;

		
		bubbleSort(arr, 0, mid, false);

		
		bubbleSort(arr, mid, size - 1, true);
	}



	/*Завдання 3
У функцію передається масив випадкових чисел у діапазоні від - 20 до + 20.
Необхідно знайти позиції крайніх від'ємних елементів (найлівішого від'ємного елемента і найправішого від'ємного елемента) 
і відсортувати елементи, що знаходяться між ними.

Додатково написати функції пошуку першого від'ємного (найлівішого) та останнього від'ємного(найправішого) елемента.
Функції повертають індекс знайденого від'ємного або -1 при невдалому пошуку. 
Використати ці функції для пошуку крайніх від'ємних елементів у масиві.*/


	int findFirstNegative(int arr[], int size) {
		for (int i = 0; i < size; ++i) 
		{
			if (arr[i] < 0) 
			{
				return i;
			}
		}
		return -1;
	}

	int findLastNegative(int arr[], int size) 
	{
		for (int i = size - 1; i >= 0; --i) 
		{
			if (arr[i] < 0) {
				return i;
			}
		}
		return -1;
	}

	void sortBetweenNegatives(int arr[], int left, int right) 
	{
		for (int i = left; i < right; ++i) {
			for (int j = i + 1; j <= right; j++) {
				if (arr[i] > arr[j]) {
					swap(arr[i], arr[j]);
				}
			}
		}
	}



	/*Додаткове завдання.
		Завдання 4
		Переписати функцію бінарного пошуку
		int binarySearch(int key, const int arr[], int size)
	{
		int left = 0, right = size - 1;
		int mid = 0;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (arr[mid] == key)
				return mid;
			if (key > arr[mid])
				left = mid + 1;
			else
				right = mid - 1;
		}
		return -1;
	}
	
	Додати у функцію третій параметр логічного типу, який буде вказувати на порядок сортування.
	Якщо він дорівнює true, то у функцію передано масив впорядкований за зростанням, якщо false — за спаданням.*/

int binarySearch(int key, const int arr[], int size, bool ascending)
{
	int left = 0, right = size - 1;
	int mid = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (arr[mid] == key)
			return mid;

		if (ascending == true) 
		{  
			if (key > arr[mid])
				left = mid + 1;
			else
				right = mid - 1;
		}
		else {
			if (key < arr[mid])  
				left = mid + 1;
			else
				right = mid - 1;
		}
	}
	return -1; 
}






int main()
{

	 //Визначити функцію прямого пошуку як шаблон. ПЕревірити роботу функції на масиві цілих, дробових, char,
	
	/*const int SIZE = 7;*/
	
	
	
	
	/*cout << "Enter a key : " << endl;

	int arr[SIZE] = { 10,22,34,100,23,-45,67 };
	int key;
	cin >> key;
	int index = searchKey(key, arr, SIZE);
	cout << "Index of key = " << index << endl;
	
	float arr2[SIZE] = { 1.0,2.0,3.0,4.0,5.0,6.0,7.0 };
	float key2;
	cin >> key2;
	int index = searchKey(key2, arr2, SIZE);
	cout << "Index of key = " << index << endl;
	
	char arr3[SIZE] = { 'q','w','e','r','t','y','u'};
	char key3;
	cin >> key3;
	int index = searchKey(key3, arr3, SIZE);
	cout << "Index of key = " << index << endl;*/




	//2.Визначити функцію(шаблон) для покращеного лінійного пошуку у впорядкованому масиві

	/*cout << "Enter a key : " << endl;

	int arr[SIZE] = { 10,20,30,40,50,60,70 };
	int key;
	cin >> key;
	int index = searchKey(key, arr, SIZE);
	cout << "Index of key = " << index << endl;*/




	           /*         Homework from file Homework C plus - sorting.txt*/

	/*Завдання 1
	Написати функцію або шаблон функції, яка сортує масив за зростанням або за спаданням методом вибору(Selection Sort),
	залежно від третього параметра функції.
	Якщо він дорівнює true, сортування йде за зростанням, якщо false — за спаданням.
	Перші 2 параметри функції — це масив і його розмір, третій параметр за замовчуванням дорівнює true.*/


	
	const int SIZE = 7;
	int arr[SIZE] = { 60,20,40,30,70,10,50 };

	print(arr, SIZE);
	cout << "Sorting in ascending order:" << endl;
	selectionSort(arr, SIZE);
	print(arr, SIZE);

	cout << "Sort by descending order:" << endl;
	selectionSort(arr, SIZE, false);
	print(arr, SIZE);

	/*Завдання 2
		Написати функцію або шаблон функції, яка сортує першу половину масиву за спаданням, а другу — за зростанням,
		використовуючи алгоритм бульбашки або камінця.*/

	const int SIZE = 8;
	int arr[SIZE] = { 60,20,40,30,70,10,50,90 };

	print(arr, SIZE);
	
	customSort(arr, SIZE);

	cout << "Sorted array: ";
	print(arr, SIZE);
	cout << endl;


		/*Завдання 3
	У функцію передається масив випадкових чисел у діапазоні від - 20 до + 20.
	Необхідно знайти позиції крайніх від'ємних елементів (найлівішого від'ємного елемента і найправішого від'ємного елемента)
	і відсортувати елементи, що знаходяться між ними.

	Додатково написати функції пошуку першого від'ємного (найлівішого) та останнього від'ємного(найправішого) елемента.
	Функції повертають індекс знайденого від'ємного або -1 при невдалому пошуку.
	Використати ці функції для пошуку крайніх від'ємних елементів у масиві.*/

	const int SIZE = 8;
	int arr[SIZE];
	fillRandomUp(arr, SIZE, -20, +20);

	print(arr, SIZE);

	int left = findFirstNegative(arr, SIZE);
	int right = findLastNegative(arr, SIZE);

	if (left == -1 || right == -1) {
		cout << "No negative elements" << endl;
		return 0;
	}

	cout << "Index first negative: " << left << endl;
	cout << "Index last negative: " << right << endl;

	sortBetweenNegatives(arr, left, right);

	cout << "Sorted array: "<<endl;
	print(arr, SIZE);
	cout << endl;

	/*Завдання 4
	Переписати функцію бінарного пошуку
	int binarySearch(int key, const int arr[], int size)
	{
		int left = 0, right = size - 1;
		int mid = 0;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (arr[mid] == key)
				return mid;
			if (key > arr[mid])
				left = mid + 1;
			else
				right = mid - 1;
		}
		return -1;
	}

	Додати у функцію третій параметр логічного типу, який буде вказувати на порядок сортування.
	Якщо він дорівнює true, то у функцію передано масив впорядкований за зростанням, якщо false — за спаданням.*/


	const int SIZE = 7;
	int arr[SIZE] = { 10,20,30,40,50,60,70 };
	print(arr, SIZE);
	int key;
	cin >> key;
	bool ascending = true;

	int result = binarySearch(key, arr, SIZE, ascending);
	if (result != -1)
		cout << "Founded on index: " << result << endl;
	else
		cout << "No such element!" << endl;

	int arr2[SIZE] = { 70,60,50,40,30,20,10 };
	print(arr2, SIZE);

	cin >> key;
	ascending = false;

	result = binarySearch(key, arr2, SIZE, ascending);
	if (result != -1)
		cout << "Founded on index: " << result << endl;
	else
		cout << "No such element!" << endl;

}

