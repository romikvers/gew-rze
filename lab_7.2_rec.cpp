// Написати програму, яка міняє місцями максимальний і мінімальний елементи
//кожного рядка матриці(k  n).Пояснити призначення змінних.

// Lab_7_2_rec.cpp
// Роман Кошів
// Лабораторна робота № 7.2_rec
// Опрацювання багатовимірних масивів рекурсивним способам.
// Варіант 14
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateRows(int** a, const int N, const int Low, const int High, int rowNo);
void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo);
void PrintRows(int** a, const int N, int rowNo);
void PrintRow(int** a, const int rowNo, const int N, int colNo);
void Second(int** a, const int rowCount, const int colCount, int rowNo, int MinIndex, int MaxIndex);
void Max(int** a, const int colCount, const int rowNo, int colNo, int max, int maxim, int& MaxIndex);
void Max1(int** a, const int colCount, const int rowNo, int colNo, int max, int& maxim, int& MaxIndex);
void MaxElemIndex(int colNo, int max, int& maxim, int& MaxIndex);
void Min(int** a, const int colCount, const int rowNo, int colNo, int min, int micro, int& MinIndex);
void Min1(int** a, const int colCount, const int rowNo, int colNo, int min, int& micro, int& MinIndex);
void MinElemIndex(int colNo, int min, int& micro, int& MinIndex);
void Change(int** a, const int rowNo, int MinIndex, int MaxIndex, int tmp);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int Count;
	cout << "rowCount and colCount = "; cin >> Count;
	int** a = new int* [Count];
	for (int i = 0; i < Count; i++)
		a[i] = new int[Count];
	CreateRows(a, Count, Low, High, 0);
	PrintRows(a, Count, 0);

	cout << "\nSwap :";
	cout << endl;
	Second(a, Count, Count, 0, 0, 0);
	PrintRows(a, Count, 0);

	cout << endl;
	cout << '\n';

	for (int i = 0; i < Count; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < N - 1)
		CreateRow(a, rowNo, N, Low, High, colNo + 1);
}
void CreateRows(int** a, const int N, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, N, Low, High, 0);
	if (rowNo < N - 1)
		CreateRows(a, N, Low, High, rowNo + 1);
}
void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < N - 1)
		PrintRow(a, rowNo, N, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int N, int rowNo)
{
	PrintRow(a, rowNo, N, 0);
	if (rowNo < N - 1)
		PrintRows(a, N, rowNo + 1);
	else
		cout << endl;
}
void Second(int** a, const int rowCount, const int colCount, int rowNo, int MinIndex, int MaxIndex)
{
    Min(a, colCount, rowNo, 0, 0, 0, MinIndex);
	Max(a, colCount, rowNo, 0, 0, 0, MaxIndex);
	Change(a, rowNo, MinIndex, MaxIndex, 0);
	if (rowNo < rowCount - 1)
	{
		Second(a, rowCount, colCount, rowNo + 1, 0, 0);
	}
}
void Min(int** a, const int colCount, const int rowNo, int colNo, int min, int micro, int& MinIndex)
{
	if (colNo == 0) {
		micro = a[rowNo][colNo];
	}
	if (colNo < colCount - 1) {
		Min1(a, colCount, rowNo, colNo, min, micro, MinIndex);
		Min(a, colCount, rowNo, colNo + 1, min, micro, MinIndex);
	}
}
void Min1(int** a, const int colCount, const int rowNo, int colNo, int min, int& micro, int& MinIndex)
{
	if (a[rowNo][colNo] > a[rowNo][colNo + 1]) {
		min = a[rowNo][colNo + 1];
		MinElemIndex(colNo, min, micro, MinIndex);
	}
}
void MinElemIndex(int colNo, int min, int& micro, int& MinIndex)
{
	if (min < micro) {
		micro = min;
		MinIndex = colNo + 1;
	}
}
void Max(int** a, const int colCount, const int rowNo, int colNo, int max, int maxim, int& MaxIndex)
{
	if (colNo == 0){
		maxim = a[rowNo][colNo];
	}
	if (colNo < colCount - 1) {
		Max1(a, colCount, rowNo, colNo, max, maxim, MaxIndex);
		Max(a, colCount, rowNo, colNo + 1, max, maxim, MaxIndex);
	}
}
void Max1(int** a, const int colCount, const int rowNo, int colNo, int max, int& maxim, int& MaxIndex)
{
	if (a[rowNo][colNo] < a[rowNo][colNo + 1]) {
		max = a[rowNo][colNo + 1];
		MaxElemIndex(colNo, max, maxim, MaxIndex);
	}
}
void MaxElemIndex(int colNo, int max, int& maxim, int& MaxIndex)
{
	if (max > maxim) {
		maxim = max;
		MaxIndex = colNo + 1;
	}
}
void Change(int** a, const int rowNo, int MinIndex, int MaxIndex, int tmp)
{
	tmp = a[rowNo][MinIndex];
	a[rowNo][MinIndex] = a[rowNo][MaxIndex];
	a[rowNo][MaxIndex] = tmp;
}