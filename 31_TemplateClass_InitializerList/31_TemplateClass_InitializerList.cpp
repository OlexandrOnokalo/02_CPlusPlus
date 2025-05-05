#include <iostream>
#include <initializer_list>
using namespace std;


	/*Шаблони класів.initializer_list
Завдання 1:
Перетворити раніше створений клас Array на шаблон, який дозволить
зберігати елементи будь - якого типу.Функціональність залишити на
тому ж рівні.
Додати можливість створювати об'єкт та присвоювати йому 
значення шляхом спискової ініціалізації : { 1, 2, 3...}
Завдання 2 :
	Реалізуйте шаблонні функції для пошуку максимуму,
	мінімуму, сортування масиву(будь - яким алгоритмом
		сортування), двійкового пошуку в масиві, заміни  елемента
	масиву на передане значення.Ці методи винести за межі класу*/




template <typename T>
class Array
{
    T* arr;
    int size;
public:
    Array() : arr(nullptr), size(0) {}

    explicit Array(int size) : size(size)
    {
        arr = new T[size]{};
    }

    Array(const initializer_list<T>& list)
    {
        size = list.size();
        arr = new T[size];
        int i = 0;
        for (T elem : list)
        {
            arr[i++] = elem;
        }
    }

    void Fill(const initializer_list<T>& list)
    {
        if (arr != nullptr)
            delete[] arr;
        size = list.size();
        arr = new T[size];
        int i = 0;
        for (T elem : list)
        {
            arr[i++] = elem;
        }
    }

    ~Array()
    {
        delete[] arr;
    }

    void Print() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    T& operator[](int index)
    {
        return arr[index];
    }

    const T& operator[](int index) const
    {
        return arr[index];
    }

    int GetSize() const { return size; }

    T* GetData() const { return arr; }
};


template <typename T>
T GetMax(const Array<T>& arr)
{
    T max = arr[0];
    for (int i = 1; i < arr.GetSize(); i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}


template <typename T>
T GetMin(const Array<T>& arr)
{
    T min = arr[0];
    for (int i = 1; i < arr.GetSize(); i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}


template <typename T>
void Sort(Array<T>& arr)
{
    for (int i = 0; i < arr.GetSize() - 1; i++)
    {
        for (int j = 0; j < arr.GetSize() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}


template <typename T>
int BinarySearch(const Array<T>& arr, T value)
{
    int left = 0;
    int right = arr.GetSize() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; 
}


template <typename T>
void Replace(Array<T>& arr, int index, T newValue)
{
    if (index >= 0 && index < arr.GetSize())
    {
        arr[index] = newValue;
    }
}

int main()
{
    cout << "Creating integer array: {5, 2, 9, 1, 6}" << endl;
    Array<int> arr = { 5, 2, 9, 1, 6 };
    arr.Print();

    cout << "Max element: " << GetMax(arr) << endl;
    cout << "Min element: " << GetMin(arr) << endl;

    cout << "Sorting array..." << endl;
    Sort(arr);
    arr.Print();

    int searchValue = 6;
    int index = BinarySearch(arr, searchValue);
    if (index != -1)
        cout << "Value " << searchValue << " found at index: " << index << endl;
    else
        cout << "Value " << searchValue << " not found." << endl;

    cout << "Replacing element at index 2 with 100..." << endl;
    Replace(arr, 2, 100);
    arr.Print();

    cout << "Creating string array: {\"apple\", \"banana\", \"pear\"}" << endl;
    Array<string> fruits = { "apple", "banana", "pear" };
    fruits.Print();

    cout << "Sorting string array..." << endl;
    Sort(fruits);
    fruits.Print();

    return 0;
}



