
#include <iostream>
#include <string>
using namespace std;





    /*1. Для масиву вагонів створити окрему структуру
з наступними полями :
struct Vagon
    номер вагону
    кількість місць
    кількість пасажирів
    2.class Train
    Створити клас Потяг.У класі оголосити поля(змінні члени класу) :
    модель
    кількість вагонів
    для збереження масиву вагонів викорисати List<Vagon> vagons;
В класі потяг оголосити дефолтний конструктор
і перезавантажений конструктор.
Реалізувати метод Show()
Додати методи додавання вагона в початок / кінець та видалення з
початку / кінця.
Реалізувати конструктор копіювання

3. Додати метод DeleteFromHead для класу двозв * язного списку.
Завдання 4:
На 12 балів зробити видалення по позиції та додавання по позиції*/




template<typename T>
class List
{
    struct Node
    {
        Node* prev;
        T value;
        Node* next;
        //c-tors....show()
        Node(Node* prev, T value, Node* next) :prev(prev), value(value), next(next) {}
    };

private:
    Node* head;
    Node* tail;
public:
    List()
    {
        head = nullptr;
        tail = nullptr;
    }
    bool IsEmpty()
    {
        return head == nullptr;
    }
    void AddToHead(T value)
    {
        Node* newNode = new Node(nullptr, value, head);

        if (IsEmpty())
        {
            head = tail = newNode;
        }
        head->prev = newNode;
        head = newNode;
    }
    void Print()const
    {
        //Node* current = head;//int i = 0;
        //while (current != nullptr)//i < 10;
        //{
        //    cout << current->value << " ";
        //    current = current->next;//i++;
        //}
        for (Node* i = head; i != nullptr; i = i->next)
        {
            cout << i->value << " ";
        }
        cout << endl;
    }
    ~List()
    {
        Node* current = nullptr;
        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }
    void AddToTail(T value)
    {
        Node* newNode = new Node(tail, value, nullptr);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    int GetElement(int pos)
    {
        Node* current = head;
        int i = 1;
        while (current != nullptr)
        {
            if (pos == i) return current->value;
            current = current->next;
            i++;
        }
    }
    int operator[](int pos)
    {
        Node* current = head;
        int i = 1;
        while (current != nullptr)
        {
            if (pos == i) return current->value;
            current = current->next;
            i++;
        }
    }
    void DeleteFromTail()
    {
        if (IsEmpty()) return;
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;

        }
        else {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
    }
    void DeleteFromHead()
    {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

};




struct Vagon {
    int number;
    int places;
    int passengers;
    Vagon() :number(0), places(0), passengers(0) {}
    Vagon(int n, int p, int pass) :number(n), places(p), passengers(pass) {}
    void Show()const
    {
        cout << "Vagon number: " << number << endl;
        cout << "Vagon places: " << places << endl;
        cout << "Vagon passengers: " << passengers << endl;
    }
};

ostream& operator <<(ostream& out, const Vagon& v) {
    out << "Vagon number: " << v.number << endl;
    out << "Vagon places: " << v.places << endl;
    out << "Vagon passengers: " << v.passengers << endl;
    return out;
}



class Train {
private:
    string model;
    int vagonCount;
    List<Vagon> vagons;
public:
    Train()
    {
        model = "Hyundai";
        vagonCount = 0;

    }
    Train(string model)
    {
        this->model = model;
        vagonCount = 0;
    }
    /*Train(const Train& other) {
        this->model = other.model;
        this->vagonCount = other.vagonCount;

        if (vagonCount > 0) {
            this->vagons = new Vagon[vagonCount];
            for (int i = 0; i < vagonCount; ++i) {
                this->vagons[i] = other.vagons[i];
            }
        }
        else {
            this->vagons = nullptr;
        }
    }*/
    void AddToHead(const Vagon& vag)
    {
        vagons.AddToHead(vag);
        vagonCount++;
    }
    void AddToTail(const Vagon& vag)
    {
        vagons.AddToTail(vag);
        vagonCount++;
    }
    void DeleteFromHead()
    {
        vagons.DeleteFromHead();
        if (vagonCount > 0) vagonCount--;
    }
    void DeleteFromTail()
    {
        vagons.DeleteFromTail();
        if (vagonCount > 0) vagonCount--;
    }
    void Show() const
    {
        vagons.Print();
        cout << "Total Points: " << vagonCount << endl;
    }


};




int main()
{
    Train t;
    t.AddToHead(Vagon(1, 20, 10));
    t.AddToTail(Vagon(2, 20, 12));
    t.AddToTail(Vagon(3, 30, 13));
    cout << "Initial list of vagons:\n";
    t.Show();
    cout << "Deleting from tail:\n";
    t.DeleteFromTail();
    t.Show();
    cout << "Deleting from Haed:\n";
    t.DeleteFromHead();
    t.Show();

    



}