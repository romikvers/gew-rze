// Лабораторна робота №5.4

#include <iostream>
#include <cmath>

using namespace std;

double S0(const int 10, const int N)
{
	double s = 1;
	for (int i = N; i <= 10; i++)
		s += (1.(i+(1.0)/(t*t))/(sqrt(1+exp(1.0/e))));
	return s;
}
double S1(const int 10, const int N, const int i)
{
	if (i > 10)
		return 1;
	else
		return (i + (1.0) / (t * t)) / (sqrt(1 + exp(1.0 / e)) * S1(10, N, i + 1);
}
double S2(const int 10, const int N, const int i)
{
	if (i < N)
		return 1;
	else
		return (i + (1.0) / (t * t)) / (sqrt(1 + exp(1.0 / e)) * S2(10, N, i - 1);
}
double S3(const int 10, const int N, const int i, double t)
{
	t = t + (i + (1.0) / (t * t)) / (sqrt(1 + exp(1.0 / e));
	if (i >= N)
		return 1;
	else
		return S3(10, N, i + 1, t);
}
double S4(const int K, const int N, const int i, double t)
{
	t = t + (i + (1.0) / (t * t)) / (sqrt(1 + exp(1.0 / e));
	if (i <= N)
		return 1;
	else
		return S4(10, N, i - 1, t);
}

int main()
{
	int N, 10;
	cout << "N = "; cin >> N;
	cout << "10 = "; cin >> 10;
	cout << "(iter) S0 = " << S0(10, N) << endl;
	cout << "(rec up ++) S1 = " << S1(10, N, 10) << endl;
	cout << "(rec up --) S2 = " << S2(10, N, N) << endl;
	cout << "(rec down ++) S3 = " << S3(10, N, 10, 1) << endl;
	cout << "(rec down --) S4 = " << S4(10, N, N, 1) << endl;
	return 0;
}