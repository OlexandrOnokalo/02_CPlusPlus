#include <iostream>
#include "function.h"

using namespace std;

int main() {
    
    cout << "Task 1" << endl;
    Boiler b1, b2;

    cout << "Enter the characteristics of the first boiler:" << endl;
    inputBoiler(b1);

    cout << "Enter the characteristics of the second boiler:" << endl;
    inputBoiler(b2);

    
    printBoiler(b1);
    printBoiler(b2);

    
    double increaseValue;
    cout << "Enter the value to increase the temperature of the first boiler: ";
    cin >> increaseValue;
    increaseTemperature(b1, increaseValue); 

    
    double decreaseValue;
    cout << "Enter the value to decrease the temperature of the second boiler: ";
    cin >> decreaseValue;
    decreaseTemperature(b2, decreaseValue);  

    
    printBoiler(b1);
    printBoiler(b2);

    
    if (compareBoilers(b1, b2)) {
        cout << "The first boiler is more powerful!" << endl;
    }
    else {
        cout << "The second boiler is more powerful!" << endl;
    }

    
    cout << "\nTask 2" << endl;
    Fraction f1, f2;
    char op;

    cout << "Enter the first fraction:" << endl;
    inputFraction(f1);

    cout << "Enter the second fraction:" << endl;
    inputFraction(f2);

    cout << "Choose an operation (+, -, *, /): ";
    cin >> op;
    testArithmeticOperations(f1, f2, op);

    
    cout << "\nTask 3" << endl;

    
    Product products[SIZE] = {
        {"Milk", "Dairy products", 30.0},
        {"Bread", "Bakery products", 20.5},
        {"Cheese", "Dairy products", 100.9},
        {"Carrot", "Vegetables", 50.5},
        {"Butter", "Dairy products", 120.5}
    };

    int productCount = 5; 

    
    cout << "\nExisting products:" << endl;
    printProducts(products, productCount);

    
    addProduct(products, productCount);

    
    cout << "\nUpdated product list:" << endl;
    printProducts(products, productCount);

    
    cout << "\nProducts in Dairy products category:" << endl;
    printProductsByCategory(products, productCount, "Dairy products");

    
    double maxPrice;
    cout << "\nEnter the maximum price to filter products: ";
    cin >> maxPrice;
    printProductsByPrice(products, productCount, maxPrice);

    
    int removeIndex;
    cout << "\nEnter the index of product to remove (0 to " << productCount-1 << "): ";
    cin >> removeIndex;
    removeProduct(products, productCount, removeIndex);

    
    cout << "\nProduct list after removal:" << endl;
    printProducts(products, productCount);

    return 0;
}
