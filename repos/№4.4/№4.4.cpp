// №4.4.cpp 

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{   
	double xp, xk, dx, y,x;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "y ="; cin >> dx;
	cout << fixed;
	cout << "---------------------------" << endl;
	cout << "|" << setw(5) << "x" << " |"
		<< setw(7) << "y" << " |" << endl;
	cout << "---------------------------" << endl;
	x = xp;
	while (x <= xk)
	{
		if (x <= -4)
			y = -2;
		else
			if (-4 < x && x <= 0)
				y = -1 + x;
			else
				if (0 < x && x <= 2)
					y = x * x;
				else
					y = 3x;

			cout << "|" << setw(7) << setprecision(2) << x
			<< " |" << setw(10) << setprecision(3) << y
			<< " |" << endl;
		x += dx;
	}
	cout << "---------------------------" << endl;
	return 0;
}
	