// №6.1.cpp 
//Діапазон значень елементів масиву : (15, ..., 94)
//Одновимірний масив p із 25 елементів цілого типу.
//Критерій – всі, крім : парних з індексами, кратними 13
#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>

using namespace std;

void Create(int* p, const int n, const int Low, const int High, int i)
{
	if (i >= n)
	{
		return;
	}

	p[i] = Low + rand() % (High - Low + 1);
	i++;

	Create(p, n, Low, High, i);
}

void Print(int* p, const int n, int i)
{

	if (i >= n) {
		cout << endl;
		cout << '\n';
		return;
	}

	cout << setw(4) << p[i];
	i++;

	Print(p, n, i);
}

void Sort(int* p, const int size, int i) // метод вибору
{

	if (i >= size - 1)
	{
		return;
	}

	int min = p[i]; // пошук мінімального елемента
	int imin = i; // невпорядкованої частини
	for (int j = i + 1; j < size; j++)
		if (min > p[j])
		{
			min = p[j];
			imin = j;
		}
	p[imin] = p[i]; // обмін місцями мінімального та першого
	p[i] = min; // елементів невпорядкованої частини

	i++;

	Sort(p, size, i);
}

void f(int* p, const int n, int& k, int& sum, int i)
{
	if (i == 0)
	{
		sum = 0;
		k = 0;


		if (i >= n) {
			return;
		}

		if (!(p[i] % 2 == 0 && i % 13 == 0))
		{
			sum += p[i];
			k++;
			p[i] = 0;
		}

		i++;

		f(p, n, k, sum, i);
	}
}

	int main()
	{
		srand(unsigned(time(NULL)));
		const int n = 25;
		int p[n];

		int sum = 0;
		int k = 0;

		int Low = 15;
		int High = 94;

		cout << "New Array:";
		cout << '\n';

		Create(p, n, 15, 94, 0);
		Print(p, n, 0);
		cout << '\n';

		cout << "Sorted Array:";
		Sort(p, n, 0);
		Print(p, n, 0);
		cout << '\n';

		f(p, n, k, sum, 0);
		cout << "Sum = ";
		cout << sum;

		cout << " k = ";
		cout << k;

		cout << "\nArray after operations:\n";
		Print(p, n, 0);
		cout << '\n';

		return 0;
	}