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


class Stack
{
    enum { EMPTY = -1, FULL = 9 };
    char arr[FULL + 1];
    int topIndex;
public:
    Stack()
    {
        topIndex = EMPTY;
    }
    Stack(const Stack& other) = delete;

    bool Push(int elem)
    {
        if (!IsFull())
        {
            ++topIndex;
            arr[topIndex] = elem;
            return true;
        }
        return false;
    }
    bool IsFull()const
    {
        return topIndex == FULL;
    }
    bool IsEmpty()const
    {
        return topIndex == EMPTY;
    }
    char Pop()
    {
        if (!IsEmpty())
            
            return arr[topIndex--];         
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
    ~Stack() = default;
};

//int main()
//{
//    Stack st;
//    st.Push('a');
//    st.Push('b');
//    st.Push('c');
//    st.Print();
//    cout << "Count : " << st.GetCount() << endl;
//
//    while (!st.IsEmpty())
//    {
//        cout << st.Pop() << endl;
//    }
//    cout << "Count : " << st.GetCount() << endl;
//
//   
//}




