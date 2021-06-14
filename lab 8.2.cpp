#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int MinLength(string &str)
{	
	string ch = " ,.!?";  // пунктуаційні знаки
	string S = str;

	int index,  //  значення першої букви в слові
		start = 0,    //  початок цику(зміне значення)
		che;   //  
	while( S[start] != NULL && start < str.length())
	{
		index = str.find_first_not_of(ch, start); // шукаєм перше значееня після пунктуаційних знаків
		if (index == -1) {
			str = S;   // присвоєння
			return 0;
		}
		else
		    S[index] = toupper(S[index]);   // переводимо першу букву в слові у верхній  регістр
		
		start = index + 1;   // наступний символ після першої букви в слові

		che = str.find_first_of(ch, start);  // шукаємо початок пунктуаційних знаків
		if (che == -1) {
			str = S;   // присвоєння
			return 0;
		}
		else
			start = che;  // значення з якого буде почитатися 2-й цикл
	}
	str = S;  // присвоєння
	return 0;
}
int main()
{
	//SetConsoleCP(1251);  
	SetConsoleOutputCP(1251);
	string str = " hallo, i a`m roman and i live in village.";
	//cout << "Введіть текст : ";
	// getline(cin, str);
	cout << "\nКожну першу букву в слові переводим у верхній регістр : "; 
	MinLength(str);
	cout << str << endl;
	return 0;
}