
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
На 12 балів зробити видалення по  позиції та додавання по позиції*/



template<typename T>
class List
{
    struct Node
    {
        Node* prev;
        T value;
        Node* next;
        Node(Node* prev, T value, Node* next) : prev(prev), value(value), next(next) {}
    };

private:
    Node* head;
    Node* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    bool IsEmpty() const { return head == nullptr; }

    void AddToHead(T value) {
        Node* newNode = new Node(nullptr, value, head);
        if (IsEmpty()) {
            head = tail = newNode;
        }
        else {
            head->prev = newNode;
            head = newNode;
        }
    }

    void AddToTail(T value) {
        Node* newNode = new Node(tail, value, nullptr);
        if (IsEmpty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void DeleteFromHead() {
        if (IsEmpty()) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }

    void DeleteFromTail() {
        if (IsEmpty()) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }

    void AddAt(int pos, const T& value) {
        if (pos <= 0) return AddToHead(value);
        Node* current = head;
        for (int i = 0; i < pos - 1 && current != nullptr; ++i)
            current = current->next;
        if (!current) return AddToTail(value);
        Node* newNode = new Node(current, value, current->next);
        if (current->next)
            current->next->prev = newNode;
        else
            tail = newNode;
        current->next = newNode;
    }

    void DeleteAt(int pos) {
        if (IsEmpty()) return;
        if (pos == 0) return DeleteFromHead();
        Node* current = head;
        for (int i = 0; i < pos && current != nullptr; ++i)
            current = current->next;
        if (!current) return;
        if (current->prev)
            current->prev->next = current->next;
        if (current->next)
            current->next->prev = current->prev;
        if (current == head) head = current->next;
        if (current == tail) tail = current->prev;
        delete current;
    }

    void Print() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value;
            current = current->next;
        }
    }

    ~List() {
        while (!IsEmpty())
            DeleteFromHead();
    }

    List(const List& other) : head(nullptr), tail(nullptr) {
        Node* current = other.head;
        while (current != nullptr) {
            AddToTail(current->value);
            current = current->next;
        }
    }

    List& operator=(const List& other) {
        if (this == &other) return *this;
        while (!IsEmpty()) DeleteFromHead();
        Node* current = other.head;
        while (current != nullptr) {
            AddToTail(current->value);
            current = current->next;
        }
        return *this;
    }
};

struct Vagon {
    int number;
    int places;
    int passengers;
    Vagon() : number(0), places(0), passengers(0) {}
    Vagon(int n, int p, int pass) : number(n), places(p), passengers(pass) {}

    void Show() const {
        cout << "Vagon number: " << number << ", places: " << places << ", passengers: " << passengers << endl;
    }
};

ostream& operator<<(ostream& out, const Vagon& v) {
    out << "[#" << v.number << ", places: " << v.places << ", pass: " << v.passengers << "] "<< endl;
    return out;
}

class Train {
private:
    string model;
    int vagonCount;
    List<Vagon> vagons;

public:
    Train() : model("Hyundai"), vagonCount(0) {}
    Train(string model) : model(model), vagonCount(0) {}

    Train(const Train& other) {
        model = other.model;            
        vagonCount = other.vagonCount;  
        vagons = other.vagons;          
    }

    void AddToHead(const Vagon& vag) {
        vagons.AddToHead(vag);
        vagonCount++;
    }

    void AddToTail(const Vagon& vag) {
        vagons.AddToTail(vag);
        vagonCount++;
    }

    void DeleteFromHead() {
        vagons.DeleteFromHead();
        if (vagonCount > 0) vagonCount--;
    }

    void DeleteFromTail() {
        vagons.DeleteFromTail();
        if (vagonCount > 0) vagonCount--;
    }

    void AddAtPosition(int pos, const Vagon& vag) {
        vagons.AddAt(pos, vag);
        vagonCount++;
    }

    void DeleteAtPosition(int pos) {
        vagons.DeleteAt(pos);
        if (vagonCount > 0) vagonCount--;
    }

    void Show() const {
        cout << "Train model: " << model << "\n";
        cout << "Vagons:\n";
        vagons.Print();
        cout << "\nTotal Vagons: " << vagonCount << "\n\n";
    }
};

int main() {
    Train t("Intercity");

    t.AddToHead(Vagon(1, 20, 10));
    t.AddToTail(Vagon(2, 25, 15));
    t.AddToTail(Vagon(3, 30, 20));
    t.AddAtPosition(0, Vagon(0, 40, 35)); 

    cout << "Initial train:\n";
    t.Show();

    t.DeleteFromHead();
    cout << "After deleting from head:\n";
    t.Show();

    t.DeleteFromTail();
    cout << "After deleting from tail:\n";
    t.Show();

    t.DeleteAtPosition(1);
    cout << "After deleting at position 1:\n";
    t.Show();

    Train copy = t;
    cout << "Copied train:\n";
    copy.Show();

    return 0;
}
