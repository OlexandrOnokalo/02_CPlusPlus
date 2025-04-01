#define CHAR 
#include "function.h"

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "Min: " << MIN(a, b) << endl;
    cout << "Max: " << MAX(a, b) << endl;
    cout << "Square of " << a << ": " << SQUARE(a) << endl;
    cout << "Square of " << b << ": " << SQUARE(b) << endl;

    cout << a << (IS_EVEN(a) ? " is even" : " is odd") << endl;
    cout << b << (IS_EVEN(b) ? " is even" : " is odd") << endl;

    const int size = 10;
    char arr[size];
    FillArray(arr, size);
    cout << "Array: ";
    ShowArray(arr, size);
    cout << "Max element: " << FindMax(arr, size) << endl;
    EditArray(arr, size);
    cout << "Edited Array: ";
    ShowArray(arr, size);

    return 0;
}