    /*Перепишіть клас Stack(Queue) одного з попередніх домашніх завдань таким чином,
щоб генерувати виключення для можливих некоректних ситуацій
які можуть виникнути.
Наприклад, неможливість виділити потрібну кількість пам’яті,
переповнення стека, витяг з порожнього стека і т.д.Для
реалізації даного завдання використати або створити власні
класи - exception або ж взяти з біблеотеки <stdexcept>.*/

#include <iostream>
#include <exception>
using namespace std;


class StackBadSizeException : public exception {
public:
    StackBadSizeException(const char* message) : exception(message) {}
};

class StackOverflowException : public exception {
public:
    StackOverflowException(const char* message) : exception(message) {}
};

class StackEmptyException : public exception {
public:
    StackEmptyException(const char* message) : exception(message) {}
};


class QueueBadSizeException : public exception {
public:
    QueueBadSizeException(const char* message) : exception(message) {}
};

class QueueOverflowException : public exception {
public:
    QueueOverflowException(const char* message) : exception(message) {}
};

class QueueEmptyException : public exception {
public:
    QueueEmptyException(const char* message) : exception(message) {}
};


class Stack {
    enum { EMPTY = -1 };
    int* arr;
    int size;
    int topIndex;

public:
    Stack() = delete;

    Stack(int size) : size(size) {
        if (size <= 0) {
            throw StackBadSizeException("Error: Stack size must be greater than zero.");
        }
        arr = new int[size];
        topIndex = EMPTY;
    }

    bool IsFull() const {
        return topIndex == size - 1;
    }

    bool IsEmpty() const {
        return topIndex == EMPTY;
    }

    void Push(int elem) {
        if (IsFull()) {
            throw StackOverflowException("Error: Stack is ful.");
        }
        arr[++topIndex] = elem;
    }

    int Pop() {
        if (IsEmpty()) {
            throw StackEmptyException("Error: Stack is empty");
        }
        return arr[topIndex--];
    }

    int Peek() const {
        if (IsEmpty()) {
            throw StackEmptyException("Error: Stack is empty.");
        }
        return arr[topIndex];
    }

    int GetCount() const {
        return topIndex + 1;
    }

    void Clear() {
        topIndex = EMPTY;
    }

    void Print() const {
        for (int i = 0; i < GetCount(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Stack() {
        delete[] arr;
    }
};


class Queue {
    int* arr;
    int maxSize;
    int topIndex;

public:
    Queue() = delete;

    Queue(int max) {
        if (max <= 0) {
            throw QueueBadSizeException("Error: Size must be greater than zero.");
        }
        maxSize = max;
        arr = new int[maxSize];
        topIndex = 0;
    }

    bool IsEmpty() const {
        return topIndex == 0;
    }

    bool IsFull() const {
        return topIndex == maxSize;
    }

    void Enqueue(int elem) {
        if (IsFull()) {
            throw QueueOverflowException("Error: Queue is full.");
        }
        arr[topIndex++] = elem;
    }

    int Dequeue() {
        if (IsEmpty()) {
            throw QueueEmptyException("Error: Queue is empty.");
        }
        int first = arr[0];
        for (int i = 0; i < topIndex - 1; i++) {
            arr[i] = arr[i + 1];
        }
        topIndex--;
        return first;
    }

    int GetCount() const {
        return topIndex;
    }

    void Clear() {
        topIndex = 0;
    }

    void Show() const {
        for (int i = 0; i < topIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};


int main() {
    try {
        

        
        //Stack s1(0);

        Stack s2(3);
        s2.Push(10);
        s2.Push(20);
        s2.Push(30);

       
        // s2.Push(40);

        
        // while (true) s2.Pop();

        
        //s2.Clear();
        //s2.Peek();

        
        // Queue q1(0);

        Queue q2(2);
        q2.Enqueue(100);
        q2.Enqueue(200);

        
        // q2.Enqueue(300);

        
        // q2.Dequeue(); q2.Dequeue(); q2.Dequeue();

    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}


