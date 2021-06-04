// Lab_7_3.cpp

// Лабораторна робота No 7.3.
// Опрацювання динамічних багатовимірних масивів. Рекурсивний спосіб.
// Варіант 14

//  Недокінчена

//Здійснити циклічне переміщення квадратної матриці розміром(n  n) вправо на k
//елементів таким чином : елементи першого рядка переміщаються в останній стовпець
//зверху вниз, з нього – в останній рядок справа наліво, з нього – в перший стовпець від
//низу до верху, з нього – в перший рядок; для решти елементів – аналогічно(оформитиу вигляді void - функції).

//Здійснити циклічне переміщення квадратної матриці розміром(n  n) вправо на k
//елементів таким чином : елементи першого рядка переміщаються в останній стовпець
//зверху вниз, з нього – в останній рядок справа наліво, з нього – в перший стовпець від
//низу до верху, з нього – в перший рядок; для решти елементів – аналогічно(оформитиу вигляді void - функції).

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo);
void CreateRow(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNO, int colNO);
//void InputRows(int** a, const int rowCount, const int colCount, int rowNo);
//void InputRow(int** a, const int rowCount, const int colCount, int colNo);
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo);
void PrintRow(int** a, const int rowCount, const int colCount, int rowNo, int colNo);
void FirstRows(int** a, const int rowCount, const int colCount, int colNo, int colNo1, int rowNo, int tmp);
void FirstRow(int** a, const int rowCount, const int colCount, int colNo, int colNo1, int rowNo, int tmp);
void SecondRows(int** a, const int rowCount, const int colCount, int rowNoleft, int colNoDown);
void SecondRow(int** a, const int rowCount, const int colCount, int rowNoleft, const int colNoleft, const int rowNoDown, int colNoDown, int tmp);
void ThirdRows(int** a, const int rowCount, const int colCount, int rowNoleft, int colNoDown);
void ThirdRow(int** a, const int rowCount, const int colCount, int rowNoleft, const int colNoleft, const int rowNoDown, int colNoDown, int tmp);
void ForthRows(int** a, const int rowCount, const int colCount, int rowUp, int colNoleft);
void ForthRow(int** a, const int rowCount, const int colCount, int rowUp, int colUp, int colNoleft, int rowNoleft, int tmp);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -17;
	int High = 15;
	int valueCount, rowCount, colCount;
	cout << "rowCount and colCount : "; cin >> valueCount;
	rowCount = valueCount;
	colCount = valueCount;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	CreateRows(a, rowCount, colCount, Low, High, 0);
	//InputRows(a, rowCount, colCount, 0);
	PrintRows(a, rowCount, colCount, 0);

	cout << "Swap_First" << endl;
	FirstRows(a, rowCount, colCount, colCount - 1, colCount - 2, 1, 0);
	PrintRows(a, rowCount, colCount, 0);
	cout << endl;

	cout << "Swap_Second" << endl;
	SecondRows(a, rowCount, colCount, rowCount - 2, colCount - 2);
	PrintRows(a, rowCount, colCount, 0);

	cout << "Swap_Third" << endl;
	ThirdRows(a, rowCount, colCount, 0, colCount - 1);
	PrintRows(a, rowCount, colCount, 0);
	cout << endl;

	cout << "Swap_Forth" << endl;
	ForthRows(a, rowCount, colCount, 0, 0);
	PrintRows(a, rowCount, colCount, 0);
	cout << endl;

	cout << endl;
	return 0;
}
void InputRow(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << "a[" << rowNo << "][" << colNo << "] = ";
	cin >> a[rowNo][colNo];
	if (colNo < colCount - 1)
		InputRow(a, rowNo, colCount, colNo + 1);
	else
		cout << endl;
}
void InputRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	InputRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		InputRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
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
void FirstRows(int** a, const int rowCount, const int colCount, int colNo, int colNo1, int rowNo, int tmp)
{
	if (colNo1 != -1 && rowNo < rowCount)
	{
		FirstRow(a, rowCount, colCount, colNo, colNo1, rowNo, 0);
	}
}
void FirstRow(int** a, const int rowCount, const int colCount, int colNo, int colNo1, int rowNo, int tmp)
{
	tmp = a[0][colNo1];
	a[0][colNo1] = a[rowNo][colNo];
	a[rowNo][colNo] = tmp;
	FirstRows(a, rowCount, colCount, colNo, colNo1 - 1, rowNo + 1, tmp);
}
void SecondRows(int** a, const int rowCount, const int colCount, int rowNoleft, int colNoDown)
{
	if (rowNoleft != -1 && colNoDown != -1)
	{
		SecondRow(a, rowCount, colCount, rowNoleft, colCount - 1, rowCount - 1, colNoDown, 0);
	}
}
void SecondRow(int** a, const int rowCount, const int colCount, int rowNoleft, const int colNoleft, const int rowNoDown, int colNoDown, int tmp)
{
	tmp = a[rowNoleft][colNoleft];
	a[rowNoleft][colNoleft] = a[rowNoDown][colNoDown];
	a[rowNoDown][colNoDown] = tmp;
	SecondRows(a, rowCount, colCount, rowNoleft - 1, colNoDown - 1);
}
void ThirdRows(int** a, const int rowCount, const int colCount, int rowNoleft, int colNoDown)
{
	if (rowNoleft < rowCount - 1 && colNoDown != 0)
	{
		ThirdRow(a, rowCount, colCount, rowNoleft, 0, rowCount - 1, colNoDown, 0);
	}
}
void ThirdRow(int** a, const int rowCount, const int colCount, int rowNoleft, const int colNoleft, const int rowNoDown, int colNoDown, int tmp)
{
	tmp = a[rowNoleft][colNoleft];
	a[rowNoleft][colNoleft] = a[rowNoDown][colNoDown];
	a[rowNoDown][colNoDown] = tmp;
	ThirdRows(a, rowCount, colCount, rowNoleft + 1, colNoDown - 1);
}
void ForthRows(int** a, const int rowCount, const int colCount, int rowUp, int colNoleft)
{
	if (rowUp < rowCount && colNoleft < colCount)
	{
		ForthRow(a, rowCount, colCount, rowUp, 0, colNoleft, 0, 0);
	}
}
void ForthRow(int** a, const int rowCount, const int colCount, int rowUp, int colUp, int colNoleft, int rowNoleft, int tmp)
{
	tmp = a[rowUp][colUp];
	a[rowUp][colUp] = a[rowNoleft][colNoleft];
	a[rowNoleft][colNoleft] = tmp;
	ForthRows(a, rowCount, colCount, rowUp + 1, colNoleft + 1);
}