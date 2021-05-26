//Групи символів, відокремлені пробілами(одним або кількома), відмінні від знаків
//пунктуації і які не містять пробілів, будемо називати словами.
//Переписати його вміст у текстовий файл t2, при цьому : якщо слово записано після
//крапки – то замінити першу букву в цьому слові відповідною великою буквою.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

void PrintTXT() // виведення файлу на екран
{
	ifstream fin("labrabra.txt"); // відкрили файл для зчитування
	string s;                     // прочитаний рядок
	while (getline(fin, s))       // поки можна прочитати рядок
	{
		cout << s << endl;        // виводимо його на екран
	}
	cout << endl;
}
int ProcessTXT3()
{
	string upper = "abcdefghijklmnopqrstuvwxyz";

	ifstream fin("Hefts.txt"); // відкрили файл для зчитування
	ofstream fout;
	//fin.open("Hefts.txt", 'r');
	fout.open("labrabra.txt", 'w');
	string s; // прочитаний рядок
	string S;  // ПОТІК ВСЬОГО ТЕКСТУ
	int k = 0;
	while (getline(fin, s)) // поки можна прочитати рядок
	{
		S += s;
	}
	for (unsigned i = 0; i < S.length(); i++) {
		if (S[i] == '.') {
			k = S.find_first_of(upper, i);
			if (k == -1)
				return 0;
			else
				S[k] = toupper(S[k]);
		}
		if (S[i] == '\n') {
			cout << endl;
			return 0;
		}
		fout << S[i];
	}
	//fin.close();
	fout.close();
	return 0;
}

int main()
{
	setlocale(LC_ALL, "rus");
	// text files
	string line;
	ifstream fin("Hefts.txt"); // ім'я першого файлу

	cout << "Hefts.txt :" << endl; // вивели вміст першого файлу на екран
	while (getline(fin, line)) {   // зчитуємо по рядку
		cout << line;
		cout << "\n";
	}
	cout << "Модифiкований текст : " << ProcessTXT3() << endl;
    PrintTXT();  // виводимо модифікований текст
	return 0;
}