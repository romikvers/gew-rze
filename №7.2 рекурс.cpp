//Написати програму, яка міняє місцями максимальний і мінімальний елементи
//кожного рядка матриці(k  n).Пояснити призначення змінних.

// Lab_7_2_1.cpp
// Роман Кошів
// Лабораторна робота № 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 14
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateRows(int** a, const int n, const int Low, const int High, int rowNo);
void CreatRow(int** a, const int colCount, const int Low, const int High, int rowNo, int colNo);
void PrintRows(int** a, const int n, int rowNo);
void PrintRow(int** a, const int n, int rowNo, int colNo);
//void Swap(int** a, const int rowCount, const int colCount, int i, int j, int max, int min);
void First(int** a, const int rowCount, int i);
void Second(int** a, const int rowCount, const int colCount, int i, int j, int min, int max);
int Min(int** a, int i, int j, int& min);
int Max(int** a, int i, int j, int& max);
void Change(int** a, int min, int max, int i, int tmp);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int n;
	cout << "rowCount and colCount = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	CreateRows(a, n, 7, 65, 0);
	PrintRows(a, n, 0);

	cout << "\nSwap ";
	Second(a, n, n, 0, 1, 0, 0);
	PrintRows(a, n, 0);
	cout << endl;
	cout << '\n';

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void CreateRows(int** a, const int n, const int Low, const int High, int rowNo)
{
	CreatRow(a, n, Low, High, rowNo, 0);
	if (rowNo < n - 1)
		CreateRows(a, n, Low, High, rowNo + 1);
}
void CreatRow(int** a, const int colCount, const int Low, const int High, int rowNo, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < colCount - 1)
	CreatRow(a, colCount, Low, High, rowNo, colNo + 1);
}
void PrintRows(int** a, const int n, int rowNo)
{
	PrintRow(a, n, rowNo, 0);
	if (rowNo < n - 1)
		PrintRows(a, n, rowNo + 1);
	else
		cout << endl;
}
void PrintRow(int** a, const int n, int rowNo, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < n - 1)
		PrintRow(a, n, rowNo, colNo + 1);
	else
		cout << endl;
}
void First(int** a, const int rowCount, int rowNo)
{
	if (rowNo < rowCount)
		rowNo++;
}
void Second(int** a, const int rowCount, const int colCount, int i, int j, int min, int max)
{
	min = Min(a, i, j, min);
	 
    max = Max(a, i, j, min);
	cout << "min" << min << endl;
	cout << "max" << max << endl;

	Change(a, min, max, i, 0);
	if (i < rowCount - 1)
		First(a, rowCount, i);
	if (j < colCount - 1)
		Second(a, rowCount, colCount, i, j + 1, min, max);
}
int Min(int** a, int i, int j, int& min)
{
	if (a[i][min] > a[i][j])
	{
		min = j;
	}
		 return min;
}
int Max(int** a, int i, int j, int& max)
{
	if (a[i][max] < a[i][j])
	{
		max = j;
    }
	return max;
}
void Change(int** a, int min, int max, int i, int tmp)
{
	tmp = a[i][min];
	a[i][min] = a[i][max];
	a[i][max] = tmp;

	cout << "Tmp : " << tmp << endl;
}
/*void Swap(int** a, const int rowCount, const int colCount, int i, int j, int max, int min)
{
	if (j < colCount)
		Second(a, colCount, i, j, min, max);
	else
		cout << endl;
	//	if (i < rowCount)
			//First(a, rowCount, i);
}
/*void Swap(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		int max, min, tmp;
		tmp = 0;
		max = 0;
		min = 0;
		for (int j = 0; j < colCount; j++)
		{
			if (a[i][min] <= a[i][j])
				min = j;
			else
				if (a[i][max] <= a[i][j])
					max = j;
		}
		tmp = a[i][min];
		a[i][min] = a[i][max];
		a[i][max] = tmp;
	}
}*/