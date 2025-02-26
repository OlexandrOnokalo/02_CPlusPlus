#include<iostream>
using namespace std;

void main()
{
	/*1.Дано сторони трикутника.
	Визначити якого вигляду це трикутник(рівносторонній, 
	рівнобедрений, прямокутний).*/
	float n1, n2, n3;
	cout << "Enter first side: " << endl;
	cin >> n1;
	cout << "Enter second side: " << endl;
	cin >> n2;
	cout << "Enter third side: " << endl;
	cin >> n3;
	if (n1==n2==n3)
	{
		cout << "Tkikutnuk rivnostoronnij" << endl;
	}
	else if ((n1==n2)||(n2==n3)||(n1==n3))
	{
		cout << "Tkikutnuk rivnobedrenij" << endl;
	}
	else if ((n1*n1==n2*n2+n3*n3)||(n2*n2==n1*n1+n3*n3)||(n3*n3==n1*n1+n2*n2))
	{
		cout << "Tkikutnuk priamokytnij" << endl;
	}
	else
	{
		cout << "Tkikutnuk ne rivnostoronnij, ne rivnobedrenij, ne priamokytnij" << endl;
	}
	system("pause");
	/*2.Дано розміри цегли і отвору у стіні.
		Визначити чи цегла пройде у отвір*/

	float h1, w1, h2, w2;
	cout << "Enter heigth of the hole: " << endl;
	cin >> h1;
	cout << "Enter width of the hole: " << endl;
	cin >> w1;
	cout << "Enter heigth of the brick: " << endl;
	cin >> h2;
	cout << "Enter width of the brick: " << endl;
	cin >> w2;
	if ((h1>h2) && (w1>w2))
	{
		cout << "Brick fit the hole" << endl;
	}
	else
	{
		cout << "Brick will not fit the hole" << endl;
	}
	system("pause");

	/*3.Дано 3 числа.Визначити 
		чи є серед них додатні.*/
	float a, b, c;
	cout << "Enter first number: " << endl;
	cin >> a;
	cout << "Enter second number: " << endl;
	cin >> b;
	cout << "Enter third number: " << endl;
	cin >> c;
	if (a>0)
	{
		cout << "First nuumber is dodatne 8-D " << endl;
	}
	if (b > 0)
	{
		cout << "Second nuumber is dodatne 8-D " << endl;
	}
	if (c > 0)
	{
		cout << "Third nuumber is dodatne 8-D " << endl;
	}
	else
	{
		cout << "There is no dodanti numbers" << endl;
	}

}


