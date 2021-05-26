//Сформувати масив структур, що містять інформацію про : прізвище
//студента, курс, спеціальність(для представлення спеціальності використовувати переліки, а
//для представлення курсу – цілі числа) та оцінки з фізики, математики, інформатики
/*
1. Програма має дати користувачеві можливість фізично впорядкувати масив в першу
    чергу – за значенням оцінки з третього – профільного – предмету, в другу чергу(для
	однакових оцінок з третього предмету) – за назвою спеціальності, в останню чергу
	(для однакових оцінок з третього предмету і спеціальностей) – за прізвищем за
	зростанням – в алфавітному порядку.
2. Програма має будувати індексний масив, який забезпечує наступне індексне
	впорядкування : в першу чергу – за значенням оцінки з третього – профільного –
	предмету, в другу чергу(для однакових оцінок з третього предмету) – за назвою
	спеціальності, в останню чергу(для однакових оцінок з третього предмету і
		спеціальностей) – за прізвищем.
3. За допомогою бінарного пошуку визначити, чи навчається студент із вказаним
	користувачем прізвищем на вказаній спеціальності та вказаною оцінкою з третього
	предмету.
*/




#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Specialnist { ComputerScience, Informatyka, Mathematicsandconomics, PhysicsandInformatyka, Worktraining };
string specStr[] = { "Комп’ютерні науки", "Інформатика", "Математика та економіка", "Фізика та інформатика", "Трудове навчання" };

struct Lehrer
{
	string prizvandname;
	unsigned kurs;
	Specialnist spec;
	int Physical;
	int Math;
	union
	{
		int Programing;
		int Cuselnimetodu;
		int Pedagogika;
	};
};

