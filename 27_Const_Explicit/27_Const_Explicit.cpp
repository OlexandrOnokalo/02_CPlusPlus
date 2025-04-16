#include <iostream>
#include <ctime>
using namespace std;

    /*Створіть клас Array – це клас динамічного масиву чисел з певним функціоналом.
Властивостями класа буде вказівник на сам масив(long* arr) та його теперішній розмір(int size).
Клас повинен дозволяти наступний функціонал :
•	Заповнити масив значеннями(випадковими, з клавіатури, по замовчуванню(заповнити масив 0))
•	Відображати вміст масиву
•	Додавати елемент в масив
•	Видаляти елемент з масива(по значенню або по індексу)
•	Відсортувати масив(по спаданню / зростанню)
•	Визначати значення(мінімальне, максимальне та  середнє арифметичне)
Також передбачити набір конструкторів :
•	Конструктор за замовчуванням, який встановлювтиме початкові значення(заповнити масив 0))
•	Конструктор, який прийматиме розмір масиву та заповнюватиме нулем всі елементи
•	Конструктор копіювання, який буде копіювати всі дані об'єкта включаючи масив
Також реалізувати деструктор в класі для уникнення втрати пам’яті.
Врахувати можливі помилки(видалення не існуючого елемента, порожній масив і тд.).Успіхів!
Всі методі, які не змінюють оригінал мають бути CONST, create explicit constructor*/

class Array {
    long* arr;
    int size;
public:
    Array() 
    {
        size = 10;
        arr = new long[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }
    explicit Array(int size)
    {
        this->size = size;
        arr = new long[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    Array(const Array& other)
    {
        this->size = other.size;
        if (this->size>0)
        {
            this->arr = new long[this->size];
            for (int i = 0; i < this->size; i++)
            {
                this->arr[i] = other.arr[i];
            }
        }
        else
        {
            this->arr = nullptr;
        }
    }

    ~Array()
    {
        if (arr != nullptr)
            delete[] arr;
    }

    void fillRandom()
    {
        srand(time(0));
        for (int i = 0; i < size; i++)
        {
            arr[i] = (rand() % 100);
        }
    }
    void fillFromKeyboard() {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter element #" << i << endl;
            cin >> arr[i];
        }
    }
    void fillDefault() {
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }
    void print() const {
        cout << "Array: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i]<<" ";
        }
        cout << endl;
    }

    void addElement(long value) {
        size++;
        long* temp = new long[size];
        for (int i = 0; i < size-1; i++)
        {
            temp[i] = arr[i];
        }
        temp[size - 1] = value;
        if (arr!=nullptr)
            delete[] arr;
        arr = temp;
    }
    void deleteByValue(long value) {
        int index = -1;
        for (int i = 0; i < size; i++)
        {
            if (arr[i]==value)
            {
                index = i;
                break;
            }
        }
        if (index==-1)
        {
            cout << "Value not faund!" << endl; return;
        }
        long* temp = new long[size - 1];
        for (int i = 0, j = 0; i < size; ++i) {
            if (i != index) {
                temp[j++] = arr[i];
            }
        }
        delete[] arr;
        arr = temp;
        size--;


    }

    void deleteByIndex(int index) {
        if (index<0||index>=size)
        {
            cout << "Wrong index" << endl;
            return;
        }
        long* temp = new long[size - 1];
        for (int i = 0,j=0; i < size; i++)
        {
            if (i!=index)
            {
                temp[j++] = arr[i];
            }
        }
        delete[] arr;
        arr = temp;
        size--;
    }

    void sortAscending() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    long temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

    }

    void sortDescending() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j] < arr[j + 1]) {
                    long temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    long getMin() const {
        if (size == 0) return 0;
        long min = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }

    long getMax() const {
        if (size == 0) return 0;
        long max = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }

    double getAverage() const {
        if (size == 0) return 0;
        long sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += arr[i];
        }
        return static_cast<double>(sum) / size;
    }

};



void main() {
    Array a(5);
    a.fillRandom();
    a.print();
    a.addElement(77);
    a.print();
    a.deleteByIndex(2);
    a.print();
    a.sortAscending();
    a.print();
    cout << "Min: " << a.getMin() << endl;
    cout << "Max: " << a.getMax() << endl;
    cout << "Average: " << a.getAverage() << endl;

    
}


