
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
	arr[0] = left + rand() % ((right - left) / 2 + 1);
	for (int i = 1; i < size; i++)
	{
		arr[i] = arr[i - 1] + rand() % ((right - left) / 2);
	}
}




// Визначити функцію прямого пошуку як шаблон. ПЕревірити роботу функції на масиві цілих, дробових, char,

//template <typename T>
//int searchKey(T key, T arr[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		if (arr[i]==key)
//		{
//			return i;
//		}
//	}
//	return -1;
//}

// 2.Визначити функцію(шаблон) для покращеного лінійного пошуку у впорядкованому масиві

//template <typename T>
//T searchKey(T key, T arr[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		if (arr[i] == key)
//		{
//			return i;
//		}
//		else if (arr[i]>key)
//		{
//			return -1;
//		}
//		cout << arr[i] << endl;
//	}
//	return -1;
//}

/*Впорядкування массиву*/

void bubbleSort(int arr[], int size)
{
	bool flag = true;
	for (int i = 0; i < length; i++)
	{

	}
}




int main()
{

	 //Визначити функцію прямого пошуку як шаблон. ПЕревірити роботу функції на масиві цілих, дробових, char,
	
	const int SIZE = 7;
	
	
	
	
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


	/*Впорядкування массиву*/

	




}

