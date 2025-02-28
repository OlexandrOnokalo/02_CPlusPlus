#include<iostream>
using namespace std;

void main() {

	//      class work assignment from the file HW.txt


	/*1.Вивести на екран цілі числа від 1 до 100. - while*/

	int i = 1;
	while (i <= 100)
	{
		cout << i << endl;
		i++;
	}

	/*2.Вивести на екран додатні парні числа,
	які не перевищують 200, та їх кількість. - while*/

	int q = 1;
	while (q <= 200)
	{
		if (q % 2 == 0)
		{
			cout << q << endl;
		}
		q++;
	}

	/*3.Дано N(N > 0).Вводяться N чисел.
	Знайти суму парних серед цих чисел. - while*/

	int countnumber;//10
	cout << "Enter how many numbers to enter :";  cin >> countnumber;
	int i = 0;
	int number;
	int summa = 0;
	while (i < countnumber) {
		cout << "Enter : " << i + 1 << " number : ";
		cin >> number;
		if (number % 2 == 0) {
			summa += number;
		}
		i++;
	}
	cout << "Sum of even number =" << summa;

	/*4.Вводяться 10 чисел.Знайти суму
	та середнє арифметичне цих чисел. - while*/

	int i4 = 0;
	int number4;
	int summa4 = 0;
	int average4 = 0;
	while (i4 < 10)
	{
		cout << "Enter " << i4 + 1 << " number : ";
		cin >> number4;
		summa4 += number4;
		i4++;
	}
	average4 = summa4 / 10;
	cout << "Summa = " << summa4 << "; Average = " << average4 << endl;

	//5.Вивести на екран цілі числа : 100 99 98 97...3 2 1. - do..while

	int i = 100;

	do
	{
		cout << i << endl;
		i = i - 1;
	} while (i >= 1);

	/*6.Написати програму яка обчислює суму семи чисел, які вводяться з клавіатури. - do..while*/

	int i = 1, num = 0, sum = 0;
	do
	{
		cout << "Enter " << i << " number: " << endl;
		cin >> num;
		sum += num;
		i++;

	} while (i <= 7);
	cout << "Summ = " << sum << endl;



	//                        switch


	/*1. Дано країна.Вивести назву столиці. (5 countries)*/

	int key;
	cout << "Choose country : " << endl;
	cout << "[ 1 ] - Great Britain " << endl;
	cout << "[ 2 ] - Poland " << endl;
	cout << "[ 3 ] - Germany " << endl;
	cout << "[ 4 ] - USA " << endl;
	cout << "[ 5 ] - Canada " << endl;
	cin >> key;


	switch (key)
	{
	case 1:
		cout << "London is the capital of Great Britain X-D  ";
		break;
	case 2:
		cout << "Warsaw";
		break;
	case 3:
		cout << "Berlin";
		break;
	case 4:
		cout << "Washington, D.C.";
		break;
	case 5:
		cout << "Ottawa";
		break;
	default:
		cout << "Wrong choice";
		break;
	}

	//2.Дано номер дня тижня(1 – понеділок і т.д.).Визначити чи це вихідний день.

	int i;
	cout << "Enter number of a day:" << endl;
	cin >> i;
	switch (i)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		cout << "It's a working day" << endl;
		break;
	case 6:
	case 7:
		cout << "It's a day off" << endl;
		break;
	default:
		cout << "Wrong number" << endl;
		break;
	}

	/*3.Дано курс корабля(північ, південь, захід, схід).Як
		зміниться курс корабля після команди «назад» ?*/

	int key;
	cout << "Choose ship's course : " << endl;
	cout << "[ 1 ] - north " << endl;
	cout << "[ 2 ] - south " << endl;
	cout << "[ 3 ] - west " << endl;
	cout << "[ 4 ] - east " << endl;
	cin >> key;

	switch (key)
	{
	case 1:
		cout << "south";
		break;
	case 2:
		cout << "north";
		break;
	case 3:
		cout << "east";
		break;
	case 4:
		cout << "west";
		break;
	default:
		cout << "Wrong choice";
		break;
	}



	/*4.Дано тварина(номер тварини. 1 – жираф. 2 – орел.тощо). (7 animals)
		Вивести клас, до якого відноситься тварина(хижак, травоїдна).*/

	int key;
	cout << "Choose animal : " << endl;
	cout << "[ 1 ] - giraffe " << endl;
	cout << "[ 2 ] - lion " << endl;
	cout << "[ 3 ] - eagle " << endl;
	cout << "[ 4 ] - fallow deer " << endl;
	cout << "[ 5 ] - cow " << endl;
	cout << "[ 6 ] - crocodile " << endl;
	cout << "[ 7 ] - tiger " << endl;
	cin >> key;

	switch (key)
	{
	case 1: case 4: case 5:
		cout << "herbivore";
		break;
	case 2: case 3: case 6: case 7:
		cout << "predator";
		break;
	default:
		cout << "Wrong choice";
		break;
	}



	//      home work assignment from the file HWWhileFor.txt

	/*1.Вивести на екран цілі числа від 14 до 123. - while*/


	int i = 14;

	while (i <= 123)
	{
		cout << i << endl;
		i++;
	}

	/*2.Вивести на екран додатні непарні числа, які не перевищують 100. - while*/

	int i = 1;
	while (i <= 100)
	{
		if (i % 2 == 0)
		{
			cout << i << endl;
		}
		i++;
	}

	/*3.Дано N(N > 0).Вводяться N чисел.Знайти кількість від’ємних серед них. - while*/

	int countnumber;
	cout << "Enter how many numbers to enter :";  cin >> countnumber;
	int i = 0;
	int number;
	int count = 0;
	while (i < countnumber) {
		cout << "Enter : " << i + 1 << " number : ";
		cin >> number;
		if (number < 0)
		{
			count++;
		}
		i++;
	}
	cout << "Count of negative number = " << count;

	/*4.Вводяться 8 чисел.Знайти добуток та середнє арифметичне цих чисел. - while*/

	int i = 0;
	int number;
	int summa = 0;
	int dobutok = 1;
	int average = 0;
	while (i < 8)
	{
		cout << "Enter " << i + 1 << " number : ";
		cin >> number;
		summa += number;
		dobutok *= number;
		i++;
	}
	average = summa / 8;
	cout << "Dobutok = " << dobutok << "; Average = " << average << endl;

	/*5.Вивести на екран цілі непарні  числа : 100 98 96 94...4  2 1. - do..while*/

	int i = 100;

	while (i >= 1)
	{
		if (i % 2 == 0)
		{
			cout << i << endl;
		}
		i--;
	}

	/*6.Написати програму яка обчислює добуток п’яти чисел, які вводяться з клавіатури. - do..while*/

	int i = 1, num = 0, dobutok = 1;
	do
	{
		cout << "Enter " << i << " number: " << endl;
		cin >> num;
		dobutok *= num;
		i++;

	} while (i <= 5);
	cout << "Dobutok = " << dobutok << endl;




	//For extra points




