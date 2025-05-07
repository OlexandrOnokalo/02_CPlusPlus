#include <iostream>
using namespace std;

    /*ТЕМА: DYNAMIC DATA STRUCTURES.PRIORITY QUEUE.

Завдання 1 :
    Розробити додаток, що імітує чергу друку принтера.
    Програма надає меню з наступними можливостями :
•Додати документ в чергу.
Користувач повинен ввести ім’я файлу та
вибрати свою посаду.В залежності від посади,
документу надається певний пріорітет
(до прикладу : гість – 1, адміністратор – 2, менеджер – 3,
    директор – 4 і тд.)
    •Виконати друк.Відображається на екран документ,
    який наразі друкується(з максимальним пріорітетом).
    Для збереження колекції документів використати динамічну
    структуру даних – Queue(черга з пріорітетним включенням).
    Клас черга має бути шаблонним.*/




template <typename T>
class QueueWithPriority
{
private:
    struct Element
    {
        T value;
        int priority;
        void Print()
        {
            cout << "Value : " << value << ". Priority : " << priority << endl;
        }
    };
    Element* arr;
    int size;
public:
    QueueWithPriority() :arr(nullptr), size(0) {}
    ~QueueWithPriority()
    {
        if (arr != nullptr)delete[]arr;
    }
    void Enqueue(T value, int priority)
    {
        int index = 0;
        while (index < size && arr[index].priority > priority) { index++; }
        size++;
        Element* temp = new Element[size];
        for (int i = 0; i < index; i++)
        {
            temp[i] = arr[i];
        }
        temp[index] = Element{ value,priority };
        for (int i = index; i < size - 1; i++)
        {
            temp[i + 1] = arr[i];
        }
        if (arr != nullptr)delete[]arr;
        arr = temp;
    }
    bool IsEmpty()
    {
        
        return size == 0;
    }
    Element Dequeue()
    {
        if (!IsEmpty())
        {
            Element first = arr[0];
            for (int i = 0; i < size - 1; i++)
            {
                
                arr[i] = arr[i + 1];
            }
            size--;
            return first;
        }
        return Element();
    }
    void Print()
    {
        cout << "------------------ Queueu -----------------" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i].value << " : " << arr[i].priority << endl;

        }
        cout << "\n______________________________________" << endl;
    }

};



int main()
{
    int choise = 0;
    string value;
    int priority;
    QueueWithPriority<string> q;

    for (; ; )
    {
        cout << "[1] - Add document" << endl;
        cout << "[2] - Print" << endl;
        cout << "[0] - Exit" << endl;
        cin >> choise;
        if (choise == 1)
        {

            cout << "Input document name: "<<endl;
            cin >> value;
            cout << "Input priority: \n guest - 1\n administrator - 2\n manager - 3\ndirector - 4" << endl;
            cin >> priority;
            q.Enqueue(value,priority);
        }
        else if (choise == 2)
        {
            q.Print();
            while (!q.IsEmpty())
            {
                q.Dequeue();
            }
        }
        else if (choise == 0)
        {
            cout << "Good bye!" << endl;
            break;
        }
        else
        {
            cout << "Wrong choise." << endl;
        }

    }






}


