#include "function.h"
#include <cstring>


void inputBoiler(Boiler& b) {
    cout << "Enter the company: ";
    cin >> b.company;
    cout << "Enter the color: ";
    cin >> b.color;
    cout << "Enter the power: ";
    cin >> b.power;
    cout << "Enter the volume: ";
    cin >> b.volume;
    cout << "Enter the initial temperature: ";
    cin >> b.temperature;
    cout << endl;
}

void printBoiler(const Boiler& b) {
    cout << "Boiler Details: " << endl;
    cout << "Company: " << b.company << endl;
    cout << "Color: " << b.color << endl;
    cout << "Power: " << b.power << " kW" << endl;
    cout << "Volume: " << b.volume << " liters" << endl;
    cout << "Temperature: " << b.temperature << " C" << endl;
    cout << endl;
}

void increaseTemperature(Boiler& b, double temp) {
    if (temp > 0) {
        b.temperature += temp;
    }
    else {
        cout << "\nInvalid temperature increase!" << endl;
    }
}

void decreaseTemperature(Boiler& b, double temp) {
    if (temp > 0 && b.temperature - temp >= 0) {
        b.temperature -= temp;
    }
    else {
        cout << "\nInvalid temperature decrease!" << endl;
    }
}

bool compareBoilers(const Boiler& b1, const Boiler& b2) {
    return b1.power > b2.power;
}


Fraction add(const Fraction& one, const Fraction& two) {
    Fraction result;
    result.numerator = one.numerator * two.denominator + one.denominator * two.numerator;
    result.denominator = one.denominator * two.denominator;
    return result;
}

Fraction subtract(const Fraction& one, const Fraction& two) {
    Fraction result;
    result.numerator = one.numerator * two.denominator - one.denominator * two.numerator;
    result.denominator = one.denominator * two.denominator;
    return result;
}

Fraction multiply(const Fraction& one, const Fraction& two) {
    Fraction result;
    result.numerator = one.numerator * two.numerator;
    result.denominator = one.denominator * two.denominator;
    return result;
}

Fraction divide(const Fraction& one, const Fraction& two) {
    Fraction result{};
    if (two.numerator != 0) {
        result.numerator = one.numerator * two.denominator;
        result.denominator = one.denominator * two.numerator;
        return result;
    }
    else {
        cout << "Error: Division by zero" << endl;
        
    }    
}


void inputFraction(Fraction& f) {
    cout << "Enter numerator: ";
    cin >> f.numerator;
    cout << "Enter denominator: ";
    cin >> f.denominator;
}

void printFraction(const Fraction& f) {
    cout << "\nFraction: " << f.numerator << "/" << f.denominator << endl;
}

void testArithmeticOperations(const Fraction& f1, const Fraction& f2, char op) {
    Fraction result;

    if (op=='+')
    {
        result = add(f1, f2);
        cout << "\nAdd:" << endl;
        printFraction(result);
    }
    else if (op == '-')
    {
        result = subtract(f1, f2);
        cout << "\nSubtrack:" << endl;
        printFraction(result);
    }
    else if (op == '*')
    {
        result = multiply(f1, f2);
        cout << "\nMultiply:" << endl;
        printFraction(result);
    }
    else if (op == '/')
    {
        result = divide(f1, f2);
        cout << "\nDivide:" << endl;
        printFraction(result);
    }
    else
    {
        cout << "Error choise!";
    }
    

    
}


void addProduct(Product products[], int& count) {
    Product p;
    cout << "Enter product name: ";
    cin >> p.name;
    cout << "Enter product category: ";
    cin >> p.category;
    cout << "Enter product price: ";
    cin >> p.price;
    products[count++] = p;
}

void printProducts(const Product products[], int count) {
    cout << "\nProducts list: " << endl;
    for (int i = 0; i < count; i++) {
        cout << "Product " << i  << ": " << products[i].name << ", "
            << products[i].category << ", Price: " << products[i].price << endl;
    }
}

void printProductsByCategory(const Product products[], int count, const char* category) {
    cout << "\nProducts in category " << category << ": " << endl;
    for (int i = 0; i < count; i++) {
        if (strncmp(products[i].category, category, 100) == 0) {
            cout << products[i].name << ", Price: " << products[i].price << endl;
        }
    }
}

void printProductsByPrice(const Product products[], int count, double maxPrice) {
    cout << "\nProducts cheaper than " << maxPrice << ": " << endl;
    for (int i = 0; i < count; i++) {
        if (products[i].price < maxPrice) {
            cout << products[i].name << ", Price: " << products[i].price << endl;
        }
    }
}

void removeProduct(Product products[], int& count, int index) {
    if (index >= 0 && index < count) {
        for (int i = index; i < count - 1; i++) {
            products[i] = products[i + 1];
        }
        count--;
        cout << "\nProduct removed." << endl;
    }
    else {
        cout << "\nInvalid index!" << endl;
    }
}
