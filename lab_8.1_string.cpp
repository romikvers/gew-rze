//Дано літерний рядок, який містить послідовність символів s0, ..., sn, ... .Відомо, що
//серед цих символів є по крайній мірі три крапки.
//2.  Замінити кожний четвертий символ крапкою.


#include <iostream>
#include <string>

using namespace std;

string Change(string& s)
{
	string S = s;
	size_t N = S.length();
	if (3 >= N)
	{
		cout << "Mas ist klein" << endl;
		return S;
	}
	size_t pos = 3;
	while(pos < N)
	{
		S.replace(pos, 1, ".");
		pos += 4;
	}
	return S;
}

int main()
{
	string str = "today is good weather ... ja genau!";

	//cout << "Enter line\n";
	//getline(cin, str);

	string dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	
	return 0;
}