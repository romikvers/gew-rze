// lab№9.3.cpp :
/*Описати структуру з іменем Note, що містить наступні поля :
 прізвище, ім'я;
 номер телефону;
 день народження(масив з трьох чисел).
Написати програму, що виконує наступні дії :
 введення даних з клавіатури в масив, що складається з елементів типу Note;
 впорядкування масиву структур за телефонними номерами;
 вивід на екран інформації про людину, прізвище якої введене з клавіатури; 
якщо такої немає, вивести на екран відповідне повідомлення.*/

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

struct Note
{
	string prizvandname;

	string NommerTelefonu;
	int day;
	int month;
	int year;
};

void Menu(Note* p, const int N);
void Create(Note* p, const int N);
void Print(Note* p, const int N);
int BinSearch(Note* p, const int N, const string prizvandname);
void Sort(Note* p, const int N);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть кількість осіб N : "; cin >> N;

	Note* p = new Note[N];

	Menu(p, N);
	
	return 0;
}
void Menu(Note* p, const int N)
{
	
	int menuItem;
	int found;
	string prizvandname;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - пошук особи за прізвищем та ім'ям" << endl;
		cout << " [4] - сортування за номером телефона" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			cout << "Введіть ключ пошуку " << endl;
			cout << "Прізвище : "; getline(cin, prizvandname);
			cout << endl;
			if ((found = BinSearch(p, N, prizvandname)) != -1)
				cout << "Знайдено особу в позиції " << found + 1 << endl;
			else
				cout << "Шуканої особи не знайдено" << endl;
			break;
		case 4:
			Sort(p, N);
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
}

void Create(Note* p, const int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << "Особа № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

		cout << "Прізвище та ім'я :"; getline(cin, p[i].prizvandname);
		cout << "Номер телефону : "; getline(cin,p[i].NommerTelefonu);
		cout << "Дата народження" << endl;
		cout << "День : "; cin >> p[i].day;
		cout << "Місяць : "; cin >> p[i].month;
		cout << "Рік : "; cin >> p[i].year;

		cout << endl;
	}
}
void Print(Note* p, const int N)
{
	cout << "===========================================================================" << endl;
	cout << "| № |     Прізвище та ім'я     |  Дата народження  |    Номер телефону    |" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(25) << left << p[i].prizvandname;
		cout << "| " << setw(18) << right << p[i].day << "." << p[i].month << "." << p[i].year;
		cout << "| " << setw(21) << right << p[i].NommerTelefonu << "|" << endl;
	}
	cout << "===========================================================================" << endl;
	cout << endl;
}
int BinSearch(Note* p, const int N, const string prizvandname)
{
	int m = N;

	do {
		if (p[m].prizvandname == prizvandname)
			return m;
		if (p[m].prizvandname != prizvandname)
		{
			m--;
		}
	} while (m != 0);
	return -1;
}
void Sort(Note* p, const int N)
{
	Note tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // метод "бульбашки"
	{
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if (p[i1].NommerTelefonu > p[i1 + 1].NommerTelefonu)
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
	}
}