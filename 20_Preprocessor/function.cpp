#include "function.h"

void FillArrayInt(int arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void ShowArrayInt(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int FindMaxInt(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void EditArrayInt(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] += 5;
    }
}

void FillArrayDouble(double arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 100) / 10.0;
    }
}

void ShowArrayDouble(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

double FindMaxDouble(double arr[], int size) {
    double max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void EditArrayDouble(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] += 0.5;
    }
}

void FillArrayChar(char arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = 'A' + rand() % 26;
    }
}

void ShowArrayChar(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

char FindMaxChar(char arr[], int size) {
    char max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void EditArrayChar(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (arr[i] == 'Z') ? 'A' : arr[i] + 1;
    }
}