// lab_№10.3.cpp
//Є текстовий файл, що містить список телефонів друзів, кожний рядок якого містить наступні дані :
// прізвище, ім'я;
// номер телефону;
// день народження(масив з трьох чисел).
//Написати програму, що виконує наступні дії :
// створює, переглядає та поповнює список;
// здійснює виведення на екран інформації про людину, прізвище якої введене з
//клавіатури; якщо такої немає, вивести на екран відповідне повідомлення.

/*Рівень А).Сформувати масив структур, що містять інформацію про : прізвище
студента, курс, спеціальність(для представлення спеціальності використовувати переліки, а
для представлення курсу – цілі числа) та оцінки з фізики, математики, інформатики.
	Рівень В).Сформувати масив структур з об’єднаннями, що містять інформацію
про : прізвище студента, курс, спеціальність(для представлення спеціальності
використовувати переліки, а для представлення курсу – цілі числа) та оцінки з фізики,
математики; якщо спеціальність – «Комп’ютерні науки», то третя оцінка – з програмування;
якщо спеціальність – «Інформатика», то третя оцінка – з чисельних методів; для всіх інших 86
спеціальностей: «Математика та економіка», «Фізика та інформатика», «Трудове навчання» –
третя оцінка – з педагогіки.Для представлення третьої оцінки використовувати об’єднання.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <fstream>
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

void Menu();
void Create(Note* p, const int N);
void Print(Note* p, const int N);
//int Search(Note* p, const int N, const string prizvandname);
//void Sort(Note* p, const int N);
void SaveToFile(Note* p, const int N, char* filename);
void Printofile(char* filename);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char filename[10000];
	cout << "Увведіть назву файлу з якого хочет зчитати інформацію : "; cin.getline(filename, sizeof(filename));
	ifstream fin;
	fin.open(filename);
	while (!fin.eof())
	{
		fin.getline(filename, sizeof(filename));
		cout << filename << endl;
	}
	fin.close();

	Menu();

	return 0;
}
void Menu()
{
	int menuItem;
	char filename[100];
	//int found;
	int N;
	cout << "Кількість осіб яку буде додано : "; cin >> N;
	Note* p = new Note[N];
	string prizvandname;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - створити дані про осіб" << endl;
		cout << " [2] - вивід даних які створили" << endl;
		cout << " [3] - помістити дані у файл" << endl;
		cout << " [4] - вивести файл на екран" << endl;
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
			cin.getline(filename, 10000);
			SaveToFile(p, N, filename);
			break;
		case 4:
			Printofile(filename);
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
}
void Printofile(char* filename)
{
	cout << endl << "\nfile \"" << filename << "\":\n";
	ifstream f(filename);
	string s;
	while (getline(f, s))
	{
		cout << filename << endl;
		cout << endl;
	}
	cout << endl;
	f.close();
}

void Create(Note* p, const int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << "Особа № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

		cout << "Прізвище та ім'я :"; getline(cin, p[i].prizvandname);
		cout << "Номер телефону : "; getline(cin, p[i].NommerTelefonu);
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
void SaveToFile(Note* p, const int N, const char* filename) //  Note - структура
{
	ofstream fout(filename, ios::app); // відкрили файл запису

	for (int i = 1; i < N; i++){   // N - кількість працівників 
		fout.write((char*)&p[i], sizeof(Note));  // сохраняю дание из структури
    }
	cout << "Дані збережено!";
	fout.close(); // закрили файл
}
/*
void LoadFromFile(Pracivnyk*& p, int& N, const char* filename)
{
	delete[] p; // знищили попередні дані
	ifstream fin(filename, ios::binary); // відкрили бінарний файл зчитування
	fin.read((char*)&N, sizeof(N)); // прочитали кількість елементів
	p = new Pracivnyk[N]; // створили динамічний масив
	for (int i = 0; i < N; i++)
		fin.read((char*)&p[i], sizeof(Pracivnyk)); // прочитали елементи масиву
	fin.close(); // закрили файл
}*/
