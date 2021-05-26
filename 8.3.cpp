#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int Count(char* str)
{
	if (strlen(str) < 3)
		return 0;
	int k = 0;
	for (int i = 1; str[i + 1] != 0; i++)
		if (str[i - 1] == '+' && str[i + 1] == '-')
			k++;
	return k;
}
char* Change(char* str)
{
	if (strlen(str) < 3)
		return str;
	char* tmp = new char[strlen(str) + 1];
	char* t = tmp;
	tmp[3] = '\0';

	int i = 3;
	{
		strcat(t, ".");

		t += 4;
		i += 4;

	}while(str[i] != 0)

	/*while (str[i] != 0 )
	{
		strcat(t, ".");
		//strcpy(t, str);
		
			t += 4;
			i += 4;
	}*/
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';
	strcpy(str, tmp);

	return tmp;
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Count(str) << " groups of '+ -'" << endl;
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}
