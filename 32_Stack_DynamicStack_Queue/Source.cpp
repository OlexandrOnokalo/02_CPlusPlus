#include <iostream>
using namespace std;

/*Тема: Динамічні структури даних — стек
Завдання N1
Реалізуйте клас стек для роботи з символами(символь -
    ний стек).Стек повинен мати фіксований розмір.Також
    реалізуйте набір операцій для роботи зі стеком : внесення
    символу в стек, видалення символу зі стеку, підрахунок
    кількості символів в стеці, перевірку, чи стек порожній,
    перевірку, чи стек повний, очищення стеку, отримання
    без видалення верхнього символу в стеці.

    Завдання N2
    Змініть стек з першого завдання зі статичного типу на
    динамічний(за нестачі вільного місця потрібно змінити
        розмір внутрішнього масиву без втрати даних).*/



class Stack {
	enum { EMPTY = -1 };
	char* arr;
	int size;
	int topIndex;

public:
	Stack() = delete;

	Stack(int size) : size(size) {
		arr = new char[size];
		topIndex = EMPTY;
	}

	bool IsFull() const {
		return topIndex == size - 1;
	}

	bool IsEmpty() const {
		return topIndex == EMPTY;
	}

	void Resize() {
		int newSize = size * 2;
		char* newArr = new char[newSize];
		for (int i = 0; i <= topIndex; i++) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		size = newSize;
		cout << "[Resize] Stack resized to " << size << " elements.\n";
	}

	bool Push(char elem) {
		if (IsFull()) {
			Resize();
		}
		arr[++topIndex] = elem;
		return true;
	}

	char Pop() {
		if (!IsEmpty()) {
			return arr[topIndex--];
		}
		return '\0'; 
	}

	char Peek() {
		if (!IsEmpty()) {
			return arr[topIndex];
		}
		return '\0';
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
		if (arr != nullptr)
			delete[] arr;
	}
};

int main() {
	Stack st(5);

	for (char ch = 'A'; ch <= 'Z'; ch++) {
		st.Push(ch);
	}

	st.Print();
	cout << "Length : " << st.GetCount() << endl;

	while (!st.IsEmpty()) {
		cout << "Element deleted - " << st.Pop() << endl;
	}

	cout << "Count : " << st.GetCount() << endl;

	return 0;
}





