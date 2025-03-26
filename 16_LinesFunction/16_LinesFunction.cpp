#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

        /*Завдання 1.
Дано текст та символ(ввести з клавіатури).
Порахувати кількість входжень цього символа у рядку. (strchr)*/

void task1() {
    cout << "Task 1" << endl;
    char text[256], symbol;
    cout << "Enter text: ";
    cin.getline(text, 256);
    cout << "Enter char: ";
    cin >> symbol;
    cin.ignore();

    int count = 0;
    char* ptr = strchr(text, symbol); 
    while (ptr) { 
        count++;  
        ptr = strchr(ptr + 1, symbol); 
    }

    cout << "Counter: " << count << endl;
}

        /*Завдання 2.
Дано текст та два символи(ввести з клавіатури).
Замінити у тексті один символ на інший. (strchr)
* *Зробити це не більше чим N разів*/

void task2() {
    cout << "Task 2" << endl;
    char text[256], oldChar, newChar;
    int maxReplacements;
    cout << "Enter text: ";
    cin.getline(text, 256);
    cout << "Enter old char: ";
    cin >> oldChar;
    cout << "Enter new char: ";
    cin >> newChar;
    cout << "Enter max replacements: ";
    cin >> maxReplacements;
    cin.ignore();

    int count = 0;
    char* ptr = strchr(text, oldChar); 
    while (ptr && count < maxReplacements) { 
        *ptr = newChar; 
        count++;  
        ptr = strchr(ptr + 1, oldChar); 
    }

    cout << "Resault: " << text << endl;
}

        /*Завдання 3.
Вводиться послідовність N слів(N вводиться з клавіатури).Об'єднати у окремий рядок слова, що  починаються та закінчуються на однакову букву.
strcat, strlen()*/

void task3() {
    cout << "Task 3" << endl;
    int N;
    cout << "Enter number of words: ";
    cin >> N;
    cin.ignore(); 

    char word[50];
    char result[256] = "";

    for (int i = 0; i < N; ++i) {
        cout << "Enter word: ";
        cin.getline(word, 50);

        int len = strlen(word);
        if (len > 0 && word[0] == word[len - 1]) {
            if (strlen(result) > 0) {
                strcat(result, " ");
            }
            strcat(result, word);
        }
    }

    cout << "Result: " << result << endl;
}





            /*Завдання 4.
Ввести  послідовність слів до зустрічі слова "stop".Порахувати число введених  слів.
Записати у окремий рядок слова, що починаються із певного сполучення букв.
Наприклад, вводиться сполучення букв "for" та вводяться слова
for
fear
forget
forgive
rfor
stop
Число слів = 5
Рядок із  словами, що починаються на  'for' = 'for forget forgive'
strcmp(), strcat(), strstr()*/

void task4() {
    cout << "Task 4" << endl;
    char prefix[50], word[50], result[256] = "";
    int wordCount = 0;

    cout << "Enter prefix: ";
    cin >> prefix;
    cin.get(); 

    while (true) {
        cout << "Enter word: ";
        cin.getline(word, 50);

        if (strcmp(word, "stop") == 0) {
            break;
        }
        wordCount++;

        if (strstr(word, prefix) == word) { 
            if (strlen(result) > 0) {
                strcat_s(result, " ");
            }
            strcat_s(result, word);
        }
    }

    cout << "Count: " << wordCount << endl;
    cout << "Result: " << result << endl;
}



        /*Додаткові завдання.*/



        /*Завдання 5.
Дано текст та два слова(фрагменти) однакової довжини.
Замінити у тексті одне слово на інше. (strstr, strncpy)
Порахувати число виконаних замін.*/

void task5() {
    cout << "Task 5" << endl;
    char text[256], oldWord[50], newWord[50];
    cout << "Enter text: ";
    cin.get(); 
    cin.getline(text, 256);
    cout << "Enter old word: ";
    cin >> oldWord;
    cout << "Enter new word: ";
    cin >> newWord;
    cin.ignore();

    int count = 0;
    char* ptr = strstr(text, oldWord); 
    while (ptr) {
        memcpy(ptr, newWord, strlen(oldWord)); 
        count++;
        ptr = strstr(ptr + strlen(oldWord), oldWord); 
    }

    cout << "Modified text: " << text << endl;
    cout << "Replacements made: " << count << endl;
}

        /*Завдання 6.
Порахуйте скільки разів цифри зустрічаються в тексті.
strchr або strpbrk(рядок, набір цифр)*/

void task6() {
    cout << "Task 6" << endl;
    char text[256];
    cout << "Enter text: ";
    cin.get(); 
    cin.getline(text, 256);

    int count = 0;
    char digits[] = "0123456789";
    char* ptr = strpbrk(text, digits); 
    while (ptr) {
        count++;
        ptr = strpbrk(ptr + 1, digits); 
    }

    cout << "Digit count: " << count << endl;
}


int main() {
    task1();
    task2(); 
    task3(); 
    task4(); 
    task5(); 
    task6(); 

    return 0;
}
