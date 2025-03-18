
#include <iostream>
using namespace std;

int main()
{
    /*1.Дано три числа.Оголосити вказівники на ці числа.Отримати добуток трьох
        заданих чисел, середє арифметичне, найменше з них, користуючись
        непрямим доступом до чисел(через вказівники).*/

    int a = 5;
    int b = 10;
    int c = 15;

    int* pa = &a;
    int* pb = &b;
    int* pc = &c;

    int product = *pa * *pb * *pc;
    cout << "Product = " << product << endl;
    int mid = (*pa + *pb + *pc) / 3;
    cout << "Middle = " << mid << endl;
    int min;
    if (*pa<*pb&&*pa<*pc)
    {
        min = *pa;
    }
    else if (*pb<*pa&&*pb<*pc)
    {
        min = *pb;
    }
    else
    {
        min = *pc;
    }
    cout << "Min = " << min << endl;

    /*2.Дано цілочисельний одновимірний масив.Заповнити його,
        вивести на екран у прямому та зворотньому порядку та порахувати
        суму елементів з використанням вказівників.*/

    const int size = 5;
    int arr[size];
    int* p_arr = arr;
    cout << "Enter 5 numbers:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> *p_arr;
        p_arr++;
    }
    
    p_arr = arr;
    for (int i = 0; i < size; i++)
    {
        cout << *p_arr << " ";
        p_arr++;
    }
    p_arr--;
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << *p_arr << " ";
        p_arr--;
    }
    int sum = 0;
    p_arr = arr;
    for (int i = 0; i < size; i++)
    {
        sum += *p_arr;
        p_arr++;
    }
    cout << endl;

    cout << "Sum = " << sum << endl;

    /*3.Дано одновимірний масив.Знайти найбільше та найменше значення у
        масиві та поміняти їх у масиві місцями.Вивести перетворений масив на екран.*/

    const int size = 6;
    int arr[size] = { 20,30,70,50,10,40 };
    int* p_arr = arr;
    for (int i = 0; i < size; i++)
    {
        cout << *p_arr << " ";
        p_arr++;
    }
    cout << endl;
    p_arr = arr;
    int min = *p_arr;
    int* min_p = p_arr;
    int max = *p_arr;
    int* max_p = p_arr;


    for (int i = 1; i < size; i++)
    {
        if (*p_arr<min)
        {
            min = *p_arr;
            min_p = p_arr;
            
        }
        if (*p_arr>max)
        {
            max = *p_arr;
            max_p = p_arr;
        }
        p_arr++;
    }
    cout << "Min = " << min << endl;
    cout << "Max = " << max << endl;
    swap(*min_p, *max_p);

    p_arr = arr;
    for (int i = 0; i < size; i++)
    {
        cout << *p_arr << " ";
        p_arr++;
    }

    /*4.Дано масив цілих чисел.Користуючись вказівниками, поміняти місцями елементи
        масиву з парними и непарними індексами(тобто ті елементи масиву, які стоять
            на парних місцях, поміняти з елементами, які стоять на непарних місцях).*/

    const int size = 6;
    int arr[size] = { 10,20,30,40,50,60 };
    int* parr = arr;

    for (int i = 0; i < size; i++)
    {
        cout << *parr << " ";
        parr++;
    }
    cout << endl;

    
    parr = arr;
    for (int i = 0; i < size - 1; i += 2) 
    {
        int temp = *(parr + i);
        *(parr + i) = *(parr + i + 1);
        *(parr + i + 1) = temp;
    }
    cout << endl;
    parr = arr;
    for (int i = 0; i < size; i++)
    {
        cout << *parr << " ";
        parr++;
    }



}
