    /*Перепишіть клас Stack(Queue) одного з попередніх домашніх завдань таким чином,
щоб генерувати виключення для можливих некоректних ситуацій
які можуть виникнути.
Наприклад, неможливість виділити потрібну кількість пам’яті,
переповнення стека, витяг з порожнього стека і т.д.Для
реалізації даного завдання використати або створити власні
класи - exception або ж взяти з біблеотеки <stdexcept>.*/

#include <iostream>
using namespace std;



class Stack {
	enum { EMPTY = -1 };
	int* arr;
	int size;
	int topIndex;
public:
	Stack() = delete;

	Stack(int size) :size(size)
	{
		if (size<=0)
		{
			throw invalid_argument("Size is less than 0");
		}
		else
		{
			arr = new int[size];
			topIndex = EMPTY;
		}
	}
	bool IsFull()const
	{
		return topIndex == size - 1;
	}
	bool Push(int elem)
	{
		if (!IsFull())
		{
			arr[++topIndex] = elem;
			return true;
		}

		return false;
	}
	bool IsEmpty()const
	{
		return topIndex == EMPTY;
	}
	int Pop()
	{
		if (!IsEmpty())
		{
			return arr[topIndex--];
		}
	}
	int Peek()
	{
		if (!IsEmpty())
		{
			return arr[topIndex];
		}
	}
	int GetCount()const
	{
		return topIndex + 1;
	}
	void Clear()
	{
		topIndex = EMPTY;
	}
	void Print()const
	{
		for (int i = 0; i < GetCount(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	~Stack()
	{
		if (arr != nullptr)
			delete[]arr;
	}
};

int main()
{
	

	try
	{
		Stack st(15);

		while (!st.IsFull())
		{
			st.Push(rand() % 100);
		}
		st.Print();
		cout << "Length : " << st.GetCount() << endl;
		while (!st.IsEmpty())
		{
			cout << "Element delete - " << st.Pop() << endl;
		}
		cout << "Count : " << st.GetCount() << endl;
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;;
	}


}
