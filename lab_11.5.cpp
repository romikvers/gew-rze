/*
Створити масив структур.Кожна структура складається з таких елементів : абонент та
телефон.Для абонента задати його прізвище та адресу.Для телефону задати його номер, вид
оплати(щохвилинна чи абонементна), вартість оплати.Створений масив записати до
бінарного файлу.Передбачити можливість доповнити файл, замінити дані в файлі, видалити
дані з файлу.Реалізувати такі операції : 1) доповнити масив прізвищами абонентів, номери
телефонів яких починаються на задані цифри(імітувати введення нової АТС); 2) видати
список абонентів з щохвилинною оплатою, сума оплати у яких нижче заданого рівня; 3)
визначити номер телефону абонента за заданою адресою.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <errno.h>
#include <Windows.h>

using namespace std;

string paypay[] = { " ", "абонентна", "щохвилина" };

struct Abonent
{
	char prizv[100];
	char adressa[100];
};
struct Phone
{
	char nommer[100];
	int oplata;
	double Value_money;
};
struct People
{
	Abonent abonents;
	Phone phones;
};

void Menu();
void Create(char* fname);
void Print(char* fname);
void Add_data(char* fname, const char* gname);
void Replace_date(char* fname, const int k);
void Delete_date(char* fname);
void A_Litle_money(char* fname);
void Adressa_such(char* fname);
void Print_value(char* fname, const int size, const int k);
void Repariren(char* fname);
void Sort_DATA(char* fname);
int Sort_for_abetka(string first_line, string second_line);
//void Add_data_name_nommer(char* fname, const char* gname);


int main()
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);

Menu();

return 0;
}
void Menu()
{
	People* peopl;
	char fname[50];
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - створити масив та записати до бінарного файлу" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - Додаткові можвивості" << endl;
		cout << " [4] - видати список абонентів з щохвилинною оплатою, \n"
			    "       сума оплати у яких нижче заданого рівня" << endl;
		cout << " [5] - визначити номер телефону абонента за заданою адресою" << endl;
		cout << " [6] - доповнити масив прізвищами абонентів, номери"
			"телефонів яких починаються на задані цифри(імітувати введення нової АТС)" << endl;   // ich muss beendet das
	//	cout << " [7] - доповнити масив прізвищами абонентів, номери"
		//	"телефонів яких починаються на задані цифри(імітувати введення нової АТС)" << endl;   //reconstrucr
		cout << " [7] - сортувати за пріщвищем зверху до низу" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			cin.sync();
			cin.get();
			cout << "Введіть назву файлу в якому хочете зберегти дані : "; cin >> fname;
			Create(fname);
			break;
		case 2:
			cin.sync();
			cin.get();
			Print(fname);
			break;
		case 3:
			cout << " [1] - add to file" << endl;
			cout << " [2] - replace data in file" << endl;
			cout << " [3] - delete data in file" << endl;
			cout << " [0] - back to hear menu" << endl;
			int menuinput;
			cout << "Character input: "; cin >> menuinput;
			switch (menuinput)
			{
			case 1:
				cin.sync();
				cin.get();
				Add_data(fname, "add.txt");
				break;
			case 2:
				cin.sync();
				cin.get();
				int k;
				cout << "Replase date in nommer :"; cin >> k;
				k = k - 1;
				Replace_date(fname, k);
				break;
			case 3:
				cin.sync();
				cin.get();
				Delete_date(fname);
				break;
			default:
				cout << "Ви ввели помилкове значення!"
					"Слід ввести число - номер вибраного пункту меню" << endl;
			}
			break;
		case 4:
			cin.sync();
			cin.get();
			A_Litle_money(fname);
			break;
		case 5:
			cin.sync();
			cin.get();
			Adressa_such(fname);
			break;
		case 6:
			cin.sync();
			cin.get();
			Repariren(fname);
			break;
		/*
		case 7:
			cin.sync();
			cin.get();
			Add_data_name_nommer(fname, "123.txt");
			break;
			*/
		case 7:
			cin.sync();
			cin.get();
			Sort_DATA(fname);
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
}
void Create(char* fname)
{
	ofstream fout(fname, ios::binary);

	People peopl;
	int oplata = 0;
	char ch;
	int i = 0;
	do {
		cout << "Особа № " << i + 1 << ":" << endl;
		cout << "Прізвище :"; cin >> peopl.abonents.prizv;
		cout << "Адреса проживання : "; cin >> peopl.abonents.adressa;
		cout << "Номер телефону : ";  cin >> peopl.phones.nommer;
		cout << "Вид оплати([1] - щохвилинна, [2] - абонементна) : "; cin >> peopl.phones.oplata;
		cout << "Вартість оплати : "; cin >> peopl.phones.Value_money;
		cout << endl;
		if (!fout.write((char*)&peopl, sizeof(People)))
		{
			cerr << "Помилка запису у файл." << endl;
		}
		cout << "Continue(Y/N or y/n): "; cin >> ch;
		i++;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}
void Print(char* fname)
{
	ifstream fin(fname, ios::binary);

	if (fin.eof())
	{
		cout << "Помилка відкриття файлу '" << fname << "'!" << endl;
	}

	People peopl;

	cout << "==========================================================================================================" << endl;
	cout << "| № |     Прізвище   |  Адреса проживання  |    Номер телефону    |    Вид оплати    |  Вартість оплати  |" << endl;
	cout << "----------------------------------------------------------------------------------------------------------" << endl;
	int i = 0;
	while (fin.read((char*)&peopl, sizeof(People)))
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(15) << left << peopl.abonents.prizv;
		cout << "| " << setw(20) << peopl.abonents.adressa << right;
		cout << "| " << setw(21) << right << peopl.phones.nommer;
		cout << "| " << setw(17) << right << paypay[peopl.phones.oplata];
		cout << "| " << setw(18) << right << peopl.phones.Value_money << "|" << endl;
		i++;
	}
	cout << "==========================================================================================================" << endl;
	cout << endl;
}
void Add_data(char* fname, const char* gname)
{
	ifstream fin(fname, ios::binary);
	if (fin.eof())
	{
		cerr << "Error, file " << fname << ".txt << don`t open!" << endl;
	}
	fin.seekg(0, ios::end);
	int size = fin.tellg();
	size = size / sizeof(People);
	fin.seekg(0, ios::beg);

	ofstream g(gname, ios::binary);
	if (g.eof())
	{
		cerr << "Error, file " << fname << ".txt << don`t open!" << endl;
	}
	People peopl;
	int k = 0;
	while (k < size)
	{
		fin.read((char*)&peopl, sizeof(People));
		g.write((char*)&peopl, sizeof(People));
		k++;
	}
	int oplata = 0;
	char ch;
	do {
		k++;
		cout << "Особа № " << k << " :" << endl;
		cout << "Прізвище :"; cin >> peopl.abonents.prizv;
		cout << "Адреса проживання : "; cin >> peopl.abonents.adressa;
		cout << "Номер телефону : ";  cin >> peopl.phones.nommer;
		cout << "Вид оплати([1] - щохвилинна, [2] - абонементна) : "; cin >> peopl.phones.oplata;
		cout << "Вартість оплати : "; cin >> peopl.phones.Value_money;
		cout << endl;
		cout << "Add else(Y/N or y/n): "; cin >> ch;
		if (!g.write((char*)&peopl, sizeof(People)))
		{
			cerr << "Помилка запису у файл." << endl;
		}
	} while (ch == 'y' || ch == 'Y');
	fin.close();
	g.close();

	ofstream fnam(fname, ios::binary);
	ifstream gnam(gname, ios::binary);
	while (gnam.read((char*)&peopl, sizeof(People))) {
		fnam.write((char*)&peopl, sizeof(People));
	}
	fnam.close();
	gnam.close();
	cout << endl;
	cout << "Дані успішно додано" << endl;
	cout << endl;
}
void Replace_date(char* fname, const int k)
{
	ifstream fin(fname, ios::binary);
	if (fin.eof())
	{
		cerr << "Error, file " << fname << ".txt << don`t open!" << endl;
	}
	fin.seekg(0, ios::end);
	int size = fin.tellg();
	size = size / sizeof(People);
	fin.seekg(0, ios::beg);
	
	People* peopl = new People[size];

	fin.read((char*)peopl, size * sizeof(People));

	cout << "\nОсоба № " << k + 1 << ":" << endl;
	cout << "Прізвище :"; cin >> peopl[k].abonents.prizv;
	cout << "Адреса проживання : "; cin >> peopl[k].abonents.adressa;
	cout << "Номер телефону : ";  cin >> peopl[k].phones.nommer;
	cout << "Вид оплати([1] - щохвилинна, [2] - абонементна) : "; cin >> peopl[k].phones.oplata;
	cout << "Вартість оплати : "; cin >> peopl[k].phones.Value_money;
	cout << endl;
	fin.close();
	ofstream fout(fname, ios::binary);
	fout.write((char*)peopl, size * sizeof(People));
	cout << endl;
	cout << "Данні про продукт успішно змінені." << endl << endl;
	fout.close();
}
void Delete_date(char* fname)
{
	ifstream fin(fname, ios::binary);
	fin.seekg(0, ios::end);
	int size = fin.tellg();
	size = size / sizeof(People);
	fin.seekg(0, ios::beg);

	People* peopl = new People[size];

	fin.read((char*)peopl, size * sizeof(People));

	ofstream fout(fname, ios::binary);
	
	char ch;
	int del;
	do {
		cout << "\nDelete data in nommer :"; cin >> del;
		del = del - 1;
		int k = 0;
		while (k < size)
		{
			if (k != del) {
				fout.write((char*)&peopl[k], sizeof(People));
			}
			k++;
		}
		cout << "\nData delete!" << endl;
		cout << "\nAdd else(Y/N or y/n): "; cin >> ch;
	} while (ch == 'Y' || ch == 'y');
}
void A_Litle_money(char* fname)
{
	ifstream fin(fname, ios::binary);

	fin.seekg(0, ios::end);
	int size = fin.tellg();
	size = size / sizeof(People);
	fin.seekg(0, ios::beg);

	People* peopl = new People[size];

	fin.read((char*)peopl, size * sizeof(People));
	
	double value;
	cout << "Charecter input minimal vakue :"; cin >> value;
	cout << "==========================================================================================================" << endl;
	cout << "| № |     Прізвище   |  Адреса проживання  |    Номер телефону    |    Вид оплати    |  Вартість оплати  |" << endl;
	cout << "----------------------------------------------------------------------------------------------------------" << endl;
	for (int k = 0; k < size; k++)
	{
		if ((paypay[peopl[k].phones.oplata] == paypay[2]) && peopl[k].phones.Value_money < value)
		{
			Print_value(fname, size, k);
		}
	}
	cout << "==========================================================================================================" << endl;
	cout << endl;
}
void Print_value(char* fname, const int size, const int k)
{
	ifstream fin(fname, ios::binary);

	People* peopl = new People[size];

	fin.read((char*)&peopl[k], sizeof(People));

		cout << "| " << setw(1) << right << 1 << " ";
		cout << "| " << setw(15) << left << peopl[k].abonents.prizv;
		cout << "| " << setw(20) << peopl[k].abonents.adressa << right;
		cout << "| " << setw(21) << right << peopl[k].phones.nommer;
		cout << "| " << setw(17) << right << paypay[peopl[k].phones.oplata];
		cout << "| " << setw(18) << right << peopl[k].phones.Value_money << "|" << endl;
}
void Adressa_such(char* fname)
{
	ifstream fin(fname, ios::binary);

	fin.seekg(0, ios::end);
	int size = fin.tellg();
	size = size / sizeof(People);
	fin.seekg(0, ios::beg);

	People* peopl = new People[size];

	fin.read((char*)peopl, size * sizeof(People));

	string adressa;
	cout << "Charecter input adressa for such data :"; cin >> adressa;
	cout << "==========================================================================================================" << endl;
	cout << "| № |     Прізвище   |  Адреса проживання  |    Номер телефону    |    Вид оплати    |  Вартість оплати  |" << endl;
	cout << "----------------------------------------------------------------------------------------------------------" << endl;
	int k = 0;
	while (k < size)
	{
		if (peopl[k].abonents.adressa == adressa)
		{
			Print_value(fname, size, k);
			break;
		}
		k++;
	}
	cout << "==========================================================================================================" << endl;
	cout << endl;
}
void Repariren(char* fname)
{
	int line;
	int oplata = 0;
	char ch;
	int menuinput;
	do
	{
		ifstream fin(fname, ios::binary);

		fin.seekg(0, ios::end);
		int size = fin.tellg();
		size = size / sizeof(People);
		fin.seekg(0, ios::beg);

		People* peopl = new People[size];

		fin.read((char*)peopl, size * sizeof(People));
		fin.close();
	
	
		ofstream fout(fname, ios::binary);


			cout << "Charecter input nommer line, who you went reconstruct :"; cin >> line;
			line = line - 1;
			cout << "Repair : " << endl;
			cout << " [1] - Прізвище" << endl;
			cout << " [2] - Адреса проживання" << endl;
			cout << " [3] - Номер телефону" << endl;
			cout << " [4] - Вид оплати" << endl;
			cout << " [5] - Вартість оплати  " << endl;
			cout << "Your choice :" << endl; cin >> menuinput;
			cout << endl;
			cout << "Особа № " << line << " :" << endl;
			switch (menuinput) {
			case 1:
				cout << "Прізвище :"; cin >> peopl[line].abonents.prizv;
				break;
			case 2:
				cout << "Адреса проживання : "; cin >> peopl[line].abonents.adressa;
				break;
			case 3:
				cout << "Номер телефону : ";  cin >> peopl[line].phones.nommer;
				break;
			case 4:
				cout << "Вид оплати([1] - щохвилинна, [2] - абонементна) : "; cin >> peopl[line].phones.oplata;
				break;
			case 5:
				cout << "Вартість оплати : "; cin >> peopl[line].phones.Value_money;
				break;
			}

		if (!fout.write((char*)peopl, size * sizeof(People)))
		{
			cerr << "Error!" << endl;
		}
		fout.close();
		cout << endl;
		cout << "Дані успішно додано" << endl;
		cout << endl;
		cout << "Add else(Y/N or y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}
void Sort_DATA(char* fname)
{
	ifstream fin(fname, ios::binary);
	if (fin.eof())
	{
		cerr << "Файл для зчитування не відкрився!" << fname << endl;
	}

	fin.seekg(0, ios::end);
	int size = fin.tellg();
	size = size / sizeof(People);
	fin.seekg(0, ios::beg);

	People* peopl = new People[size];
	People temp;

	fin.read((char*)peopl, size * sizeof(People));

	fin.close();

	string first_line = " ", second_line = " ";

	int max_value = 1; // value about compare word

	for (int j = 0; j < size - 1; j++)
	{
		for (int i = size - 1; i >= j; i--)
		{
			first_line = peopl[i].abonents.prizv;   //
			second_line = peopl[i - 1].abonents.prizv;
			max_value = Sort_for_abetka(first_line, second_line);
			if (max_value == 2)
			{
				temp = peopl[i - 1];
				peopl[i - 1] = peopl[i];
				peopl[i] = temp;
			}
		}
	}

	ofstream fout(fname, ios::binary);

	if (fout.eof())
	{
		cerr << "Файл для запису не відкрився!" << fname << endl;
	}
	if (!fout.write((char*)peopl, size * sizeof(People)))
	{
		cerr << "Error!" << endl;
	}
	cout << "The data is sorted " << endl;
}
int Sort_for_abetka(string first_line, string second_line)     // від А до Z.
{
	string abetka = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
	int pos = 0,
		fir = 0,
		sec = 0;

		string first_letter = data(first_line);
		string second_letter = data(second_line);

		fir = abetka.find_first_of(first_letter, pos);
		sec = abetka.find_first_of(second_letter, pos);

		cout << "fir :" << fir << first_line << endl;
		cout << "sec :" << sec << second_line << endl;

		if (fir < 0  || sec < 0)
		{
			cout << "Letter is not!" << endl;
			return 1;
		}
		else if (fir < sec)   // 'fir' and 'sec' is position in abetka 
			 {
			   return 2;
	     	 }
	return 1;
}
/*void Add_data_name_nommer(char* fname, const char* gname)
{
	int oplata = 0;
	char ch;
	int menuinput;
	do
	{
		ifstream fin(fname, ios::binary);

		fin.seekg(0, ios::end);
		int size = fin.tellg();
		size = size / sizeof(People);
		fin.seekg(0, ios::beg);
		
		People* peopl = new People[size];

		ofstream gout(gname, ios::binary);

		int k = 0;
		while (k < size)
		{
			fin.read((char*)&peopl, sizeof(People));
			gout.write((char*)&peopl, sizeof(People));
		}
		fin.close();
		gout.close();

		ifstream gin(gname, ios::binary || ios::app);
		cout << "Add data : " << endl;
		cout << endl;
		//cout << "Особа № " << size + 2 << " :" << endl;
		cout << "Прізвище :"; cin >> peopl.abonents.prizv;
		peopl.abonents.adressa;
		cout << "Номер телефону : ";  cin >> peopl[size_place].phones.nommer;
		cout << endl;

		ifstream gin(gname, ios::binary);
		ofstream fout(fname, ios::binary);

		while (gin.read((char*)&peopl, size_place * sizeof(People)))
		{
			fout.write((char*)&peopl, size_place * sizeof(People));
		}

	/*	if (!fout.write((char*)&peopl, sizeof(People)))
		{
			cerr << "Error!" << endl;
		}
		else {
			cout << endl;
			cout << "Дані успішно додано" << endl;
		}
		while (gin.read((char*)&peopl, size * sizeof(People)))
		{
			fout.write((char*)&peopl, size * sizeof(People));
		}
		cin.sync();
		cin.get();
		/*
	    ifstream g(gname, ios::binary);
		ofstream f(fname, ios::binary);
		if (g.write((char*)peopl, size * sizeof(People)))
		{
			cerr << "Error!" << endl;
		}
		g.close();
		f.close();
		cout << endl;
		cout << "Add else(Y/N or y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}*/