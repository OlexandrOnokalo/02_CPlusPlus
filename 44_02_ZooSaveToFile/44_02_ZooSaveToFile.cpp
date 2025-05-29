    /*До вже існуючого класу, який має колекцію динамічних об* єктів
додати механізм зберігання та зчитування даних класу з файлу
Для даних операцій перевантажити operator <<
operator >> для зчитування  та запису у файл
(Train)*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Vagon {
    int number;
    int places;
    int passengers;

    friend ofstream& operator<<(ofstream& out, const Vagon& vagon);
    friend ifstream& operator>>(ifstream& in, Vagon& vagon);
};

ofstream& operator<<(ofstream& out, const Vagon& vagon)
{
    out << vagon.number << " " << vagon.places << " " << vagon.passengers;
    return out;
}

ifstream& operator>>(ifstream& in, Vagon& vagon)
{
    in >> vagon.number >> vagon.places >> vagon.passengers;
    return in;
}

class Train {
private:
    string model;
    vector<Vagon> vagons;

public:
    Train() : model("Hyundai") {}

    Train(const string& model) : model(model) {}

    Train(const Train& other) {
        model = other.model;
        vagons = other.vagons;
    }

    void AddVagon(const Vagon& vagon)
    {
        vagons.push_back(vagon);
    }

    void print() const {
        cout << "Train model: " << model << endl;
        cout << "Vagon counter: " << vagons.size() << endl;
        for (const auto& v : vagons)
        {
            cout << "Vagon number: " << v.number << endl;
            cout << "Vagon places: " << v.places << endl;
            cout << "Vagon passengers: " << v.passengers << endl;
        }
    }

    void addOnePas(int vagonNumber) {
        bool found = false;
        for (auto& v : vagons) {
            if (v.number == vagonNumber) {
                v.passengers++;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Wrong vagon number" << endl;
        }
    }

    void BinaryWrite() {
        ofstream out("Train.bin", ios::binary);
        size_t modelSize = model.size();
        out.write(reinterpret_cast<char*>(&modelSize), sizeof(modelSize));
        out.write(model.c_str(), modelSize);

        size_t vagonCount = vagons.size();
        out.write(reinterpret_cast<char*>(&vagonCount), sizeof(vagonCount));
        for (const auto& v : vagons) {
            out.write(reinterpret_cast<const char*>(&v), sizeof(Vagon));
        }
        out.close();
        cout << "Save to file (binary)" << endl;
    }

    void BinaryRead() {
        ifstream in("Train.bin", ios::binary);
        if (!in) {
            cout << "Файл не найден!" << endl;
            return;
        }

        size_t modelSize;
        in.read(reinterpret_cast<char*>(&modelSize), sizeof(modelSize));
        model.resize(modelSize);
        in.read(&model[0], modelSize);

        size_t vagonCount;
        in.read(reinterpret_cast<char*>(&vagonCount), sizeof(vagonCount));
        vagons.resize(vagonCount);
        for (size_t i = 0; i < vagonCount; ++i) {
            in.read(reinterpret_cast<char*>(&vagons[i]), sizeof(Vagon));
        }

        in.close();
    }
};

int main()
{
    Train tr;
    Vagon vagon1{ 1, 20, 10 };
    Vagon vagon2{ 2, 20, 10 };
    Vagon vagon3{ 3, 20, 10 };

    tr.AddVagon(vagon1);
    tr.AddVagon(vagon2);
    tr.AddVagon(vagon3);

    tr.print();
    tr.BinaryWrite();

    Train readFromfile;
    readFromfile.BinaryRead();
    readFromfile.print();

    return 0;
}



