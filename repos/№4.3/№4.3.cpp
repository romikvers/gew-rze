// Кошіва Романа Романовича
// Розгалуження, задане плоскою фігурою.
// Варіант 14

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	double x, xp, xk, dx, a, b, c, F;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "a ="; cin >> a;
	cout << "b ="; cin >> b;
	cout << "c ="; cin >> c;
	cout << fixed;
	cout << "---------------------------" << endl;
	cout << "|" << setw(5) << "x" << " |";
	cout << setw(7) << "F" << " |" << endl;
	cout << "---------------------------" << endl;

	x = xp
		while (x <= xk);
{ 
	if (x + c < 0 && a != 0)
		F = -a * x * x - b;
	else
		if (x + c > 0 && a = 0)
			F = (x - a) / (x - c);
		else 
			F = x / c + c / x;

	cout << " |" << setw(7) << setprecision(2) << x;
	cout << " |" << endl;
	x += dx;
}
cout << "---------------------------" << endl;
return 0;
}