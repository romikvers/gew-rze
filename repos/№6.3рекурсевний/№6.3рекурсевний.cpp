#include <iostream>
#include <iomanip>

using namespace std;
void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
	cout << endl;
}
int Find(int* a, const int size, const int x)
{
	for (int i = 0; i < size; i++)
		if (a[i] == x)
			return i;
	return -1;
}
int main()
{
	const int n = 5;
	int a[n];
    Print(a, n);
	int x;
	cout << "x = ? "; cin >> x;
	int i = Find(a, n, x);
	if (i > -1)
		cout << "Found at position " << i << endl;
	else
		cout << "Not found" << endl;
	return 0;
}
void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
	cout << endl;
}