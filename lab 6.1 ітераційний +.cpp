// №6.1.cpp 
//Діапазон значень елементів масиву : (15, ..., 94)
//Одновимірний масив p із 25 елементів цілого типу.
//Критерій – всі, крім : парних з індексами, кратними 13
#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>

using namespace std;

void Print(int* p, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(4) << p[i];
	}

	cout << endl;
	cout << "\n";
}
void Create(int* p, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		p[i] = Low + rand() % (High - Low + 1);
}
void f(int* p, const int n, int& k, int &sum)
{
	 sum = 0;
	 k = 0;
	 for (int i = 0; i < n; i++)
	 {
		 if (!(p[i] % 2 == 0 && i % 13 == 0))
		 {
			sum += p[i];
			 k++;
			 p[i] = 0;
		 }
	 }
}
void Sort(int* p, const int size) // метод вибору
{
	for (int i = 0; i < size - 1; i++) // індекс початку невпорядкованої частини
	{
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
	Create(p, n, 15, 94);
	Print(p, n);
	cout << '\n';

	cout << "Sorted Array:";
	Sort(p, n);
	Print(p, n);
	cout << '\n';

	f(p, n, k, sum);
	cout << "Sum = ";
	cout << sum;

	cout << " k = ";
	cout << k;

	cout << "\nArray after operations:\n";
	Print(p, n);
	cout << '\n';

	return 0;
}