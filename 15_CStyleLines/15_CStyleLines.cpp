#include <iostream>
using namespace std;

int main()
{
	/*1.Вводиться рядок.Яких букв у рядку більше ’а’ чи ’о’ ?*/

	char txt[255];
	cout << "Enter text: " << endl;
	cin.getline(txt, 255);
	
	int ca = 0;
	int co = 0;
	for (int i = 0; i < strlen(txt); i++)
	{
		if (txt[i]=='a')
		{
			ca++;
		}
		if (txt[i]=='o')
		{
			co++;
		}
	}
	cout << "A = " << ca << endl;
	cout << "O = " << co << endl;
	if (ca>co)
	{
		cout << "O more then A" << endl;
	}
	if (co>ca)
	{

	}

}


