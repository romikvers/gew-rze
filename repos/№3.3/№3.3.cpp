// Lab_03_3.cpp
// < прізвище, ім’я автора >
// Лабораторна робота No 3.3
// Розгалуження, задане графіком функції.
// Варіант 14

#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	double x; // вхідний аргумент
	double y; // результат обчислення виразу
	cout << "x = "; cin >> x;
	// розгалуження в повній формі
	if (x <= -4)
		y = -2;
	else
		if (-4 < x && x <= 0)
			y = -1+x;
		else
			if (0 < x && x <= 2)
				y = x * x;
			else
					y = 3x;
	cout << endl;
	cout << "y = " << y << endl;
	cin.get();
	return 0;
}