//Дано літерний рядок, який містить послідовність символів s0, ..., sn, ... .Відомо, що
//серед цих символів є по крайній мірі три крапки.
//1.  Знайти число і таке, що sі – третя за порядком крапка.
//2.  Замінити кожний четвертий символ крапкою.

// Працює

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int Street(char* s)
{
	int pos = 0,
		k = 0;

	char* t;
	while (t = strchr(s + pos, '.'))
	{
		pos = t - s + 1;
		k++;
		if (k == 3)
			return pos;
	}
	cout << "NOTHINK";
	return 0;
}
char* Change(char* s, char* punkt)
{ 
	int i;

	for (i = 3; s[i] != 0; i+4)
	{
		strstr(s, punkt);
	}
	s[i++] = '\0';
	return s;
}

int main()
{
	setlocale(LC_ALL, "rus");
	char str[101];
	char punkt[] = ".";

	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Street(str) << " groups of later" << endl;

	char* dest = new char[151];
	dest = Change(str, punkt);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;

	cin.get();
	return 0;
}