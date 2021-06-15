//Дано літерний рядок, який містить послідовність символів s0, ..., sn, ... .Відомо, що
//серед цих символів є по крайній мірі три крапки.
//2.  Замінити кожний четвертий символ крапкою.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
#include <string>

using namespace std;

char* Change(char* dest, const char* str, char* t, int m, int i)
{
	if (str[i] != 0)
	{
		if (i == m)
		{
			strcat(t, ".");
			return Change(dest, str, t + 1, m + 4, i + 1);
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
			return Change(dest, str, t, m, i);
		}
	}
	else
	{
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		return dest;
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	//char str[101];
	char str[] = "today is good weather";
	//cout << "Enter string:" << endl;
	//cin.getline(str, 150);
	cout << "Лiтерний рядок до обробки : " << str << endl;
	char* dest1 = new char[151];
	dest1[0] = '\0';
	char* dest2;
	dest2 = Change(dest1, str, dest1, 3, 0);
	cout << "Лiтерний рядок пiсля обробки (result) : " << dest2 << endl;

	return 0;
}