// lab_7.3(2)_iter.cpp :
/*
Знайти номер останнього із стовпчиків, що містить найбільшу кількість нульових
елементів(оформити у вигляді int - функції).
*/

#include <iostream>
#include <iomanip>
#include <time.h>
#include <locale>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void SuchNommer(int** a, const int rowCount, const int colCount, bool& result);

int main()
{
	setlocale(LC_ALL, "rus");
	srand((unsigned)time(NULL));
	int Low = -17;
	int High = 15;
	int rowCount, colCount;
	cout << "colCount : "; cin >> colCount;
	cout << "rowCount : "; cin >> rowCount;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);

	bool result = false;
	SuchNommer(a, rowCount, colCount, result);
	Print(a, rowCount, colCount);
	cout << endl;


	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}
void SuchNommer(int** a, const int rowCount, const int colCount, bool& result)
{
	int rowNo, zahl = 0, MaxZero = 1, colNommer = 0;
	for (int colNo = 0; colNo < colCount; colNo++)
	{
		for (rowNo = 0; rowNo < rowCount; rowNo++)
		{
			if (a[rowNo][colNo] == 0)
			{
				zahl++;
			}
		}
		if (zahl != 0)
		{
			result = true;
			if (MaxZero <= zahl)
			{
				MaxZero = zahl;
				colNommer = colNo;
			}
		}
		zahl = 0;
	}
	if (result == true)
	{
		cout << "Найбiльша кiлькiсть нулiв : " << MaxZero << ", у стовпцi пiд номер : " << colNommer + 1;
	}
	else 
		cout << "Матриця не мiстить жодного нуля!";
}
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}