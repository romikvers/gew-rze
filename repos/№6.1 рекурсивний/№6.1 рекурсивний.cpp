
#include<iostream>
#include<time.h.>
#include<iomanip>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	const int n = 25;
		int p[n];


		int Low = 15;
		int High = 94;

		 Print(p, n, 0)
		 Create (p, n, Low, High, 0)
	     s(p, sum, n, 0)
		 f(p, k, n, 0)
		 format_mas(p, n, 0)
} return 0;

void format_mas(int* p, const int n, int i)
{
	for (int i = 0; i < n; i++)
	{
		if (!(p[i] % 2 == 0 && i % 13 == 0))
			a[i] = 0;
	}
}
void f(int* p, const int n, int& k, int i)
{
	int S = 0;
	int k = 0;
	for (int i = 0; i <= n-1; i++)
	{
		if (!(p[i] % 2 == 0 && i % 13 == 0))
			k++;
	}
void Create(int* p, const int size, const int Low, const int High, int i)
{
	p[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(p, size, Low, High, i + 1);
}

void Print(int* p, const int size, int i)
{
	cout << setw(4) << p[i];
	if (i < size - 1)
		Print(p, size, i + 1);
	else
		cout << endl;
}

void s(int* p, int& sum, const int n, int i)
{
	for (int i = 0; i < n -1; i++)
	{
		if (!(p[i] % 2 == 0 && i % 13 == 0))
			sum += a[i];
	}
}


//void Inverse(int* p, const int n, int i)
{
	int tmp = p[i];
	p[i] = a[n - 1 - i];
	p[n - 1 - i] = tmp;
	if (i < n / 2 - 1)
		Inverse(p, n, i + 1);
}