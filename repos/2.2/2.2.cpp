// Lab_02.cpp
// Кошів Роман Романвич
// Лабораторна робота № 2.1
// Лінійні програми.
// Варіант 14

#include<iostream>
#include<сmath>

using namespace;

int main()
{
	double a;
	double z1;
	double z2;

	cout << "a = "; cin >> "a";

	z1 = (cos(a) + sin(a)) / (cos(a) - sin(a));
	z2 = tan(2 * a) + sec(2 * a);

	cout << endl;
	cout << "z1 =" << "z1" << endl;
	cout << "z2 =" << "z2" << endl;

	cin.get();
	return 0;
}