
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
   
    for (int i = 0; i < size; i++)
    {
        cout << *p_arr << " ";
        p_arr--;
    }




}
