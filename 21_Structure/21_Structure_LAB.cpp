#include <iostream>
using namespace std;

struct rectangle 
{
	int height = 1;
	int width = 1;
};

void inputRectangle(rectangle & rec)
{
	cout << "Enter heigh : ";
	cin >> rec.height;
	if (rec.height <= 0) {
		cout << "Error input";
		return;
	}
	cout << "Enter width : ";
	cin >> rec.width;
	if (rec.width <= 0) {
		cout << "Error input";
		return;
	}

}

void changeHeigh(rectangle & rec)
{
	cout << "Enter heigh : ";
	cin >> rec.height;
	if (rec.height <= 0) {
		cout << "Error input";
		return;
	}

}

void changeWidth(rectangle& rec)
{
	cout << "Enter width : ";
	cin >> rec.width;
	if (rec.height <= 0) {
		cout << "Error input";
		return;
	}
}

void printRectangle(const rectangle& rec)
{
	cout << "\nHeigh : " << rec.height << endl;
	cout << "Width : " << rec.width << endl;
	cout << endl;
}

int area(const rectangle& rec) { return rec.height * rec.width; }

int perimeter(const rectangle& rec) { return (rec.height+rec.width)*2; }





	/*Завдання 2
Створіть структуру, що описує точку в двовимірній 
системі координат(x, y).За допомогою цієї структури 
задайте дві точки.Напишіть функцію, 
яка обчислює відстань між цими двома точками.*/

struct coordinates {
	int x = 0;
	int y = 0;
};

void inputCoordinates(coordinates& cor)
{
	cout << "Enter x : ";
	cin >> cor.x;

	cout << "Enter y : ";
	cin >> cor.y;
	
}

double distance(const coordinates& cor, const coordinates& cor2) {

	double dist;
	dist = sqrt(pow(cor2.x - cor.x, 2) + pow(cor2.y - cor.y, 2));
	return dist;

}



	/*Завдання 3
Створіть структуру, що описує простий дріб.Реалізуйте арифметичні 
операції з дробами : суму, різницю, множення, ділення.
Врахувати можливість скорочення дробів і 
переведення з неправильного дробу в простий.*/

struct fraction {
	int numerator = 0;
	int denominator = 0;
};


	/*завдання 4.
Дописати у задачу(демо Товар - Магазин) можливість   введення товару,*/


const int MAX_LEN = 20;

struct Product
{
	char name[MAX_LEN];
	double price;
};

void addProduct(Product product, Product shop[], int& actualSize, int maxSize)
{
	if (actualSize >= maxSize)
	{
		cout << "Shop is full!\n";
		return;
	}
	shop[actualSize] = product; // заносимо на місце після останнього Продукту новий продукт product
	++actualSize;
}

void printProduct(const Product& product)
{
	cout << "Product: '" << product.name << "', price: " << product.price << endl;
}

void printShop(const Product  shop[], int actualSize)
{
	for (int i = 0; i < actualSize; i++)
	{
		cout << "#" << i + 1 << "\t";
		printProduct(shop[i]);
	}
}

void printProducts(const Product shop[], int actualSize, const char* name)
{
	cout << "Products with name like '" << name << "'\n";
	for (int i = 0; i < actualSize; i++)
	{
		//if (_stricmp(name, shop[i].name) == 0) // чи співпадають рядки?
		if (strstr(shop[i].name, name) != nullptr) // чи name є частинрою назви товару shop[i].name
		{
			printProduct(shop[i]);
		}
	}
}






int main()
{
		/*rectangle rec{};
	cout << "Enter size of rectangle:" << endl;
	inputRectangle(rec);
	printRectangle(rec);
	cout << "Change rectangle:" << endl;
	changeHeigh(rec);
	changeWidth(rec);
	printRectangle(rec);
	cout << "Area = " << area(rec) << "\nPerimeter = " << perimeter(rec) << endl;*/

	/*coordinates cor1;
	coordinates cor2;
	cout << "Enter coordinates of point 1: " << endl;
	inputCoordinates(cor1);
	cout << "Enter coordinates of point 2: " << endl;
	inputCoordinates(cor2);
	cout << "Distance: " << distance(cor1, cor2) << endl;*/



}


