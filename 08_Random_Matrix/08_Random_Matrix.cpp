#include<iostream>
using namespace std;

void main() {

	
	/*1.Дано масив розміром 4×3 з елементами цілого типу.
	Визначити кількість елементів відмінних від нуля.*/

	srand(time(0));
    const int row = 5;
    const int col = 6;

    /*int count = 0;
    int array1[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            array1[i][j] = rand() % 4;
            cout << array1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (array1[i][j]!=0)
            {
                count++;
            }
            
        }
    }
    cout << "Count of non zero = " << count << endl;*/

    /*2.Дано масив розміром 3×3 з елементами цілого типу.
    Визначити кількість елементів які б дорівнювали нулю.*/

    /*int count = 0;
    int array1[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            array1[i][j] = rand() % 4;
            cout << array1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (array1[i][j] == 0)
            {
                count++;
            }

        }
    }
    cout << "Count of zero = " << count << endl;*/

    /*3.Дано масив розміром 7×3 з елементами цілого типу.
    Визначити кількість елементів, модуль яких менший 12. (-20 + rand() % 40)*/

    /*int count = 0;
    int arr[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = ((rand() % 40) - 20);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] > -12 && arr[i][j] < 12)
            {
                count++;
                cout << arr[i][j] << endl;
            }

        }
    }
    cout << "count of range -12 to 12 = " << count << endl;*/


    /*4.Дано масив розміром 4×5 з елементами цілого типу(позитивні та від’ємні).
    Визначити кількість позитивних елементів.*/

    /*int count = 0;
    int arr[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = ((rand() % 40) - 20);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] > 0)
            {
                count++;
                cout << arr[i][j] << endl;
            }

        }
    }
    cout << "count of positive = " << count << endl;*/

    /*5.Дано масив розміром 5×4 з елементами дійсного типу(додатні та від’ємні).
    Визначити добуток всіх додатніх елементів.*/

    
    /*int arr[row][col];
    int product = 1;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = ((rand() % 40) - 20);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] > 0)
            {
                product *= arr[i][j];
                cout << arr[i][j] << endl;
            }

        }
    }
    cout << "Product of pisitive = " << product << endl;*/

    /*6.Дано масив розміром 5×4 з елементами дійсного типу(позитивні та від’ємні).
        Визначити добуток всіх від’ємних елементів.*/

    /*int arr[row][col];
    int product = 1;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = ((rand() % 40) - 20);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] < 0)
            {
                product *= arr[i][j];
                cout << arr[i][j] << endl;
            }

        }
    }
    cout << "Product of negative = " << product << endl;*/

    /*7.Дано масив розміром 4×4 з елементами цілого типу.Визначити кількість
        елементів, які б при діленні на 6 давали залишок 1. 13 % 6 = 1*/

    /*int count = 0;
    int arr[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = ((rand() % 40) - 20);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] % 6 == 1)
            {
                count++;
                cout << arr[i][j] << endl;
            }

        }
    }
    cout << "count = " << count << endl;*/

    /*8.Дано масив розміром 5хб цілого типу.Знайти мінімальний елемент.*/

    /*int arr[row][col];
    int min;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = ((rand() % 40) - 20);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    min = arr[0][0];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }

        }
    }
    cout << "Minimum element = " << min << endl;*/

    /*9.Дано масив розміром 5×6 цілого типу.Знайти максимальний елемент.*/


    /*int arr[row][col];
    int max;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = ((rand() % 40) - 20);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    max = arr[0][0];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                
            }

        }
    }
    cout << "Maximum element = " << max << endl;*/

    /*10.Дано масив розміром 5×4 з елементами дійсного типу(позитивні та від’ємні).
        Визначити суму всіх від’ємних елементів.*/

    /*int arr[row][col];
    int sum = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = ((rand() % 40) - 20);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] < 0)
            {
                sum += arr[i][j];
                cout << arr[i][j] << endl;
            }

        }
    }
    cout << "Sum of negative = " << sum << endl;*/



}
