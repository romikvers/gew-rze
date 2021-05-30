//lab№11.1.cpp :
//Сформувати файл даних, компонентами якого є числа.
//Записати в інший файл даних середнє арифметичне максимальної і мінімальної
//компоненти і середнє арифметичне всіх компонент.
//Вивести на екран вміст результуючого файлу.

#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

void CreateBIN(const char* fname) // створення файлу символів з введених рядків
{
	srand((unsigned)time(NULL));
	int N, x;
	cout << "Кiлькiсть значень у файлi: "; cin >> N;
	ofstream f(fname, ios::binary); // відкрили файл для запису
	for (int i = 0; i <= N - 1; i++)  // скануємо введений рядок
	{
		x = 0 + rand() % 21;
		f.write((char*)&x, sizeof(x));  // записали символ у файл
	}
	cout << endl;
}
void PrintBIN(char* fname)
{
	ifstream fin(fname, ios::binary);
	if (!fin)
	{
		cerr << "Error opening file '" << fname << "'" << endl;
		return;
	}
	int c;
	while (fin.read((char*)&c, sizeof(c)))
	{
		cout << c << " ";

	}
	cout << endl;
	fin.close();
}
void ValueSER(char* fname, char* gname)
{
	ifstream f(fname, ios::binary);
	ofstream h(gname, ios::binary);
	if (!f)
	{
		cout << "Nothing" << endl;
	}

	float L = 0, S = 0;
	int x, k = 0;

	while (f.read((char*)&x, sizeof(x)))
	{

		k++;
		S += x;
	}
	L = S / k;
	cout << "\nL value : " << L;
	cin.get();
	cin.sync();
	h.write((char*)&L, sizeof(L));
	f.close();
	h.close();
}
void ValueMaxMin(char* fname, char* gname)
{
	ifstream f(fname, ios::binary);
	ofstream h(gname, ios::binary);

	int L = 0, i = 0, max = 0, min = 0, x;

	while (f.read((char*)&x, sizeof(x)))
	{
		if (i == 0)
		{
			min = x;
			max = x;
		}
		if (min > x)
		{
			min = x;
		}
		if (max < x)
		{
			max = x;
		}
		i++;
	}
	L = (max + min) / 2.0;

	h.write((char*)&L, sizeof(L));
	f.close();
	h.close();
}
int main()
{
	setlocale(LC_ALL, "rus");
	char fname[64]; // ім'я першого файлу
	cout << "Введiть номер 1-го файлу : "; cin.getline(fname, sizeof(fname));
	CreateBIN(fname); // ввели рядки файлу з клавіатури
	PrintBIN(fname); // вивели вміст першого файлу на екран
	cout << "\n_____________________________" << endl;

	char gname[64]; // ім'я другого файлу
	cout << "\nВведiть номер 2-го файлу : "; cin >> gname;
	cout << "Среднє арифметичне значення  : " << endl;
	ValueSER(fname, gname);
	cout << "\n-------------" << endl;
	cout << "Среднє значення мiж мiнiмальним i максимальним значенням : " << endl;
	ValueMaxMin(fname, gname);
	PrintBIN(gname); // вивели вміст другого файлу на екран
	return 0;
}