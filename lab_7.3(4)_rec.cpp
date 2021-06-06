// lab_7.3(4)_rec.cpp :

/*
Знайти номер останнього із стовпчиків, що містить найбільшу кількість нульових
елементів(оформити у вигляді int - функції).
*/

#include <iostream>
#include <iomanip>
#include <time.h>
#include <locale>

using namespace std;

void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo);
void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo);
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo);
void PrintRow(int** a, const int rowNo, const int colCount, int colNo);
void SuchNommerS(int** a, const int rowCount, const int colCount, int colNo, int& MaxZero, int& colNummer, bool& result);
void SuchLevel1(int** a, const int rowCount, const int colCount, int rowNo, int colNo, int& MaxZero, int& colNummer, int zahl, bool& result);
void CompareZero(int** a, const int rowCount, const int colCount, const int rowNo, const int colNo, int& MaxZero, int& colNummer, int zahl, bool& result);
void SuchGleich(int colNo, int& MaxZero, int& colNummer, int zahl, bool& result);  //  шукаєм найбільший стовпець від кінця з нульовими значеннями

int main()
{
	setlocale(LC_ALL, "rus");
	srand((unsigned)time(NULL));
	int Low = 0;
	int High = 1;
	int rowCount, colCount;
	cout << "colCount : "; cin >> colCount;
	cout << "rowCount : "; cin >> rowCount;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	CreateRows(a, rowCount, colCount, Low, High, 0);
	PrintRows(a, rowCount, colCount, 0);

	bool result = false;
	int MaxZero = 1,
	colNummer = 0;
	SuchNommerS(a, rowCount, colCount, 0, MaxZero, colNummer, result);
	if (result == true)
	{
		cout << "Найбiльша кiлькiсть нулiв вiд кiнця : " << MaxZero << ", у стовпцi пiд номер : " << colNummer + 1;
	}
	else
	{
		cout << "Матриця не мiстить нуля! Гоп! і ти красавчик.";
	}
	cout << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}
void SuchNommerS(int** a, const int rowCount, const int colCount, int colNo, int& MaxZero, int& colNummer, bool& result)
{
	if (colNo < colCount)
	{
		SuchLevel1(a, rowCount, colCount, 0, colNo, MaxZero, colNummer, 0, result);
	}
}
void SuchLevel1(int** a, const int rowCount, const int colCount, int rowNo, int colNo, int& MaxZero, int& colNummer, int zahl, bool& result)
{
	if (rowNo < rowCount)
	{
		CompareZero(a, rowCount, colCount, rowNo, colNo, MaxZero, colNummer, zahl, result); // порівнюємо 
		SuchLevel1(a, rowCount, colCount, rowNo + 1, colNo, MaxZero, colNummer, zahl, result);
	}
	if (zahl != 0)
	{
		SuchGleich(colNo, MaxZero, colNummer, zahl, result);
	}
	SuchNommerS(a, rowCount, colCount, colNo + 1, MaxZero, colNummer, result);
}
void CompareZero(int** a, const int rowCount, const int colCount, const int rowNo, const int colNo, int& MaxZero, int& colNummer, int zahl, bool& result)
{
	if (a[rowNo][colNo] == 0)
	{
		SuchLevel1(a, rowCount, colCount, rowNo + 1, colNo, MaxZero, colNummer, zahl + 1, result);
	}
}
void SuchGleich(int colNo, int &MaxZero, int& colNummer, int zahl, bool& result)  //  шукаєм найбільший стовпець від кінця з нульовими значеннями
{
	if (MaxZero <= zahl)
	{
		result = true;
		MaxZero = zahl;
		colNummer = colNo;
	}
}
void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < colCount - 1)
		CreateRow(a, rowNo, colCount, Low, High, colNo + 1);
}
void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, colCount, Low, High, 0);
	if (rowNo < rowCount - 1)
		CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);
}
void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < colCount - 1)
		PrintRow(a, rowNo, colCount, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	PrintRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		PrintRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
}