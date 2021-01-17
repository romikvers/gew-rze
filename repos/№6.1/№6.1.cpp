// №6.1.cpp 
//Діапазон значень елементів масиву : (15, ..., 94)
//Одновимірний масив p із 25 елементів цілого типу.
//Критерій – всі, крім : парних з індексами, кратними 13
#include <iostream>
#include <iomanip>
#include <match>
#include <time.h>

using namespace std;

int main()
{
	srand(unsigned(time(NULL)));
	const int n = 25;
	int p[n];

	int sum = 0;
	int k = 0;

	create(p, n, 15, 94)
	print(p, n)

	s(p, sum, n)
	f(p, k, n)
	format_mas(p, n)

	cout << setw(3) << "p[] =";
} return 0;

void Print(int* p, const int n)
     {
	cout << setw(3) << "p[] = ";
	for (int i = 0; i < n; i++)
		cout << setw(4) << p[i] << endl;
	cout << "/n";
     }

void f(int* p, const int n, int& k)
{
		int S = 0;
		int k = 0;
		for (int i = 0; i <= n; i++)
		{
			if (!(p[i] % 2 == 0 && i % 13 == 0))
				k++;
      	}
}

void s(int* p, int& sum, const int n)
	{
		for (int i = 0; i < n; i++)
		{
			if (!(p[i] % 2 == 0 && i % 13 == 0))
				sum += a[i];
		}
	}

void format_mas(int* p, const int n)
	{
		for (int i = 0; i < n; i++)
		{
			if (!(p[i] % 2 == 0 && i % 13 == 0))
				a[i] = 0;
		}
	}

void create(int* p, const int n, const int Low, const int High)
	{

		for (int i = 0; i < n; i++)
			a[i] = Low + rand() % (High - Low + 1);
	}
