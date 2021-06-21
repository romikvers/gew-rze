#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>

using namespace std;

char* Change(char* s)
{
	char* t = new char[strlen(s)];
	int pos1 = 0;
	int pos = 3;
	*t = 0;


	strcpy(t, s);
	while (t[pos] != '\0')
	{
		t[pos] = '.';
		pos += 4;
	}
	/*
	while (pos <= strlen(s))
	{
		strncat(t, s + pos1, pos);
		strcat(t, ".");
		pos1 = pos + 1;
		pos += 4;
	}
	strcat(t, s + pos1);
	
	//strcpy(s, t);
	*/
	return t;
}
//Today is good weather
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char str[101];

	cout << "Enter string:" << endl;
	cin.getline(str,101);

	char* dest = new char[101];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;

	cin.get();
	return 0;
}
