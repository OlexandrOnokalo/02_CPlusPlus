#include<iostream>

using namespace std;

void main() {

	//      class work assignment from the file FP_Practice_06_Цикли.pdf



	/*Завдання 1. Вивести на екран усі числа від нуля до введеного користувачем числа.*/



	int num;
	cout << "Enter number: " << endl;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		cout << i << " ";
	}




	/*Завдання 2. Користувач вводить дві межі діапазону, вивести на екран усі числа з цього діапазону.Передбачити,
		щоб користувач міг вводити межі діапазону в довільному
		порядку.
		■ вивести всі парні числа з діапазону.
		■ вивести всі непарні числа з діапазону.
		■ вивести всі числа, кратні семи.*/



	int a, b;
	cout << "Enter two range numbers: " << endl;
	cin >> a >> b;


	if (a > b) {
		swap(a, b);
	}

	cout << "All numbers in the range: " << endl;
	for (int i = a; i <=b ; i++)
	{
		cout << i << " " ;
	}

	cout << "\nEven numbers: " << endl;
	for (int i = a; i <= b; i++)
	{
		if (i % 2 == 0) {
			cout << i << " ";
		}
	}

	cout << "\nOdd numbers: " << endl;
	for (int i = a; i <= b; i++)
	{
		if (i % 2 == 0) {
			cout << i << " ";
		}
	}



	/*Завдання 3. Користувач вводить дві межі діапазону.Порахувати суму всіх чисел діапазону.*/




	int a, b, sum = 0;

	cout << "Enter two range numbers: " << endl;
	cin >> a >> b;


	if (a > b)
	{
		swap(a, b);
	}

	for (int i = a; i <= b; i++)
	{
		sum += i;
	}

	cout << "Sum of numbers is: " << sum << endl;




	/*Завдання 4. Користувач з клавіатури вводить числа.Порахувати їхню суму і вивести на екран, щойно користувач
		введе нуль.*/

	int num, sum = 0;

	for (; ; )
	{
		cout << "Enter numbers (0 for stop): ";
		cin >> num;

		if (num == 0) {
			break;
		}

		sum += num;
	}

	cout << "Summ: " << sum << endl;




	/*Завдання 1. Написати гру «Вгадай число».Програма
	загадує число в діапазоні від 1 до 500. Користувач намагається його вгадати.Після кожної спроби програма
	видає підказки, чи його число є більшим або меншим за
	задумане.У кінці програма видає статистику : за скільки
	спроб угадано число, скільки часу це зайняло.Передбачити вихід за допомогою 0, у разі, якщо користувачеві
	набридло вгадувати число.*/

	int random = 271;
	int number;
	int i = 0;

	for (; ;)
	{
		cout << "Enter number: " << endl;
		cin >> number;
		if (number==random)
		{
			cout << "You win" << endl;
			i++;
			break;
		}
		else if (number>random)
		{
			cout << "Number to big" << endl;
			i++;
		}
		else if (number<random)
		{
			cout << "Number is small" << endl;
			i++;
		}
		else if (number==0)
		{
			cout << "Good bye!" << endl;
			i++;
			break;
		}
	
	}
	
	cout << "Counter: " << i << endl;


	/*Завдання 2. Написати програму — конвертер валют.Реалізувати спілкування з користувачем через меню.*/

	float UAH;
	float USD;
	int choise;

	for (; ; )
	{
		cout << "[1] - UAH to USD"<<endl;
		cout << "[2] - USD to UAH" << endl;
		cout << "[0] - Exit" << endl;
		cin >> choise;
		if (choise == 1)
		{
			cout << "Enter quantity" << endl;
			cin >> UAH;
			USD = UAH / 42;
			cout << "It is " << USD << " USD." << endl;
		}
		else if (choise ==2)
		{
			cout << "Enter quantity" << endl;
			cin >> USD;
			UAH = USD * 42;
			cout << "It is " << UAH << " UAH." << endl;
		}
		else if (choise ==0)
		{
			cout << "Good bye!" << endl;
			break;
		}
		else
		{
			cout << "Wrong choise." << endl;
		}

	}




	//      home work assignment from the file FP_HW_07_Цикли.pdf


	/*Завдання 1. Вивести на екран фігури, заповнені зірочками.Діалог з користувачем реалізувати за допомогою меню.*/

	int choise, N = 21;
		
	for (; ; )
	{
		cout << "[1] - figure 1." << endl;
		cout << "[2] - figure 2." << endl;
		cout << "[3] - figure 3." << endl;
		cout << "[4] - figure 4." << endl;
		cout << "[5] - figure 5." << endl;
		cout << "[6] - figure 6." << endl;
		cout << "[7] - figure 7." << endl;
		cout << "[8] - figure 8." << endl;
		cout << "[9] - figure 9." << endl;
		cout << "[10] - figure 10." << endl;
		cout << "[0] - Exit." << endl;
		cin >> choise;

		if (choise == 1)
		{
			cout << "1" << endl;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (i <= j)
						cout << " *";
					else
						cout << "  ";
				}
				cout << endl;
			}
			cout << endl;
		}

		else if (choise == 2)
		{
			cout << "2" << endl;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (i >= j)
						cout << " *";
					else
						cout << "  ";
				}
				cout << endl;
			}
			cout << endl;
		}

		else if (choise == 3)
		{
			cout << "3" << endl;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (i <= j && i + j <= N - 1)
						cout << " *";
					else
						cout << "  ";
				}
				cout << endl;
			}
			cout << endl;
		}

		else if (choise == 4)
		{
			cout << "4" << endl;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (i >= j && i + j >= N - 1)
						cout << " *";
					else
						cout << "  ";
				}
				cout << endl;
			}
			cout << endl;
		}

		else if (choise == 5)
		{
			cout << "5" << endl;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (i >= j && i + j >= N - 1 || i <= j && i + j <= N - 1)
						cout << " *";
					else
						cout << "  ";
				}
				cout << endl;
			}
			cout << endl;
		}

		else if (choise == 6)
		{
			cout << "6" << endl;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (i <= j && i + j >= N - 1 || i >= j && i + j <= N - 1)
						cout << " *";
					else
						cout << "  ";
				}
				cout << endl;
			}
			cout << endl;
		}

		else if (choise == 7)
		{
			cout << "7" << endl;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (i >= j && i + j <= N - 1)
						cout << " *";
					else
						cout << "  ";
				}
				cout << endl;
			}
			cout << endl;
		}

		else if (choise == 8)
		{
			cout << "8" << endl;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (i <= j && i + j >= N - 1)
						cout << " *";
					else
						cout << "  ";
				}
				cout << endl;
			}
			cout << endl;
		}

		else if (choise == 9)
		{
			cout << "9" << endl;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (i + j <= N - 1)
						cout << " *";
					else
						cout << "  ";
				}
				cout << endl;
			}
			cout << endl;
		}

		else if (choise == 10)
		{
			cout << "10" << endl;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (i + j >= N - 1)
						cout << " *";
					else
						cout << "  ";
				}
				cout << endl;
			}
			cout << endl;
		}


		else if (choise == 0)
		{
			cout << "Good bye!" << endl;
			break;
		}
		else
		{
			cout << "Wrong choise." << endl;
		}

	}


}
