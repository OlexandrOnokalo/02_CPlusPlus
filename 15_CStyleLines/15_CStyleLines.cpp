#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cctype>
#include <cstring>

using namespace std;


//1.Вводиться рядок.Яких букв у рядку більше ’а’ чи ’о’ ?

void countAandO(char str[]) {
    int countA = 0, countO = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a' || str[i] == 'A') countA++;
        if (str[i] == 'o' || str[i] == 'O') countO++;
    }
    cout << "More: " << (countA > countO ? "a" : "o") << endl;
}


//2.Вводиться рядок.Порахувати кількість латинських букв, цифр та пробілів у рядку.

void countCharacters(char str[]) {
    int letters = 0, digits = 0, spaces = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) letters++;
        if (isdigit(str[i])) digits++;
        if (isspace(str[i])) spaces++;
    }
    cout << "Letters: " << letters << ", digits: " << digits << ", spaces: " << spaces << endl;
}

//3.Дано рядок.Замінити у рядку всі великі букви на малі і навпаки.

void swapCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i])) str[i] = toupper(str[i]);
        else if (isupper(str[i])) str[i] = tolower(str[i]);
    }
    cout << "Resaut line: " << str << endl;
}

//4.Написати функцію, яка отримує рядок і повертає довжину рядка.
//Без використання функції strlen()

int getLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

//5 * **.Дано рядок.Видалити із рядка заданий символ.Результат розмістити у новому рядку.

void removeCharacter(char str[], char ch) {
    char newStr[100] = "";
    int index = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ch) {
            newStr[index++] = str[i];
        }
    }
    newStr[index] = '\0';
    cout << "Line after remove : " << newStr << endl;
}


    /*6 * **.Розробити програму, яка зчитує з екрану рядок, а потім видає статистику :
кількість пробільних символів(whitespaces), голосних, приголосних, знаків пунктуації.
Введення передбачається англомовним.*/

void analyzeText(char str[]) {
    int spaces = 0, vowels = 0, consonants = 0, punctuation = 0;
    char vowelsList[] = "aeiouAEIOU";
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) spaces++;
        else if (isalpha(str[i])) {
            if (strchr(vowelsList, str[i])) vowels++;
            else consonants++;
        }
        else if (ispunct(str[i])) punctuation++;
    }
    cout << "Spaces: " << spaces << ", Vowels: " << vowels << ", Consonants: " << consonants << ", Punctuation: " << punctuation << endl;
}

void main() {
    
    /*1.Вводиться рядок.Яких букв у рядку більше ’а’ чи ’о’ ?*/

    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);
    countAandO(str);

    /*2.Вводиться рядок.Порахувати кількість латинських букв, цифр та пробілів у рядку.*/
    countCharacters(str);

    /*3.Дано рядок.Замінити у рядку всі великі букви на малі і навпаки.*/
    swapCase(str);

    /*4.Написати функцію, яка отримує рядок і повертає довжину рядка.
        Без використання функції strlen()*/
    cout << "String length: " << getLength(str) << endl;

    /*5 * **.Дано рядок.Видалити із рядка заданий символ.Результат розмістити у новому рядку.*/
    char ch;
    cout << "Enter character to remove: ";
    cin >> ch;
    removeCharacter(str, ch);
    cin.ignore();

    /*6 * **.Розробити програму, яка зчитує з екрану рядок, а потім видає статистику :
    кількість пробільних символів(whitespaces), голосних, приголосних, знаків пунктуації.
        Введення передбачається англомовним.*/

    cout << "Enter a new string for analysis: ";
    cin.getline(str, 100);
    analyzeText(str);

    
}
