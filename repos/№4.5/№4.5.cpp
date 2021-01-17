// Варіант 14   ст. 107

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
int main()
{
	double x, y, R(2), R(1);
	srand((unsigned)time(NULL));

	cout << "R(2) = "; cin >> R(2);
	cout << "R(1) = "; cin >> R(1);
	for (int i = 0; i < 10; i++)
	{
		cout << "x = "; cin >> x;
		cout << "y = "; cin >> y;
		if ((y <= R(2) + sqrt(R(2) * R(2) - x * x) && y >= R(1) + sqrt(R(1) * R(1) - x * x) && 0 <= y && 0 <= x) ||
			(y <= R(2) - sqrt(R(2) * R(2) - x * x) && y >= (R(1) - sqrt(R(1) * R(1) - x * x)) && y <= 0 && x <= 0))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	cout << endl << fixed;

		for (int i = 0; i < 10; i++)
		{
			x = 6. * rand() / RAND_MAX - R(2);
			y = 6. * rand() / RAND_MAX - R(2);
			if ((y <= R(2) + sqrt(R(2) * R(2) - x * x) && y >= R(1) + sqrt(R(1) * R(1) - x * x) && 0 <= y && 0 <= x) ||
				(y <= R(2) - sqrt(R(2) * R(2) - x * x) && y >= (R(1) - sqrt(R(1) * R(1) - x * x)) && y <= 0 && x <= 0))

				cout << setw(8) << setprecision(4) << x << " "
				<< setw(8) << setprecision(4) << y << " " << "yes" << endl;
			else
				cout << setw(8) << setprecision(4) << x << " "
				<< setw(8) << setprecision(4) << y << " " << "no" << endl;
		}
	return 0;
}