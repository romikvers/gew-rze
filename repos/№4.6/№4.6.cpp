№4.6




#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double P, S;
	int n, i;
	S = 1;
	i = 1;
	while (i <= 10)
	{
		P = 1;
		k = 1;
		while (k <= i)
		{
			P+= k / i;
			k++;
		}
		S*= (1+P)/(i*i);
		i++;
	}
	cout << S << endl;
	S = 1;
	i = 1;
	do
	{
		P = 0;
		k = 1;
		do
		{

			P += k / i;
			k++;
		} while (i <= 10);
		S *= (1 + P) / (i * i)
		i++;
	} while (i <= 10);
	cout << S << endl;
	S = 1;
	for (i = 1; i <= 10; i++)
	{
		P = 0;
		for (k = 1; k <= i; k++)
		{
			P += k / i;
			k++;
		}
		S *= (1 + P) / (i * i);
	}
	cout << S << endl;
	S = 1;
	for (i = 10; i >= 1; i--)

	{
		P = 0;
		for (k = i; k >= 1; k--)

		{
			P += k / i;

		}
		S *= (1 + P) / (i * i);
	}
	cout << S << endl;
	return 0;
}