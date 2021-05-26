//Дано літерний рядок, який містить послідовність символів s0, ..., sn, ... .Відомо, що
//серед цих символів є по крайній мірі три крапки.
//1.  Знайти число і таке, що sі – третя за порядком крапка.
//2.  Замінити кожний четвертий символ крапкою.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
#include <string>
using namespace std;

int Street(char* str, int i, int n)
{
	if (strlen(str) < 2)
		return 0;
	if (str[i] != 0)
	{
		if (str[i] == '.')
		{
			if (n == 3)
			{
				return i + 1;
			}
			else
				return Street(str, i + 1, n + 1);
		}
		else
			return Street(str, i + 1, n);
	}
	else
		return 0;
}

int main()
{
	setlocale(LC_ALL, "rus");
	char str[101];

	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Street(str, 0, 1) << " groups of later" << endl;

	return 0;
} 