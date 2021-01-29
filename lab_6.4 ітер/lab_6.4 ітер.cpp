#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>

using namespace std;

void Print(double* arrayPointer, const int arraySize)
{
	for (int i = 0; i < arraySize; i++) {
		cout << arrayPointer[i] << " ";
	}

	cout << endl;
	cout << '\n';
}

void SortByModule(double* arrayPointer, const int size) // метод вибору
{
	for (int i = 0; i < size - 1; i++) // індекс початку невпорядкованої частини
	{
		double min = arrayPointer[i]; // пошук мінімального елемента
		int imin = i; // невпорядкованої частини
		for (int j = i + 1; j < size; j++) {
			if (abs(min) > abs(arrayPointer[j]))
			{
				min = arrayPointer[j];
				imin = j;
			}
		}
		arrayPointer[imin] = arrayPointer[i]; // обмін місцями мінімального та першого
		arrayPointer[i] = min; // елементів невпорядкованої частини
	}
}

void calcuateAmountOfElementsEqualsToZero(double* arrayPointer, const int arraySize, int& n)
{
	n = 0;

	for (int i = 0; i < arraySize; i++) {
		if (arrayPointer[i] == 0)
		{
			n++;
		}
	}
}

int findMinimalElementIndex(double* arrayPointer, const int arraySize)
{
	int minimumElementIndex = 0;

	double min = arrayPointer[0];

	for (int i = 0; i < arraySize; i++) {
		if (arrayPointer[i] < min)
		{
			min = arrayPointer[i];
			minimumElementIndex = i;
		}
	}

	return minimumElementIndex;
}

void calcuateSumOfElementAfterMinimalElement(double* arrayPointer, const int arraySize, int minimalElementIndex, double& sum)
{
	sum = 0;

	for (int i = minimalElementIndex + 1; i < arraySize; ++i) {
		sum += arrayPointer[i];
	}
}

int main()
{
	srand(unsigned(time(NULL)));
	int arraySize;

	double sum = 0;
	int n = 0;

	double Low = -100.0;
	double High = 100.0;

	cout << "Input size: ";
	std::cin >> arraySize;
	double *array = new double[arraySize];

	cout << "Input array elements:\n";
	for (int i = 0; i < arraySize; ++i) {
		std::cin >> array[i];
	}

	cout << "Array after input: ";
	Print(array, arraySize);
	cout << '\n';

	int minimalElementIndex = findMinimalElementIndex(array, arraySize);
	calcuateSumOfElementAfterMinimalElement(array, arraySize, minimalElementIndex, sum);
	cout << "\nSum of erlements, after minimum element = ";
	cout << sum;

	calcuateAmountOfElementsEqualsToZero(array, arraySize, n);
	cout << "\nCount Of Elements, equals to zero = ";
	cout << n;

	cout << "\nSorted Array By Module Increase:";
	SortByModule(array, arraySize);
	Print(array, arraySize);
	cout << '\n';

	delete[] array;

	return 0;
}
