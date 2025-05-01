#include <iostream>
#include "Vector.h"
using namespace std;

void main() {
    Vector vec;

    Point p1(10, 5);
    Point p2(15, 10);
    Point p3(20, 15);

    vec.AddPoint(p1);
    vec.AddPoint(p2);
    vec.AddPoint(p3);

    cout << "Vector contains the following points:" << endl;
    vec.Print();

    cout << "\nTesting operators:" << endl;
    p1++;
    p1.Show();

    p2--;
    p2.Show();

    cout << "p1 > p2: " << (p1 > p2 ? "true" : "false") << endl;
    cout << "p1 < p3: " << (p1 < p3 ? "true" : "false") << endl;

}
