#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
using namespace std;

const int SIZE = 100;

struct Boiler {
    char company[SIZE];
    char color[SIZE];
    double power;
    double volume;
    double temperature;
};


struct Fraction {
    int numerator;
    int denominator;
};


struct Product {
    char name[SIZE];
    char category[SIZE];
    double price;
};


void inputBoiler(Boiler& b);
void printBoiler(const Boiler& b);
void increaseTemperature(Boiler& b, double temp);
void decreaseTemperature(Boiler& b, double temp);
bool compareBoilers(const Boiler& b1, const Boiler& b2);

void inputFraction(Fraction& f);
void printFraction(const Fraction& f);
Fraction add(const Fraction& one, const Fraction& two);
Fraction subtract(const Fraction& one, const Fraction& two);
Fraction multiply(const Fraction& one, const Fraction& two);
Fraction divide(const Fraction& one, const Fraction& two);
void testArithmeticOperations(const Fraction& f1, const Fraction& f2, char op);

void addProduct(Product products[], int& count);
void printProducts(const Product products[], int count);
void printProductsByCategory(const Product products[], int count, const char* category);
void printProductsByPrice(const Product products[], int count, double maxPrice);
void removeProduct(Product products[], int& count, int index);

#endif