	/*Використовуючи контейнер map реалізувати програму - словник.
Програма повинна у вигляді меню надавати наступні можливості :
-додати слово з перекладами;
-знайти переклади слова;
-додати переклад до існуючого слова;
-видалити слово разом зі всіма перекладами;
-показавати всі слова які наявні в словнику;
-*читання і запис словника в файл.

Для реалізації даного функціоналу, створити клас Dictionary
який містить
колекцію слів зі списком перекладів та всі необхідні методи.*/



#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;


class Dictionary
{
    string name;
    map<string, list<string>> dic;
public:
    void AddNewWord(string word, string value)
    {
		if (dic.find(word) != dic.end())
		{
			cout << "Word already exists!\n";
			return;
		}
		list<string> translations;
		string translate = "";
		do
		{
			cout << "Enter translation for " << word << ": ";
			getline(cin, translate);
			if (!translate.empty())
				translations.push_back(translate);
		} while (!translate.empty());
		dic[word] = translations;
    }




    void AddTranlate()
    {
        string input = "";
        cout << "Enter word to add translatins: "; getline(cin, input);

        if (dic.find(input) == dic.end())
            cout << "Word not found!\n";
        else
        {
            string translate = "";
            do
            {
                cout << "Enter translate: ";
                getline(cin, translate);
                dic[input].push_back(translate);

            } while (!translate.empty());
        }

        for (string item : dic[input])
        {
            cout << item << " ";
        }
    }

};
	








int main()
{

}

