#include <iostream>
using namespace std;

    /*Для масиву вагонів створити окрему структуру
з наступними полями :
struct Vagon
    номер вагону
    кількість місць
    кількість пасажирів
    class Train
    Створити клас Потяг.У класі оголосити поля(змінні члени класу) :
    модель
    кількість вагонів
    вказівник на масив вагонів(динамічний).Vagon* vagon;
В класі потяг оголосити дефолтний конструктор
і перезавантажений конструктор.
Реалізувати метод Show()
Реалізувати метод додавання вагону до динамічного масиву
Реалізувати метод - додати 1 пасажира у вагон
Реалізувати конструктор копіювання*/

struct Vagon {
    int number;
    int places;
    int passengers;
};

class Train {
private:
    string model;
    int vagonCount;
    Vagon* vagons;
public:
    Train()
    {
        model = "Hyundai";
        vagonCount = 0;
        vagons = nullptr;

    }
    Train(string model)
    {
        this->model = model;
    }
    void AddVagon(Vagon vagon)
    {
        vagonCount++;
        Vagon* temp = new Vagon[vagonCount];
        for (int i = 0; i < vagonCount - 1; i++)
        {
            temp[i] = vagons[i];
        }
        temp[vagonCount - 1] = vagon;
        if (vagons != nullptr)
            delete[] vagons;
        vagons = temp;      
    }
    void print() {
        cout << "Train model: " << model << endl;
        cout << "Vagon counter: " << vagonCount << endl;
        for (int i = 0; i < vagonCount-1; i++)
        {
            cout << "Vagon number: " << vagons[i].number << endl;
            cout << "Vagon places: " << vagons[i].places << endl;
            cout << "Vagon passengers: " << vagons[i].passengers << endl;
        }
    }
    void addOnePas(int vagonNumber) {
        for (int i = 0; i < vagonCount; i++)
        {            
            if (vagons[i].number == vagonNumber)
            {
                vagons[i].passengers++;
            }
            else
            {
                cout << "Wrong vagon number" << endl;
            }

        }
        
        

    }
};




int main()
{
    
}

