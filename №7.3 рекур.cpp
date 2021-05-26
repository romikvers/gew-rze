// Lab_7_3.cpp

// < прізвище, ім’я автора >
// Лабораторна робота No 7.3.
// Опрацювання динамічних багатовимірних масивів. Рекурсивний спосіб.
// Варіант 14

//  Недокінчена

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

void FirstRows(int** a, const int rowCount, const int colCount, int rowNo, int rowNo1, int colNo);
void FirstRow(int** a, const int rowCount, const int colCount, int rowNo1, int rowNo, int colNo, int tmp);
void Second(int** a, const int rowCount, const int colCount);
void Third(int** a, const int rowCount, const int colCount);
void Forth(int** a, const int rowCount, const int colCount);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -17;
	int High = 15;
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	CreateRows(a, rowCount, colCount, Low, High, 0);
	//InputRows(a, rowCount, colCount);
	PrintRows(a, rowCount, colCount, 0);
	
	cout << "Swap_First" << endl;
	int colNo = colCount - 1;
	int rowNo1 = colCount - 2;
	FirstRows(a, rowCount, colCount, 1, rowNo1, colNo);
	PrintRows(a, rowCount, colCount, 0);
	cout << endl;

	cout << "Swap_Second" << endl;
	Second(a, rowCount, colCount);
	PrintRows(a, rowCount, colCount, 0);
    cout << endl;

	cout << "Swap_Third" << endl;
	Third(a, rowCount, colCount);
	PrintRows(a, rowCount, colCount, 0);
	cout << endl;

	cout << "Swap_Forth" << endl;
	Forth( a, rowCount, colCount);
	PrintRows(a, rowCount, colCount, 0);
	cout << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void CreateRow(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < colCount)
		CreateRow(a, rowCount, colCount, Low, High, rowNo, colNo + 1);
}
void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowCount, colCount, Low, High, rowNo, 0);
		if (rowNo < rowCount - 1)
			CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);
}
void InputRow(int** a, const int rowCount, const int colCount, int rowNo, int colNo)
{
	cout << "a[" << rowNo << "][" << colNo << "] = ";
	cin >> a[rowNo][colNo];
	if (colNo < colCount - 1)
		InputRow(a, rowCount, colCount, rowNo, colNo + 1);
	else
		cout << endl;
}
void InputRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	InputRow(a, rowCount, colCount, rowNo, 0);
	if (rowNo < rowCount - 1)
		InputRows(a, rowCount, colCount, rowNo);
	else
		cout << endl;
}
void PrintRow(int** a, const int rowCount, const int colCount, int rowNo, int colNo)
{
	cout << a[rowNo][colNo];
	    cout << endl;
	if (colNo < colCount - 1)
	PrintRow(a, rowCount, colCount, rowNo, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	PrintRow(a, rowCount, colCount, rowNo, 0);
	if (rowNo < rowCount - 1)
		PrintRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
}
void FirstRow(int** a, const int rowCount, const int colCount, int rowNo1, int rowNo, int colNo, int tmp)
{
		tmp = a[0][rowNo1];
		a[0][rowNo1] = a[rowNo][colNo];
		a[rowNo][colNo] = tmp;
		FirstRows(a, rowCount, colCount, rowNo + 1, rowNo1, colNo);
}
void FirstRows(int** a, const int rowCount, const int colCount, int rowNo, int rowNo1, int colNo)
{
	if (rowNo < rowCount)
	FirstRow(a, rowCount, colCount, rowNo1, rowNo, colNo, 0);
	if (rowNo1 != -1)
		FirstRows(a, rowCount, colCount, rowNo, rowNo1 - 1, colNo);
	else
		cout << endl;
}
void Second(int** a, const int rowCount, const int colCount)
{
	int tmp;
	int i = rowCount - 1;
	const int j = colCount - 1;
	int rowNo = rowCount - 1;
	int colNo = colCount - 1;
	while (i != -1 && colNo != -1)
	{
		tmp = a[i][j];
		a[i][j] = a[rowNo][colNo];
		a[rowNo][colNo] = tmp;
		i--;
		colNo--;
	}
}
void Third(int** a, const int rowCount, const int colCount)
{
	int tmp;
	int i = 0;
	int j = 0;
	int rowNo = rowCount - 1;
	int colNo = colCount - 1;
	while (i < rowCount - 1 && colNo != -1)
	{
		a[i][j];
		a[rowNo][colNo];

		tmp = a[i][j];
		a[i][j] = a[rowNo][colNo];
		a[rowNo][colNo] = tmp;
		i++;
		colNo--;
	}
}
void Forth(int** a, const int rowCount, const int colCount)
{
	int tmp;
	int i = 1;
	int j = 0;
	int rowNo = 0;
	int colNo = 1;
	while (i < rowCount && colNo < colCount)
	{
		a[i][j];
		a[rowNo][colNo];

		tmp = a[i][j];
		a[i][j] = a[rowNo][colNo];
		a[rowNo][colNo] = tmp;
		i++;
		colNo++;
	}
}
//Здійснити циклічне переміщення квадратної матриці розміром(n  n) вправо на k
//елементів таким чином : елементи першого рядка переміщаються в останній стовпець
//зверху вниз, з нього – в останній рядок справа наліво, з нього – в перший стовпець від
//низу до верху, з нього – в перший рядок; для решти елементів – аналогічно(оформитиу вигляді void - функції).*/