void Create(Lehrer* p, const int N);
void Print(Lehrer* p, const int N);
void Sort(Lehrer* p, const int N);
int BinSearch(Lehrer* p, const int N, const string prizv, const Specialnist spec, const int value);
int* IndexSort(Lehrer* p, const int N);
void PrintIndexSorted(Lehrer* p, int* I, const int N);
//void SaveToFile(Pracivnyk* p, const int N, const char* filename);
//void LoadFromFile(Pracivnyk*& p, int& N, const char* filename);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть кількість студентів N: "; cin >> N;

	Lehrer* p = new Lehrer[N];

	double proc;
	unsigned kurs;
	Specialnist spec;
	int ispec;
	string prizvandname;
	int Physical;
	int Math;
	int Programing;
	int Cuselnimetodu;
	int Pedagogika;
	int found;

	int menuItem;
	//int ispec;
	int i;
	//int value;
	//int found;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - Фізичне впорядкування даних" << endl;
		cout << " [4] - бінарний пошук студента за оцінкою та прізвищем" << endl;
		cout << " [5] - індексне впорядкування та вивід даних" << endl;
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
			Sort(p, N);
			Print(p, N);
		case 4:
			cout << "Введіть ключі пошуку : " << endl;
			int ispec;
			cout << "Прізвище : "; getline(cin, prizvandname);
			cout << "\nСпеціальність (0 - Комп’ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання) : ";
			cin >> ispec;
			spec = (Specialnist)ispec;
			cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
			cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
			cout << "Який з перелічих предметiв вивчає студент ( 0 - Programing, 1 - Cuselnimetodu, 2 - Pedagogika) : ";
			cin >> i;
			int value;
			cout << "Введіть оцінку з 3-го предмета : "; cin >> value;
			cout << endl;
			switch (p[i].spec) {
			case ComputerScience:
				value = p[i].Programing;
			case Informatyka:
				value = p[i].Cuselnimetodu;
			case Mathematicsandconomics:
			case PhysicsandInformatyka:
			case Worktraining:
				value = p[i].Pedagogika;
				break;
			}
			int found;
			if ((found = BinSearch(p, N, prizvandname, spec, value)) != -1)
				cout << "Знайдено працівника в позиції " << found + 1 << endl;
			else
				cout << "Шуканого працівника не знайдено" << endl;
			break;
		case 5:
			PrintIndexSorted(p, IndexSort(p, N), N);
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	return 0;
}
void Create(Lehrer* p, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "Працівник № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

		cout << " Прізвище та ім'я: "; getline(cin, p[i].prizvandname);
		cout << " курс: "; cin >> p[i].kurs;
		cout << "Cпеціальність ( 0 - Комп’ютерні науки, 1 - Інформатика, 2 - Математика та економіка,";
		cout << "3 - Фізика та інформатика, 4 - Трудове навчання : ";
		cin >> spec;
		p[i].spec = (Specialnist)spec;
		switch (p[i].spec)
		{
		case ComputerScience:
			cout << " Оцінка з Програмування: "; cin >> p[i].Programing;
			break;
		case Informatyka:
			cout << " Оцінка з Програмування: "; cin >> p[i].Cuselnimetodu;
			break;
		case Mathematicsandconomics:
		case PhysicsandInformatyka:
		case Worktraining:
			cout << " Оцінка з Педагогіки:"; cin >> p[i].Pedagogika;
			break;
		}
		cout << " Оцінка з Фізики: "; cin >> p[i].Physical;
		cout << " Оцінка з Математики: "; cin >> p[i].Math;

		cout << endl;
	}
}
void Print(Lehrer* p, const int N)
{
	cout << "================================================================================================================================="
		<< endl;
	cout << "| № |      Прізвище       | Курс |      Спеціальність      | Фізика | Математика | Програмування | Чисельні методи | Педагогіка |"
		<< endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(20) << left << p[i].prizvandname << "| " << setw(4) << right << p[i].kurs << " ";
		cout << "| " << setw(24) << left << specStr[p[i].spec];
		cout << "| " << setw(6) << setprecision(2) << fixed << right << p[i].Physical << right << " |";
		cout << " " << setw(10) << right << p[i].Math << " |";
		cout << " " << setw(13) << right << p[i].Programing << " |";
		cout << " " << setw(15) << right << p[i].Cuselnimetodu << " |";
		cout << " " << setw(10) << right << p[i].Pedagogika << " |" << endl;
	}
	cout << "=================================================================================================================================" << endl;
	cout << endl;
}
int BinSearch(Lehrer* p, const int N, const string prizvandname, const Specialnist spec, const int value)
{
	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		if (p[m].prizvandname == prizvandname && p[m].spec == spec && (p[m].Programing == value ||
			p[m].Cuselnimetodu == value || p[m].Pedagogika == value))
			return m;
		if ((p[m].spec < spec) && (p[m].prizvandname < prizvandname)
			&& (p[m].Programing < value ||
				p[m].Cuselnimetodu < value || p[m].Pedagogika < value))
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;
}
void Sort(Lehrer* p, const int N)
{
	Lehrer tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // метод "бульбашки"
	{
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
		{
			if (p[i1].spec == ComputerScience)
			{
				if ((p[i1].Programing > p[i1 + 1].Programing ||
					p[i1].Programing > p[i1 + 1].Cuselnimetodu ||
					p[i1].Programing > p[i1 + 1].Pedagogika)
					||
					((p[i1].Programing == p[i1 + 1].Programing ||
						p[i1].Programing == p[i1 + 1].Cuselnimetodu ||
						p[i1].Programing == p[i1 + 1].Pedagogika) &&
						p[i1].kurs > p[i1 + 1].kurs)
					||
					((p[i1].Programing == p[i1 + 1].Programing ||
						p[i1].Programing == p[i1 + 1].Cuselnimetodu ||
						p[i1].Programing == p[i1 + 1].Pedagogika) &&
						p[i1].kurs == p[i1 + 1].kurs &&
						p[i1].prizvandname < p[i1 + 1].prizvandname))
				{
					tmp = p[i1];
					p[i1] = p[i1 + 1];
					p[i1 + 1] = tmp;
				}
			}
			if (p[i1].spec == Informatyka)
			{
				if ((p[i1].Cuselnimetodu > p[i1 + 1].Programing ||
					p[i1].Cuselnimetodu > p[i1 + 1].Cuselnimetodu ||
					p[i1].Cuselnimetodu > p[i1 + 1].Pedagogika)
					||
					((p[i1].Cuselnimetodu == p[i1 + 1].Programing ||
						p[i1].Cuselnimetodu == p[i1 + 1].Cuselnimetodu ||
						p[i1].Cuselnimetodu == p[i1 + 1].Pedagogika) &&
						p[i1].kurs > p[i1 + 1].kurs)
					||
					((p[i1].Cuselnimetodu == p[i1 + 1].Programing ||
						p[i1].Cuselnimetodu == p[i1 + 1].Cuselnimetodu ||
						p[i1].Cuselnimetodu == p[i1 + 1].Pedagogika) &&
						p[i1].kurs == p[i1 + 1].kurs &&
						p[i1].prizvandname < p[i1 + 1].prizvandname))
				{
					tmp = p[i1];
					p[i1] = p[i1 + 1];
					p[i1 + 1] = tmp;
				}
			}
			if (p[i1].spec == Mathematicsandconomics || p[i1].spec == PhysicsandInformatyka || p[i1].spec == Worktraining)
			{
				if ((p[i1].Pedagogika > p[i1 + 1].Programing ||
					p[i1].Pedagogika > p[i1 + 1].Cuselnimetodu ||
					p[i1].Pedagogika > p[i1 + 1].Pedagogika)
					||
					((p[i1].Pedagogika == p[i1 + 1].Programing ||
						p[i1].Pedagogika == p[i1 + 1].Cuselnimetodu ||
						p[i1].Pedagogika == p[i1 + 1].Pedagogika) &&
						p[i1].kurs > p[i1 + 1].kurs)
					||
					((p[i1].Pedagogika == p[i1 + 1].Programing ||
						p[i1].Pedagogika == p[i1 + 1].Cuselnimetodu ||
						p[i1].Pedagogika == p[i1 + 1].Pedagogika) &&
						p[i1].kurs == p[i1 + 1].kurs &&
						p[i1].prizvandname < p[i1 + 1].prizvandname))
				{
					tmp = p[i1];
					p[i1] = p[i1 + 1];
					p[i1 + 1] = tmp;
				}
			}
		}
	}
}
int* IndexSort(Lehrer* p, const int N)
{ 
	int* I = new int[N]; // створили індексний масив
	for (int i = 0; i < N; i++)
		I[i] = i; // заповнили його початковими даними

		int i, j, value; // починаємо сортувати масив індексів
		for (i = 1; i < N; i++)
		{
			value = I[i];
			for (j = i - 1;
				j >= 0 && ((p[I[j]].Pedagogika > p[value].Programing ||
					p[I[j]].Pedagogika > p[value].Cuselnimetodu ||
					p[I[j]].Pedagogika > p[value].Pedagogika) ||
					    ((p[I[j]].Pedagogika == p[value].Programing ||
						p[I[j]].Pedagogika == p[value].Cuselnimetodu ||
						p[I[j]].Pedagogika == p[value].Pedagogika) &&
					    p[I[j]].kurs > p[value].kurs) ||
					         ((p[I[j]].Pedagogika == p[value].Programing ||
						     p[I[j]].Pedagogika == p[value].Cuselnimetodu ||
						     p[I[j]].Pedagogika == p[value].Pedagogika) &&
						     p[I[j]].kurs == p[value].kurs &&
					         p[I[j]].prizvandname > p[value].prizvandname));
				j--)
			{
				I[j + 1] = I[j];
			}
			I[j + 1] = value;
		}
	return I;
}
void PrintIndexSorted(Lehrer* p, int* I, const int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << "================================================================================================================================="
		<< endl;
	cout << "| № |      Прізвище       | Курс |      Спеціальність      | Фізика | Математика | Програмування | Чисельні методи | Педагогіка |"
		<< endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(20) << left << p[I[i]].prizvandname << "| " << setw(4) << right << p[I[i]].kurs << " ";
		cout << "| " << setw(24) << left << specStr[p[I[i]].spec];
		cout << "| " << setw(6) << setprecision(2) << fixed << right << p[I[i]].Physical << right << " |";
		cout << " " << setw(10) << right << p[I[i]].Math << " |";
		cout << " " << setw(13) << right << p[I[i]].Programing << " |";
		cout << " " << setw(15) << right << p[I[i]].Cuselnimetodu << " |";
		cout << " " << setw(10) << right << p[I[i]].Pedagogika << " |" << endl;
	}
	cout << "=================================================================================================================================" << endl;
	cout << endl;
	}
	cout << "=========================================================================" << endl;
	cout << endl;
}
