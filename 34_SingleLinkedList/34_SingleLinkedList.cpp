#include <iostream>
#include <windows.h> 
using namespace std;

//	Реалізувати клас Vector, який містить колекцію точок на площині.
//Точки зберігаються у вигляді списка(змінна типу List).
//Для класу потрібно реалізувати необхідний набір конструкторів,
//методи для видалення, додавання нової точки на початок та в кінець
//та метод Print() для виводу точок на екран.
//
//class List {}
//
//class Point {}
//
//class Vector
//{
//	int size;
//	//Point * points;
//	List<Point> points;
//}
//
//- Написати метод видалення з голови.
//- зробити ліст шаблонним





template<typename T>
class List
{
private:
    struct Node
    {
        T value;
        Node* next;
        //c-tors....show()
        Node(T value, Node* next) :value(value), next(next) {}
    };
    Node* head;
public:
    List()
    {
        head = nullptr;
    }
    void AddToHead(T value)
    {
        /* Node* newNode = new Node;
         newNode->value = value;
         newNode->next = head;*/
        Node* newNode = new Node(value, head);
        head = newNode;
    }
    void Print()const
    {
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
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
        Node* newNode = new Node(value, nullptr);
        if (head == nullptr)
        {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    T GetElement(int pos)
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
    T operator[](int pos)
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
        if (head == nullptr) return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;

        }
        else {
            Node* current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }


    }
};



class Point
{
    int x;
    int y;
public:
    Point();
    Point(int x, int y);
    Point operator++(int);
    Point operator--(int);
    bool operator >(const Point& other);
    bool operator <(const Point& other);
    void Show() const;
    void ShowAtCoords() const;
};
Point::Point() {
    x = y = 0;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point Point::operator++(int) {
    this->x++;
    this->y++;
    return *this;
}

Point Point::operator--(int) {
    this->x--;
    this->y--;
    return *this;
}

bool Point::operator>(const Point& other) {
    return (this->x * this->x + this->y * this->y) > (other.x * other.x + other.y * other.y);
}

bool Point::operator<(const Point& other) {
    return (this->x * this->x + this->y * this->y) < (other.x * other.x + other.y * other.y);
}

void Point::Show() const {
    cout << "X: " << x << " Y: " << y << endl;
}

void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Point::ShowAtCoords() const {
    gotoxy(x, y);
    cout << "*";
}









class Vector
{
	List<Point> points;
    int countPoint;
public:
    Vector()
    {

        countPoint = 0;
    }

};


















int main()
{
    Point p;
    
}
