//Дано текстовий файл t.Відомо, що в цьому файлі є по крайній мірі три крапки.
//Знайти числа і(номер рядка у файлі) та j(номер позиції у рядку) – такі, що sіj – третя
//за порядком крапка(оформити у вигляді функції).
//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

int SuchPunkt1(int& i)
{
	ifstream fin("Hefts.txt");
	char line;
	int k = 0;
	while ((line = fin.get()) > 0) {
		if (line == '.') {
			k++;
			if (k == 3) {

				return i;
			}
		}
		if (line != '\n')
			i++;
	}
	cout << "Nothink";
	return 0;
}
int SuchPunkt2(int& n, int& i)
{
	char line;
	int l = 0;
	ifstream fin("Hefts.txt"); // ім'я файлу
	while ((line = fin.get()) > 0) {
		if (line != '\n')
			l++;
		if (l <= i && line == '\n')
			n++, l++;
	}
	return n;
}
int main()
{
	setlocale(LC_ALL, "rus");
	ifstream fin("Hefts.txt"); // ім'я файлу
	char line[150];
	while (!fin.eof())
	{
		fin.getline(line, sizeof(line));
		cout << line << endl;
	}
	int i = 1;
	int n = 1;
	cout << "\nПозицiя символу : " << SuchPunkt1(i) << endl;
	cout << "\nРядок : " << SuchPunkt2(n, i) << endl;
	cout << "\nThe End" << endl;
	return 0;
}