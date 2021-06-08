//Дано літерний рядок, який містить послідовність символів s0, ..., sn, ... .Відомо, що
//серед цих символів є по крайній мірі три крапки.
//1.  Знайти число і таке, що sі – третя за порядком крапка.
//2.  Замінити кожний четвертий символ крапкою.

// Два в одному

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

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

	char* tmp = new char[l + 1];
	char* t = tmp;
	
	tmp[0] = '\0';
	int k = 0, m = 3;
	while (str[k] != NULL)
	{
		if (k == m)
		{
			strcat(t, ".");
			m += 4;
			t++;
			k++;
		}
		else
		{
		    *t++ = str[k++];
			*t = '\0';
		}
	}
	*t++ = str[k++];
	*t++ = str[k++];
	*t = '\0';

	strcpy(str, tmp);

	return tmp;
}
int main()
{
	setlocale(LC_ALL, "rus");
	char str[101];

	cout << "Enter string:" << endl;
	cin.getline(str, 150);
	cout << "String contained " << Street(str) << " groups of later" << endl;
    cout << "Лiтерний рядок до обробки : " << str << endl;
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (result) : " << dest << endl;
	
	return 0;
}