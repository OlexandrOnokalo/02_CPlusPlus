#include<iostream>

using namespace std;

void main() {

	//      class work assignment from the file FP_Practice_06_Цикли.pdf



	/*Завдання 1. Вивести на екран усі числа від нуля до введеного користувачем числа.*/



	/*int num;
	cout << "Enter number: " << endl;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		cout << i << " ";
	}*/




	/*Завдання 2. Користувач вводить дві межі діапазону, вивести на екран усі числа з цього діапазону.Передбачити,
		щоб користувач міг вводити межі діапазону в довільному
		порядку.
		■ вивести всі парні числа з діапазону.
		■ вивести всі непарні числа з діапазону.
		■ вивести всі числа, кратні семи.*/



	/*int a, b;
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
	}*/



	/*Завдання 3. Користувач вводить дві межі діапазону.Порахувати суму всіх чисел діапазону.*/




	/*int a, b, sum = 0;

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

	cout << "Sum of numbers is: " << sum << endl;*/




	/*Завдання 4. Користувач з клавіатури вводить числа.Порахувати їхню суму і вивести на екран, щойно користувач
		введе нуль.*/

	/*int num, sum = 0;

	for (; ; )
	{
		cout << "Enter numbers (0 for stop): ";
		cin >> num;

		if (num == 0) {
			break;
		}

		sum += num;
	}

	cout << "Summ: " << sum << endl;*/

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







}
