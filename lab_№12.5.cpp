/*
Необхідно:
-сформувати заданий список(списки);
-роздрукувати його(їх) – вивести значення елементів на екран;
-виконати вказані в завданні дії;
-вивести результат на екран.
*/


//  Побудувати стек, елементами якого є слова тексту, що зчитуються з текстового
// файлу.Слова відокремлюються одне від одного комами, пробілами та іншими розділовими
// символами.Створити новий стек, в якому містяться слова заданої довжини, що вибрані з
// першого стеку.Вивести вміст першого та другого стеків.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

typedef string Info;
 
struct Elem
{
	Elem* link;
	Info info;
};

struct Second
{
	Second* next;
	Info value;
};

void Punkt_space(string& element)
{
	string punkt = ".,:;!?-'";
	//cout << "Befor :" << element << endl;
	int size = element.size();
	int nummer = element.find_first_of(punkt, 0);
	if (nummer != -1)
	{
		int deleting = size - nummer + 1;
		element.erase(nummer, deleting);
		//cout << "Modifical :" << element << endl;
	}
}
void push(Elem* &top, Info value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	tmp->link = top; // 3
	top = tmp; // 4
}
void OutputWithFILE(Elem* &top, char* fname)
{
	ifstream fin(fname);     // відкрили файл для зчитування
	string element;
	while (fin >> element)     // поки можна виокремити слово
	{
		Punkt_space(element);
		push(top, element);
	}
}
void PrintFirst(Elem* L)
{
	while (L != NULL)
	{
		cout << L->info << " ";
		L = L->link;
	}
	cout << endl;
}
void Chose(int &amount)
{
	cout << "Введіть довжину слова яке буде збережено в іншому стеці : "; cin >> amount;
}
void Push_Second(Second* &sec, Info element)
{
	Second* tmp = new Second;
	tmp->value = element;
	cout << tmp->value << endl;
	tmp->next = sec;
	sec = tmp;
}
void Check(Elem* L, Second* &sec, const int amount, Info element)
{
	while (L != NULL)
	{
		element = L->info;
		int count = element.size();
		if (amount == count)
		{
			Push_Second(sec, element);
		}
		L = L->link;
	}
}
Info pop_first(Elem* &top)
{
	Elem* tmp = top->link;
	Info word = top->info;
	delete top;
	top = tmp;
	return word;
}
Info pop_second(Second* &sec)
{
	Second* tmp = sec->next;
	Info word = sec->value;
	delete sec;
	sec = tmp;
	return word;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Elem* top = NULL;
	Second* sec = NULL;

	char fname[50];  //   ім'я файлу
	cout << "Введіть назву файлу з якого буде\n зчитана інформація з стеку :"; cin >> fname;
	OutputWithFILE(top, fname);   // зчитуємо слова з файлу
	PrintFirst(top);
	//cout << "Кількість значень : " << Count(top) << endl;
	int amount = 0;  // довжина слова
	char ch;  // y/n
	do {
		Chose(amount);    //   вводим довжину слова
		string element;    //  містить в собі слова розміром amount 
		Check(top, sec, amount, element);   //   перевіряємо на наявність слова з довжиною amount
		cout << "Else (Y/N or y/n) ?"; cin >> ch;
    } while (ch == 'Y' || ch == 'y');

	cout << "Перший стек :";
	while (top != NULL) {
		cout << pop_first(top) << " "; // виводмо значення з 1-го стеку
	}
	cout << "\nДругий стек :";
	while (sec != NULL) {
		cout << pop_second(sec) << " "; // виводмо значення з 2-го стеку
	}
	return 0;
}