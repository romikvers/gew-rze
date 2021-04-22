// 1. Обчислити кількість кожної з оцінок «5», «4», «3» з програмування.
// 2. Обчислити процент студентів, які отримали і з фізики і з математики оцінки «4» або «5».
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

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Specialnist { ComputerScience, Informatyka, Mathematicsandconomics, PhysicsandInformatyka, Worktraining};
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
double LineSearch(Lehrer* p, const int N);
double LineSearchPrograming(Lehrer* p, const int N);
//void Sort(Pracivnyk* p, const int N);
//int BinSearch(Pracivnyk* p, const int N, const string prizv, const Posada posada);
//int* IndexSort(Pracivnyk* p, const int N);
//void PrintIndexSorted(Pracivnyk* p, int* I, const int N);
//void SaveToFile(Pracivnyk* p, const int N, const char* filename);
//void LoadFromFile(Pracivnyk*& p, int& N, const char* filename);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть кількість працівників N: "; cin >> N;

	Lehrer* p = new Lehrer[N];

	double proc;
	unsigned kurs;
	Specialnist spec;
	string prizvandname;
	int Physical;
	int Math;
	int Programing;
	int Cuselnimetodu;
	int Pedagogika;

	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - Процент студентів, які отримали і з фізики і з математики оцінки «4» або «5»." << endl;
		cout << " [4] - Кількість  студентів які отримали оцінку 3 - 5 з програмування" << endl;
		//cout << " [5] - бінарний пошук працівника за посадою та прізвищем" << endl;
		//cout << " [6] - індексне впорядкування та вивід даних" << endl;
		//cout << " [7] - запис даних у файл" << endl;
		//cout << " [8] - зчитування даних із файлу" << endl << endl;
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
			proc = LineSearch(p, N);
			cout << "Процент студентів, які отримали і з фізики і з математики оцінки «4» або «5» : " << endl;
			cout << proc << "%" << endl;
			break;
		case 4:
			cout << " Кількість  оцінок з програмування " << endl;
			LineSearchPrograming(p, N);
			break;
			/*case 5:
				cout << "Введіть ключі пошуку:" << endl;
				cout << " kurs (0 - робітник, 1 - інженер, 2 - службовець): ";
				cin >> kurs;
				predmet = (Specilnist)kurs;
				cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
				cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

				cout << " прізвище: "; getline(cin, prizvandname);
				cout << endl;
				if ((found = BinSearch(p, N, prizvandname, predmet)) != -1)
					cout << "Знайдено працівника в позиції " << found + 1 << endl;
				else
					cout << "Шуканого працівника не знайдено" << endl;
				break;
			case 6:
				PrintIndexSorted(p, IndexSort(p, N), N);
				break;
			case 7:
				cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
				cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

				cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
				SaveToFile(p, N, filename);
				break;
			case 8:
				cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
				cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

				cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
				LoadFromFile(p, N, filename);
				break;*/
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
		switch(p[i].spec)
		{
		case ComputerScience :
			cout << " Оцінка з Програмування: "; cin >> p[i].Programing;
			break;
		case Informatyka :
			cout << " Оцінка з Програмування: "; cin >> p[i].Cuselnimetodu;
			break;
		case Mathematicsandconomics :
		case PhysicsandInformatyka :
		case Worktraining :
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
double LineSearch(Lehrer* p, const int N)
{
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].Physical && p[i].Math)
		{
			n++;
			if (p[i].Physical >= 4 && p[i].Math >= 4)
			{
				k++;
			}
		}
	}
	return 100.0 * k / n;
}
double LineSearchPrograming(Lehrer* p, const int N)
{
	int k = 0, l = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].Programing)
		{
			if (p[i].Programing == 5) {
				k++;
			}
			if (p[i].Programing == 4) {
				l++;
			}
			if (p[i].Programing == 3) {
				n++;
			}
		}
	}
	cout << " Кількість  студентів які отримали оцінку " << endl;
	cout << "«5» з програмування : " << k << endl;
	cout << " Кількість  студентів які отримали оцінку " << endl;
	cout << "«4» з програмування : " << l << endl;
	cout << " Кількість  студентів які отримали оцінку " << endl;
	cout << "«3» з програмування : " << n << endl;
	return 0;
}