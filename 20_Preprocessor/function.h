#define FUNCTION_H

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


#define MIN(a, b) ((a) < (b) ? (a) : (b))   
#define MAX(a, b) ((a) > (b) ? (a) : (b))   
#define SQUARE(x) ((x) * (x))               
#define IS_EVEN(x) ((x) % 2 == 0)           


void FillArrayInt(int arr[], int size);
void ShowArrayInt(int arr[], int size);
int FindMaxInt(int arr[], int size);
void EditArrayInt(int arr[], int size);

void FillArrayDouble(double arr[], int size);
void ShowArrayDouble(double arr[], int size);
double FindMaxDouble(double arr[], int size);
void EditArrayDouble(double arr[], int size);

void FillArrayChar(char arr[], int size);
void ShowArrayChar(char arr[], int size);
char FindMaxChar(char arr[], int size);
void EditArrayChar(char arr[], int size);


#ifdef INTEGER
	#define FillArray FillArrayInt
	#define ShowArray ShowArrayInt
	#define FindMax FindMaxInt
	#define EditArray EditArrayInt
#elif defined(DOUBLE)
	#define FillArray FillArrayDouble
	#define ShowArray ShowArrayDouble
	#define FindMax FindMaxDouble
	#define EditArray EditArrayDouble
#elif defined(CHAR)
	#define FillArray FillArrayChar
	#define ShowArray ShowArrayChar
	#define FindMax FindMaxChar
	#define EditArray EditArrayChar
#endif


