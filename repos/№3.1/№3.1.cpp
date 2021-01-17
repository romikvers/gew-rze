#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double x; // вхідний параметр
	double y; // результат обчислення виразу
	double A; // проміжний результат - функціонально стала частина виразу
	double B; // проміжний результат 
	
	cout << "x = "; cin >> x;

	A = 2 * sin(fabs(x * x * x));

	// спосіб 1: розгалуження в скороченій формі
	if (0 < x && x < 3)
		B = 1 / x + log(x * x);
	if (3 <= x && x < 4)
		B = 7 / x + pow(x, 1. / 3.);
	if (x >= 4)
		B = exp(1 + log(fabs(x)));
	y = A + B;

	cout << endl;
	cout << "1) y = " << y << endl;

	// спосіб 2: розгалуження в повній формі
	if (0 < x && x < 3)
            B = 1 / x + log(x * x);
	else
		if (3 <= x && x < 4)
			B = 7 / x + pow(x, 1. / 3.);
		else
			B = exp(1 + log(fabs(x)));
	y = A + B;
	cout << "2) y = " << y << endl;
	cin.get();


	return 0;
}