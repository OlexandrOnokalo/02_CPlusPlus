    /*До вже існуючого класу, який має колекцію динамічних об* єктів
додати механізм зберігання та зчитування даних класу з файлу
Для даних операцій перевантажити operator <<
operator >> для зчитування  та запису у файл
(Train)*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Vagon {
    int number;
    int places;
    int passengers;
    friend ofstream& operator <<(ofstream& out, Vagon& vagon);
    friend ifstream& operator >>(ifstream& in, Vagon& vagon);
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
        vagonCount = 0;
        vagons = nullptr;
    }
    Train(const Train& other) {
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
        for (int i = 0; i < vagonCount; i++)
        {
            cout << "Vagon number: " << vagons[i].number << endl;
            cout << "Vagon places: " << vagons[i].places << endl;
            cout << "Vagon passengers: " << vagons[i].passengers << endl;
        }
    }
    void addOnePas(int vagonNumber) {
        bool found = false;
        for (int i = 0; i < vagonCount; i++) {
            if (vagons[i].number == vagonNumber) {
                vagons[i].passengers++;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Wrong vagon number" << endl;
        }
    }


    void BinaryWrite()
    {
        ofstream out("Train.bin", ios_base::out | ios_base::binary);
        out.write((char*)&model, sizeof(model));
        out.write((char*)&vagonCount, sizeof(vagonCount));
        for (int i = 0; i < vagonCount; i++)
        {
            out.write((char*)&vagons[i], sizeof(vagons[i]));

        }
        out.close();
        cout << "Save to file  binary" << endl;
    }
    void BinaryRead()
    {
        ifstream in("Train.bin", ios_base::in | ios_base::binary);
        in.read((char*)&model, sizeof(model));
        in.read((char*)&vagonCount, sizeof(vagonCount));
        vagons = new Vagon[vagonCount];
        for (int i = 0; i < vagonCount; i++)
        {
            
            in.read((char*)&vagons[i], sizeof(vagons[i]));
        }
        in.close();

    }












};

ofstream& operator <<(ofstream& out, Vagon& vagon)
{
    out << vagon.number << " " << vagon.places << " " << vagon.passengers;
    return out;
}
ifstream& operator >>(ifstream& in, Vagon& vagon)
{
    in >> vagon.number >> vagon.places >> vagon.passengers;
    return in;
}


int main()
{

    //Train tr;
    //Vagon vagon1{ 1,20,10 };
    //Vagon vagon2{ 2,20,10 };
    //Vagon vagon3{ 3,20,10 };
    //tr.AddVagon(vagon1);
    //tr.AddVagon(vagon2);
    //tr.AddVagon(vagon3);
    //tr.print();
    //tr.BinaryWrite();

    Train readFromfile;
    //readFromfile.ReadFromFile();
    readFromfile.BinaryRead();
    readFromfile.print();



















}


