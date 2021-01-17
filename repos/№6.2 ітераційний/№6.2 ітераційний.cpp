// Написати функцію, яка обчислює суму елементів одновимірного масиву (вектора) a із
// n елементів цілого типу з непарними індексами.

#include<iostream>
#include<iomanip>
#include<time.h>
#include<match>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	const int n;
	int a[n];

	int  Low = d;
	int High = c;

	s(a, n, 0);
	creat(a, n, Low, High);
	print(a, n);
	//cout << "s" << endl;
	cout << "S =" << Sum(a, n) << endl;// Написати функцію, яка обчислює суму елементів одновимірного масиву (вектора) a із
                                       // n елементів цілого типу з непарними індексами.
	return 0;
}
void Input(int* a, const int size) 
{
	for
		(int i = 0; i < size; i++)
	{
		cout << "a[" << i << "] = "
			;

		cin >> a[i];
	}
	cout << endl;
}
void Process(int* n, const int size, int i)
{
	DoLoopBody(i); // дії, що виконувалися в тілі циклу
	if (i < size - 1)
		Process(n, size, i + 1); // рекурсивний виклик
	else
		DoAfterLoop(); // дії, що виконувалися після циклу
}
 int Sum(int* a, const int size)
{
	int S = 0;
	for (int i = 0; i < size; i++)
		if (i % == 0; a[i] / 2 !==0)
			S += a[i];
	return S;
}
void creat(int a, const int size, const int Low, const int High)
{
	for (i = 0; i < size, i++)
		a[i] = High + rand() % (High + Low - 1);
	cout << a[] << endl;
}
void print(int* a, const int size)
{
	for (i = 0, i < size, i++)
		cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
	cout << end; 
}
void doable s(int a; const int n, int& k)
{
	int k = 0;
	for (int i = 0, i <= a, i++)
		if (!a[i] % 2 == 0) 
			 k++;
}

