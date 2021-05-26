//Дано літерний рядок, який містить послідовність символів s0, ..., sn, ... .Відомо, що
//серед цих символів є по крайній мірі три крапки.
//1.  Знайти число і таке, що sі – третя за порядком крапка.
//2.  Замінити кожний четвертий символ крапкою.

// Працює

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int Street(char* str)
{
	if (strlen(str) < 2)
	{
		return 0;
	}
	int n = 1;
	for (int i = 0; str[i] != 0; i++)
	{ 
		if (str[i] == '.')
		{
			if (n == 3)
			{
				return i + 1;
			}
			n++;
		}
	}
	cout << "Nothing\n";
	return 0;
}
                            //Замінити кожний четвертий символ крапкою.
char* Change(char* str)
{
	if (strlen(str) < 3)
		return str;

	int l = strlen(str);

	char* tmp = new char[strlen(str) + 1];
	char* t = tmp;
	
	int k = 0;
	while (str[k] != 0)
	{ 
		if (str[k] % 4 != 0)
		{
			*t[k] = str[k];
			k++;
		}
		else
			*t[k] = '.';
		    k++;
	}
	*t[k++] = '\0';
	return t;
}

int main()
{
	setlocale(LC_ALL, "rus");
	char str[101];

	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Street(str) << " groups of later" << endl;

	char* dest = new char[102];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;

	return 0;
}