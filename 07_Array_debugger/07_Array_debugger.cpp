#include<iostream>
using namespace std;

void main() 
{
	/*1.Оголосити одновимірний масив з 10 елементів типу int.
		Заповнити його значеннями з клавіатури, вивести на екран та
		підрахувати добуток елементів масиву*/

	const int size = 10;
	int arr[size];
	int product = 1;

	for (int i = 0; i < size; i++)
	{
		cout << "Enter " << i + 1 << " element ";
		cin >> arr[i];
		product *= arr[i];
	}
	
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Product of numbers: " << product << endl;

	/*2.Оголосити одновимірний масив з 7 елементів типу int.
		Заповнити його випадковими значеннями в діапазоні[-12.. + 50]
		та вивести на екран.
		Підрахувати кількість відємних та додатніх елементів масиву.*/

	const int size = 7;
	int arr[size] = { -9,-5,-7,8,5,2,1 };
	int positive = 0;
	int negative = 0;

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
		if (arr[i]<0)
		{
			negative++ ;
		}
		else
		{
			positive++;
		}
	}
	cout << "\nCount of negative: " << negative << endl;
	cout << "Cont of positive: " << positive << endl;

	/*3.Оголосити, проініціалізувати початковими значеннями та вивести
		одновимірний масив з 7 елементів типу long.Визначити суму парних елементів масиву*/

	const int size = 7;
	long arr[size] = { -9,-5,-7,8,5,2,1 };
	long sum = 0;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i]<<" ";
		if (arr[i]%2==0)
		{
			sum += arr[i];
		}
	}
	cout << "\nSumm of paired = " << sum << endl;

	/*4.Утворити одновимірний масив розміром 30.
		Заповнити його числами, які є степенями 2: (1, 2, 4, 8, 16, ...).
		Вивести елементи масиву на екран у прямому і оберненому порядку.*/

	const int size = 30;
	long long arr[size] = { 1 };
	for (int i = 1; i<size; i++)
	{
		arr[i] = arr[i - 1] * 2;
	}
	for (int i = 0; i < size; i++)
	{
		cout<< i<<" " << arr[i] << endl;
	}

	/*5.Дано одновимірний масив.Замінити всі від’ємні елементи їх модулями.
		if (arr[i] < 0) arr[i] = arr[i] * -1;*/

	const int size = 7;
	int arr[size] = { -9,-5,-7,8,5,2,1 };

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0) {
			arr[i] = arr[i] * -1;
		}
		cout << arr[i] << " ";
	}



	//      home work assignment from the file HW.txt


	/*1.Вивести на екран n одиниць, потім 2n двійок,
		потім 3n трійок.Число n вводить користувач.
		(Зробити вкладеним циклом одним)
		н = 5
		11111
		2222222222
		333333333333333*/

	int n;
	cout << "Enter n: ";
	cin >> n;

	for (int i = 1; i <= 3; i++) 
	{
		for (int j = 0; j < i * n; j++) 
		{
			cout << i;
		}
	
	}

	/*2..Виведіть на екран квадрат з нулів і одиниць,
		причому нулі знаходяться тільки на діагоналі квадрата.
		Всього в квадраті сто цифр.*/

	int N = 10;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
				cout << " 0";
			else
				cout << " 1";
		}
		cout << endl;
	}

	/*3.Вивести ряд чисел : десять десяток, дев'ять дев'яток,
	вісім вісімок, ..., одну одиницю.
	Знайти суму всіх цих чисел.*/

	int n = 10;
	int sum = 0;

	for (int i = n; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			cout << i << endl;
		}
	}

	/*4.Вивести на екран 15 рядків.У рядках з парними номерами
	вивести по 8 чисел, рівних номеру рядка.У рядках з
	непарними номерами вивести десять одиниць.*/

	int x = 15;
	int y = 10;
	int z = 8;

	for (int i = 1; i <= x; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < z; j++)
			{
				cout << i << " ";
			}
		}
		else
		{
			for (int j = 0; j < y; j++)
			{
				cout << 1 << " ";
			}
		}
		cout << endl;
	}

	/*5. Вивести 30 рядків.Непарні рядки містять натуральні числа
	від 1 до номера поточного рядка включно з кроком 1,
	парні рядки складаються з п'яти одиниць.*/

	int n = 30;
	int a = 5;

	for (int i = 1; i <= n; i++)
	{
		if (i%2!=0)
		{
			for (int j = 1; j <= i ; j++)
			{
				cout << j << " ";
			}
		}
		else
		{
			for (int i = 0; i < a; i++)
			{
				cout << 1 << " ";
			}
		}
		cout << endl;
	}

	/*6.Виведіть на екран таблицю множення для чисел від 1 до 10.*/

	int n = 10;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			cout << i << " * " << j << " = " << i * j << " ";
			cout << endl;
		}
		cout << endl;

	}


	/*7.Знайдіть кількість цілих чисел від a до b включно,
	які діляться на 12.*/

	int a;
	int b;
	int count = 0;
	cout << "Enter a,b:" << endl;
	cin >> a >> b;
	for (int i = a; i <= b; i++)
	{
		if (i%12==0)
		{
			count++;
		}
	}
	cout << "Counter: " << count << endl;

	/*8. Користувач вводить прибуток фірми за рік(12
	місяців).Потім користувач вводить діапазон(наприклад,
	3 і 6 — пошук між третім і шостим місяцем).Необхідно
	визначити місяць, у якому прибуток був максимальним, і
	місяць, у якому прибуток був мінімальним, з урахуванням
	обраного діапазону.*/

	const int size = 12;
	int arr[size];

	int a, b;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter " << i + 1 << " month profit: ";
		cin >> arr[i];
	}
	while (true)
	{
		cout << "Enter month range:" << endl;
		cin >> a >> b;
		if (a < 1 || a > 12 || b < 1 || b > 12)
		{
			cout << "Wrong number of the month." << endl;
		}
		else
			break;
	}
	if (a > b)
	{
		swap(a, b);
	}

	int min = arr[a - 1];
	int max = arr[a - 1];
	int maxindex = a;
	int minindex = a;
	for (int i = a; i <= b; i++)
	{
		if (arr[i - 1] > max)
		{
			max = arr[i - 1];
			maxindex = i;

		}
		if (arr[i - 1] < min)
		{
			min = arr[i - 1];
			minindex = i;
		}
	}
	cout << "Max month: " << maxindex << endl;
	cout << "Min month: " << minindex << endl;



	


}