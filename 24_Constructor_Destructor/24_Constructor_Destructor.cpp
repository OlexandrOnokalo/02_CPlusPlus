
#include <iostream>
#include <Windows.h>
using namespace std;

    /*Завдання 1:
Створити клас Rectangle, який буде описувати прямокутник.Клас містить розміри : ширина, висота, символ, 
який відображатиме прямокутник на екрані та координати розміщення.
Для збереження координат створити структуру Coord, яка міститиме X та Y координату.
    Клас повинен містити наступні конструктори :
Конструктор по замовчуванню, який встановлюватиме «дефолтні» дані
Параметризований конструктор, який приймає один параметр «розмір» та ініціалізує ним ширину та висоту
Параметризований конструктор, який приймає два параметри «ширину» та «висоту», які являються розмірами об’єкта
    Та наступні методи :
Вивід фігури на екран, відповідного розміру, символом та у відповідних координатах
Зміна розміру прямокутника.Метод приймає два парметри : 1 – зміна висоти, 2 – ширини
Переміщення прямокутника.Метод приймає два парметри : 1 – величина 
переміщення по осі X, 2 – по осі Y
Методи повинні включати перевірку на коректність 
даних(від’ємна ширина, координати і тд).
Створити екземпляр об’єкту та протестувати написаті методи.*/

void SetPos(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

struct Coord {
    int x;
    int y;
};

class MyRectangle
{
private:
    int width;
    int height;
    char symbol;
    Coord coord;
public:
    MyRectangle()
    {
        width = 0;
        height = 0;
        symbol = '*';
        coord.x = 0;
        coord.y = 0;
    }
    MyRectangle(int size)
    {
        width = size;
        height = size;
        symbol = '*';
        coord.x = 0;
        coord.y = 0;
    }
    MyRectangle(int width, int height)
    {
        this->width = width;
        this->height = height;
        symbol = '*';
        coord.x = 0;
        coord.y = 0;
    }
    void print() {
        SetPos(coord.x, coord.y);
        if (width<=0 && height<=0)
        {
            cout << "Error! Width or heigth are <=0!";
        }
        else
        {
            for (int i = 0; i < height; i++)
            {
                SetPos(coord.x, coord.y+i);
                for (int j = 0; j < width; j++)
                {
                    cout << symbol;
                }
                cout << endl;
            }
        }
        
    }
    void changeSize(int width, int height) {
        if (width <= 0 && height <= 0)
        {
            cout << "Error! Width or heigth are <=0!";
        }
        else
        {
            this->width = width;
            this->height = height;
        }
        
    }
    void move(int x, int y) {
        if (x <= 0 && y <= 0)
        {
            cout << "Error! X or Y are <=0!";
        }
        else
        {
            coord.x = x;
            coord.y = y;
        }
        
    }


};






int main()
{
    MyRectangle rect;
    rect.move(5, 5);
    rect.changeSize(10, 10);
    rect.print();
    
}

