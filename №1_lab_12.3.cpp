#include <iostream>
#include <iomanip>
#include <time.h>
#include <locale>

using namespace std;

typedef int Info;

struct Elem
{
	Elem* link;
	Info info;
};

void Insert(Elem*& L, Info value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2

	if (L != NULL)
	{
		Elem* T = L;
		while (T->link != L)
			T = T->link; // 3
		T->link = tmp; // 4
	}
	else
	{
		L = tmp; // 5
	}

	tmp->link = L; // 6
}
Info Remove(Elem*& L)
{
	Elem* T = L;
	while (T->link != L)
		T = T->link; // 1
	Info value = L->info; // 2
	if (T != L)
	{
		Elem* tmp = L->link; // 3
		delete L; // 4
		L = tmp; // 5

		T->link = L; // 6

	}
	else
	{
		delete L; // 4
		L = NULL; // 7
	}
	return value; // 8
}
int Count(Elem* L) {
	if (L == NULL)
	{
		return 0;
	}
	Elem* first = L;
	int k = 1;
	while (L->link != first)
	{
		k++;
		L = L->link;
	}
	return k;
}
void Print(Elem* L) {
	if (L == NULL)
		return;

	Elem* first = L;
	cout << setw(4) << L->info;
	while (L->link != first)
	{
		L = L->link;
		cout << setw(4) << L->info;
	}
	cout << endl;
}
int Sort_at(Elem* L)
{
	Elem* T = L;
	Info value;
	int up = 0,      //  відсортовано за зростанням
		down = 0;     //   відсортовано за спаданням
	while (T->link != L)
	{
		value = T->info;
		if (value < T->link->info)
		{
			up++;
		}
		else
			if (value > T->link->info)
			{
				down++;
			}
		T = T->link;
	}
	if (down == 0)   //  то  масив посортований за зростанням
	{
		return 2;
	} else
		if (up == 0)   //    то  масив посортований за спаданням
		{
			return 1;
		}
	return 0;
}
int main()
{
	setlocale(LC_ALL, "rus");
	Elem* L = NULL;
	for (int i = 10; i >= 0; i--)
	{
		int value = 1 + rand() % 100;
		Insert(L, value);
	}
	cout << "Count :" << Count(L) << endl;
	Print(L);
	int sorat = Sort_at(L);
	if (2 == sorat)
	{
		cout << "Черга відсортована за зростанням" << endl;
	} else
		if(1 == sorat)
	    {
		cout << "Черга відсортована за спаданням" << endl;
	    }
		else 
			cout << "Значення в черзі не мають ознаки послідовності" << endl;

	while (L != NULL)
	{
		cout << setw(4) << Remove(L);
	}
	cout << endl;
	return 0;
}