/*7.Напишіть програму знаходження суми чисел менше 50 і кратних 4,
	використовуючи всі два типи циклів.*/

	int sum = 0;
	int num = 4;

	while (num < 50) {
		sum += num;
		num += 4;
	}

	cout << "Summ: " << sum << endl;


	///////////////////////////////

	int sum = 0;
	int num = 4;

	do {
		sum += num;
		num += 4;
	} while (num < 50);

	cout << "Summ: " << sum << endl;


	/*8. Вивести на екран усі числа від нуля до вве -
		деного користувачем числа.*/

	int num, i = 0;
	cout << "Enter number: " << endl;
	cin >> num;
	while (i <= num)
	{
		cout << i << endl;
		i++;
	}

	/*9. Користувач вводить дві межі діапазону, ви -
		вести на екран усі числа з цього діапазону.Передбачити,
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
	int i = a;
	while (i <= b) {
		cout << i << " " << endl;
		i++;
	}

	cout << "Even numbers: " << endl;
	i = a;
	while (i <= b) {
		if (i % 2 == 0) {
			cout << i << " " << endl;
		}
		i++;
	}

	cout << "Odd numbers: " << endl;
	i = a;
	while (i <= b) {
		if (i % 2 != 0) {
			cout << i << " " << endl;
		}
		i++;
	}

	cout << "Numbers divisible by 7: " << endl;
	i = a;
	while (i <= b) {
		if (i % 7 == 0) {
			cout << i << " " << endl;
		}
		i++;
	}

	/*10. Користувач вводить дві межі діапазону.По -
		рахувати суму всіх чисел діапазону.*/

	int a, b, sum = 0;

	cout << "Enter two range numbers: " << endl;
	cin >> a >> b;


	if (a > b)
	{
		swap(a, b);
	}


	while (a < b)
	{
		sum += a;
		a++;
	}

	cout << "Sum of numbers is: " << sum << endl;

	//11. Користувач з клавіатури вводить числа.По -
	//рахувати їхню суму і вивести на екран, щойно користувач
	//введе нуль.

	int num, sum = 0;


	while (true) {
		cout << "Enter numbers (0 for stop): ";
		cin >> num;

		if (num == 0) {
			break;
		}

		sum += num;
	}

	cout << "Summ: " << sum << endl;






}