#include <iostream>
#include <cstring>
using namespace std;


        //Лабораторна робота


int countSentence(char str[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (str[i] == '.' || str[i] == '!')
        {
            count++;
        }
    }
    return  count;

}




void main()
{
    
    //Лабораторна робота

    /*const int size = 100;
    char str[size];
    char strcopy[size];
    cout << "Enter a string: ";
    cin.getline(str, 100);
    cout << "Count of sentences is: " << countSentence(str, size) << endl;*/
    

        /*Ввести кількість слів. Потім ввести самі слова, обєднати  слова у новий рядок, розділити слова комою (чи іншим символом) у цьому новому рядку*/

    /*const int size = 255;
    const int leng = 10;
    int count;
    char text[size] = {};
    cout << "Enter how many words: ";
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        char word[leng] = {};
        cout << "Enter " << i+1 << " word: ";
        cin >> word;
        strcat_s(text, word);
        if (i<count-1)
        {
            strcat_s(text, ", ");
        }
    }
    
    cout << text << endl;*/

        /*Завдання 2. Дано текст та символ(ввести з клавіатури).Порахувати кількість входжень цього символа у рядку. (strchr)*/

    /*const int size = 255;
    char text[size] = {};
    char symbol;
    int count = 0;
    cout << "Enter text: " << endl;
    cin.getline(text, 255);
    cout << "Enter symbol: " << endl;
    cin >> symbol;
    char* p = strchr(text, symbol);
    while (p!= nullptr)
    {
        p = strchr(p + 1, symbol);
        count++;
    }
    cout << count << endl;*/
    




    /*Завдання 3. Дано текст та два символи(ввести з клавіатури).Замінити у тексті один символ на інший.
        * *Зробити це не більше чим N разів*/


    const int size = 255;
    char text[size] = {};
    char symbol1;
    char symbol2;
    int times;
    int count = 0;
    cout << "Enter text: " << endl;
    cin.getline(text, 255);
    cout << "Enter symbol1: " << endl;
    cin >> symbol1;
    cout << "Enter symbol2: " << endl;
    cin >> symbol2;
    cout << "Enter how many times: " << endl;
    cin >> times;
    char* p = strchr(text, symbol1);
    while (p != nullptr && count<times)
    {
        *p = symbol2;
        p = strchr(p + 1, symbol1);
        count++;
    }
    cout << text << endl;









}

