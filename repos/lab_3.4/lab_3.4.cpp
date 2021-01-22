// Lab_03_4.cpp
Кошів Роман Романович
// Лабораторна робота No 3.4
// Розгалуження, задане плоскою фігурою.
// Варіант 0.1
#include <iostream>
using namespace std;
int main()
{
	double x; // вхідний аргумент
	double R1; // вхідний аргумент
	double R2; // вхідний аргумент
	double y; // вхідний параметр

	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;
	// розгалуження в повній формі
	if ((y <= R2 + sqrt(R2 * R2 - x * x) && y >=R1 + sqrt(R1 * R1 - x * x) && 0 <= y && 0 <= x) ||
		(y <= R2 - sqrt (R2 * R2 - x * x) && y >= (R1 - sqrt(R1 * R1 - x * x)) && y <= 0 && x <= 0))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	cin.get();
	return 0;
}


