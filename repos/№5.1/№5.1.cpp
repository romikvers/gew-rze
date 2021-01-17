// Lab 5_1

#include <iostream>
#include <cmath>
using namespace std;
double h(const double a, const double b); // прототип
int main()
{
	double s, t;

	cout << "s = "; cin >> s;
	cout << "t = "; cin >> t;
	double c = (pow(h ,3)(t * t, 1) + h(1, (t*s) * (t*s))) / 1 + pow(h, 2)(s, t));
	cout << "c = " << c << endl;
	return 0;
}

double h(const double a, const double b, )
{
	return (pow(a,2) * sin(b) + pow(b,2) * cos(a));
}
