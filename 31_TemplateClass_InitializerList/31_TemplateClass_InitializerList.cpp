#include <iostream>
#include <initializer_list>
#include <string>
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

    
    T GetMax() const;
    T GetMin() const;
    void Sort();
    int BinarySearch(T value) const;
    void Replace(int index, T newValue);
};



template <typename T>
T Array<T>::GetMax() const
{
    T max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

template <typename T>
T Array<T>::GetMin() const
{
    T min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

template <typename T>
void Array<T>::Sort()
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

template <typename T>
int Array<T>::BinarySearch(T value) const
{
    int left = 0;
    int right = size - 1;

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
void Array<T>::Replace(int index, T newValue)
{
    if (index >= 0 && index < size)
    {
        arr[index] = newValue;
    }
}



int main()
{
    cout << "Creating integer array: {5, 2, 9, 1, 6}" << endl;
    Array<int> arr = { 5, 2, 9, 1, 6 };
    arr.Print();

    cout << "Max element: " << arr.GetMax() << endl;
    cout << "Min element: " << arr.GetMin() << endl;

    cout << "Sorting array..." << endl;
    arr.Sort();
    arr.Print();

    int searchValue = 6;
    int index = arr.BinarySearch(searchValue);
    if (index != -1)
        cout << "Value " << searchValue << " found at index: " << index << endl;
    else
        cout << "Value " << searchValue << " not found." << endl;

    cout << "Replacing element at index 2 with 100..." << endl;
    arr.Replace(2, 100);
    arr.Print();

    cout << "\nCreating string array: {\"apple\", \"banana\", \"pear\"}" << endl;
    Array<string> fruits = { "apple", "banana", "pear" };
    fruits.Print();

    cout << "Sorting string array..." << endl;
    fruits.Sort();
    fruits.Print();

    return 0;
}

