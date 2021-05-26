//Написати програму, яка міняє місцями максимальний і мінімальний елементи
//кожного рядка матриці(k на n).Пояснити призначення змінних.

// Lab_7_2_1.cpp
// Роман Кошів
// Лабораторна робота № 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 14
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void Swap(int** a, const int rowCount, const int colCount);

int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 96;
	int n;
	cout << "rowCount and colCount = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, Low, High);
	Print(a, n);
	cout << "\nSwap ";
    Swap(a, n, n);
	Print(a, n);
	cout << endl;
	cout << '\n';

		for (int i = 0; i < n; i++)
			delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
void Swap(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		int max, min, tmp;
		tmp = 0;
		max = 0;
		min = 0;
		for (int j = 1; j < colCount; j++)
		{
			if (a[i][min] > a[i][j])
				min = j;
			else
 				  if (a[i][max] < a[i][j])
					  max = j;
 		}
		tmp = a[i][min];
		a[i][min] = a[i][max];
		a[i][max] = tmp;
	}
}