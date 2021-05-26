//Дано літерний рядок, який містить послідовність символів s0, ..., sn, ... .Відомо, що
//серед цих символів є по крайній мірі три крапки.
//1.  Знайти число і таке, що sі – третя за порядком крапка.
//2.  Замінити кожний четвертий символ крапкою.

#include <iostream>
#include <string>

using namespace std;

int Count(const string s)
{
	int k = 0;
	size_t pos = 0;
	while((pos = s.find('.', pos)) != -1)
	{
		pos++;
		k++;
		if (k == 3)
			return pos;
	}
	cout << "Nothing\n";
	return -1;
}
string Change(string& s) // не працює
{
	int N = s.length();
	if (3 < N)
	{
		for (size_t pos = 3; pos < N - 4; pos + 4)
		{
			s.replace(pos, 1, "..");
		}
		return s;
	}
	cout << "Mas ist klein";
return 0;	
}

int main()
{
	setlocale(LC_ALL, "rus");
	string str;

	cout << "Enter line\n";
	getline(cin, str);
	cout << "\n Lenght punkt\".\"\n" << Count(str) << endl;

	string dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	
	return 0;
}