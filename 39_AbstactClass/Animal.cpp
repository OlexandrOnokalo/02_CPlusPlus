#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string location;
    int age;
    int max_age;
    bool alive;
public:
    Animal(string loc, int max_age) : location(loc), age(0), max_age(max_age), alive(true) {}
    virtual void Eat(Animal* other) {}
    virtual void Eat(class Plant* plant) {}
    virtual void Live() {
        age++;
        if (age >= max_age) {
            alive = false;
        }
    }
    bool IsAlive() const {
        return alive;
    }
    string GetLocation() const {
        return location;
    }
    virtual string GetType() const = 0;
    virtual void Show() const {
        cout << GetType() << " | Age: " << age << " | Location: " << location << " | Alive: " << (alive ? "Yes" : "No") << endl;
    }
    void Kill() {
        alive = false;
    }
};

class Fox : public Animal {
public:
    Fox(string loc) : Animal(loc, 10) {}
    void Eat(Animal* other) override {
        if (other->GetType() == "Rabbit" && other->IsAlive() && location == other->GetLocation()) {
            other->Kill();
            cout << "Fox ate Rabbit at " << location << endl;
        }
    }
    string GetType() const override {
        return "Fox";
    }

};

class Rabbit : public Animal {
public:
    Rabbit(string loc) : Animal(loc, 5) {}
    void Eat(class Plant* plant) override;
    string GetType() const override {
        return "Rabbit";
    }
    void Kill() {
        alive = false;
    }
};

class Plant {
protected:
    string location;
    bool alive;
public:
    Plant(string loc) : location(loc), alive(true) {}
    virtual string GetType() const = 0;
    virtual void Show() const {
        cout << GetType() << " at " << location << " | Alive: " << (alive ? "Yes" : "No") << endl;
    }
    string GetLocation() const {
        return location;
    }
    bool IsAlive() const {
        return alive;
    }
    void Kill() {
        alive = false;
    }
};

class Grass : public Plant {
public:
    Grass(string loc) : Plant(loc) {}
    string GetType() const override {
        return "Grass";
    }
};

void Rabbit::Eat(Plant* plant) {
    if (plant->GetType() == "Grass" && plant->IsAlive() && location == plant->GetLocation()) {
        plant->Kill();
        cout << "Rabbit ate Grass at " << location << endl;
    }
}

class Life {
    Fox* foxes[10];
    int foxCount;
    Rabbit* rabbits[10];
    int rabbitCount;
    Grass* grasses[20];
    int grassCount;
public:
    Life() : foxCount(0), rabbitCount(0), grassCount(0) {}

    void AddFox(Fox* fox) {
        if (foxCount < 10 && foxCount < 5) {
            foxes[foxCount++] = fox;
        }
    }
    void AddRabbit(Rabbit* rabbit) {
        if (rabbitCount < 10) {
            rabbits[rabbitCount++] = rabbit;
        }
    }
    void AddGrass(Grass* grass) {
        if (grassCount < 20) {
            grasses[grassCount++] = grass;
        }
    }

    void Step() {

        for (int i = 0; i < foxCount; ++i) {
            if (foxes[i]->IsAlive()) foxes[i]->Live();
        }
        for (int i = 0; i < rabbitCount; ++i) {
            if (rabbits[i]->IsAlive()) rabbits[i]->Live();
        }


        for (int i = 0; i < rabbitCount; ++i) {
            if (rabbits[i]->IsAlive()) {
                for (int j = 0; j < grassCount; ++j) {
                    if (grasses[j]->IsAlive() && grasses[j]->GetLocation() == rabbits[i]->GetLocation()) {
                        rabbits[i]->Eat(grasses[j]);
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < foxCount; ++i) {
            if (!foxes[i]->IsAlive()) continue;
            int preyCount = 0;
            for (int j = 0; j < rabbitCount; ++j) {
                if (rabbits[j]->IsAlive() && rabbits[j]->GetLocation() == foxes[i]->GetLocation()) {
                    preyCount++;
                }
            }
            if (preyCount > 0) {
                for (int j = 0; j < rabbitCount; ++j) {
                    if (rabbits[j]->IsAlive() && rabbits[j]->GetLocation() == foxes[i]->GetLocation()) {
                        foxes[i]->Eat(rabbits[j]);
                        break;
                    }
                }
            }
        }
    }

    void ShowAll() {
        cout << "\n--- Foxes ---\n";
        for (int i = 0; i < foxCount; ++i) {
            foxes[i]->Show();
        }
        cout << "\n--- Rabbits ---\n";
        for (int i = 0; i < rabbitCount; ++i) {
            rabbits[i]->Show();
        }
        cout << "\n--- Grasses ---\n";
        for (int i = 0; i < grassCount; ++i) {
            grasses[i]->Show();
        }
    }
};











int main() {
    Life life;


    life.AddFox(new Fox("forest"));
    life.AddFox(new Fox("forest"));
    life.AddRabbit(new Rabbit("forest"));
    life.AddRabbit(new Rabbit("forest"));
    life.AddRabbit(new Rabbit("field"));
    life.AddGrass(new Grass("forest"));
    life.AddGrass(new Grass("forest"));
    life.AddGrass(new Grass("field"));
    life.AddGrass(new Grass("field"));
    life.AddGrass(new Grass("field"));

    for (int day = 0; day < 7; ++day) {
        cout << "\n=== Day " << day + 1 << " ===\n";
        life.Step();
        life.ShowAll();
    }

    return 0;
}
