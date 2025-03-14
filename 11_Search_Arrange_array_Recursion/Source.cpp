#include <iostream>
using std::cout;
using std::endl;
using std::cin;
int main();
void print(const int arr[], int size);
void fillRandomUp(int arr[], int size, int left = 0, int right = 100);
int binarySearch(int key, const int arr[], int size);
int linearModifSearch(int key, const int arr[], int size);

int main()
{
    const int SIZE = 10;
    int arr[SIZE];
    fillRandomUp(arr, SIZE);
    print(arr, SIZE);

    int key;
    cout << "Enter a key to search: ";
    cin >> key;
    int index = binarySearch(key, arr, SIZE);
    cout << "\nIndex of key = " << index << endl;

    int index = linearModifSearch(key, arr, SIZE);
    cout << "\nIndex of key = " << index << endl;
}

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
int linearModifSearch(int key, const int arr[], int size)
{
    int i;
    for (i = 0; i < size && arr[i] < key; i++)
    {

    }
    if (arr[i] == )
}

int binarySearch(int key, const int arr[], int size)
{
    int left = 0, right = size - 1;
    int mid;// = (left + right) / 2;
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