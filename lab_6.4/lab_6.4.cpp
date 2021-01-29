// lab_6.4.
#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>

using namespace std;

void PrintRec(double* arrayPointer, const int arraySize, int currentIndex)
{
	if (currentIndex >= arraySize) {
		cout << endl;
		cout << '\n';
		return;
	}

	cout << arrayPointer[currentIndex] << " ";

	currentIndex++;

	PrintRec(arrayPointer, arraySize, currentIndex);
}

void SortByModuleRecursive(double* arrayPointer, const int size, int currentIndex) // метод вибору
{
	if (currentIndex >= size - 1) {
		return;
	}

	double min = arrayPointer[currentIndex]; // пошук мінімального елемента
	int imin = currentIndex; // невпорядкованої частини
	for (int j = currentIndex + 1; j < size; j++)
		if (abs(min) > abs(arrayPointer[j]))
		{
			min = arrayPointer[j];
			imin = j;
		}
	arrayPointer[imin] = arrayPointer[currentIndex]; // обмін місцями мінімального та першого
	arrayPointer[currentIndex] = min; // елементів невпорядкованої частини

	currentIndex++;

	SortByModuleRecursive(arrayPointer, size, currentIndex);
}

void calcuateAmountOfElementsEqualsToZeroRecursive(double* arrayPointer, const int arraySize, int currentIndex, int& n)
{
	if (currentIndex == 0) {
		n = 0;
	}

	if (currentIndex >= arraySize) {
		return;
	}

	if (arrayPointer[currentIndex] == 0)
	{
		n++;
	}

	currentIndex++;

	calcuateAmountOfElementsEqualsToZeroRecursive(arrayPointer, arraySize, currentIndex, n);
}

void findMinimalElementIndexRecursive(double* arrayPointer, const int arraySize, int& minimumElementIndex, int currentIndex)
{

	if (currentIndex >= arraySize) {
		return;
	}

	double min = arrayPointer[minimumElementIndex];

	if (arrayPointer[currentIndex] < min)
	{
		minimumElementIndex = currentIndex;
	}

	currentIndex++;

	findMinimalElementIndexRecursive(arrayPointer, arraySize, minimumElementIndex, currentIndex);
}

void calcuateSumOfElementAfterMinimalElementRecursive(double* arrayPointer, const int arraySize, double& sum, int currentIndex)
{
	if (currentIndex >= arraySize) {
		return;
	}

	sum += arrayPointer[currentIndex];

	currentIndex++;

	calcuateSumOfElementAfterMinimalElementRecursive(arrayPointer, arraySize, sum, currentIndex);
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
	double* array = new double[arraySize];

	cout << "Input array elements:\n";
	for (int i = 0; i < arraySize; ++i)
	{
		std::cin >> array[i];
	}

	cout << "Array after input: ";
	PrintRec(array, arraySize, 0);
	cout << '\n';

	int minimalElementIndex = 0;
	findMinimalElementIndexRecursive(array, arraySize, minimalElementIndex, 0);
	calcuateSumOfElementAfterMinimalElementRecursive(array, arraySize, sum, minimalElementIndex + 1);
	cout << "\nSum of erlements, after minimum element = ";
	cout << sum;

	calcuateAmountOfElementsEqualsToZeroRecursive(array, arraySize, 0, n);
	cout << "\nCount Of Elements, equals to zero = ";
	cout << n;

	cout << "\nSorted Array By Module Increase:";
	SortByModuleRecursive(array, arraySize, 0);
	PrintRec(array, arraySize, 0);
	cout << '\n';

	delete[] array;
}