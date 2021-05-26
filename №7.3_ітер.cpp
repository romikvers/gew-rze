//Здійснити циклічне переміщення квадратної матриці розміром(n  n) вправо на k
//елементів таким чином : елементи першого рядка переміщаються в останній стовпець
//зверху вниз, з нього – в останній рядок справа наліво, з нього – в перший стовпець від
//низу до верху, з нього – в перший рядок; для решти елементів – аналогічно(оформитиу вигляді void - функції).

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
//void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
void First(int** a, const int rowCount, const int colCount);
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

	Create(a, rowCount, colCount, Low, High);
	//Input(a, rowCount, colCount);
	Print(a, rowCount, colCount);
	
	cout << "Swap_First" << endl;
	First(a, rowCount, colCount);
	Print(a, rowCount, colCount);
	cout << endl;

	cout << "Swap_Second" << endl;
	Second(a, rowCount, colCount);
	Print(a, rowCount, colCount);
    cout << endl;

	cout << "Swap_Third" << endl;
	Third(a, rowCount, colCount);
	Print(a, rowCount, colCount);
	cout << endl;

	cout << "Swap_Forth" << endl;
	Forth( a, rowCount, colCount);
	Print(a, rowCount, colCount);
	cout << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Input(int** a, const int rowCount, const int colCount)
{
		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				cout << "a[" << i << "][" << j << "] = ";
				cin >> a[i][j];
			}
			cout << endl;
		}
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
void First(int** a, const int rowCount, const int colCount)
{	
	int tmp;
	int rowNo1 = colCount - 2;
	int rowNo = 1; 
	int colNo = colCount - 1;
	while (rowNo1 != -1 && rowNo < rowCount)
	{
		tmp = a[0][rowNo1];
		a[0][rowNo1] = a[rowNo][colNo];
		a[rowNo][colNo] = tmp;
		rowNo1--;
		rowNo++;
	}
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
//низу до верху, з нього – в перший рядок; для решти елементів – аналогічно(оформитиу вигляді void - функції).