#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	cout << "dx = "; cin >> dx;
	cout << fixed;
	double x, xp, xk, dx, A, B, y;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "---------------------------" << endl;
	cout << "|" << setw(5) << "x" << " |"
		<< setw(7) << "y" << " |" << endl;
	cout << "---------------------------" << endl;
	x = xp;
	while (x <= xk)
	{
		A = abs(4*x-1);
		if (x < 0)
			B = pow(x,7)-2*x;
		else
			if (x >= 1)
				B = pow(x,4)+exp(x*x + 3);
			else
				B = atan((exp(x)+1)/8.0);
		y = A + B;
		cout << "|" << setw(7) << setprecision(2) << x
			<< " |" << setw(10) << setprecision(3) << y
			<< " |" << endl;
		x += dx;
	}
	cout << "---------------------------" << endl;
	return 0;
}