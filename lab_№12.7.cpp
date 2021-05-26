/*Необхідно:
-сформувати заданий список(списки);
-роздрукувати його(їх) – вивести значення елементів на екран;
-виконати вказані в завданні дії;
-вивести результат на екран.

Побудувати однозв’язний список, елементи якого є цілими числами, що зчитані з
текстового файлу або введені з клавіатури. Видалити зі списку усі парні значення, значення з
непарними номерами подвоїти, вставити в список у задану позицію підсписок із заданою
кількістю елементів. Надрукувати вхідний та вихідний списки.
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <Windows.h>

using namespace std;

typedef int Info;

struct Elem {
    Elem* link,
        * prev;
    Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value);
Info dequeue(Elem*& first, Elem*& last);
int fread(char* fname);
void DeleteParni(Elem*& first, Elem*& last);
void ValueUp(Elem*& first, Elem*& last, Info value);
void Insert(Elem*& first, Elem*& last, Info info, int under);
void Print(Elem*& first);
void Menu();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Menu();

    return 0;
}
void Menu()
{
    Elem* first = NULL,
        * last = NULL;
    char fname[100];
    Info info;
    int k;
    cout << "Яким способом бажаєте записувати значення : " << endl;
    cout << " [1] із клавіатури " << endl;
    cout << " [2] із тексту   " << endl;
    do {
        cout << "1 or 2 : ";
        cin >> k;

        switch (k)
        {
        case 1:
            cout << "Введіть значення(при завершені введіть : 0) : "; cin.getline(fname, sizeof(fname));
            int zahl;
            cin >> zahl;
            while (zahl != 0)
            {
                info = zahl;
                enqueue(first, last, info);
                cin >> zahl;
            }
        case 2:
            cout << "Введіть назву файлу : "; cin.getline(fname, sizeof(fname));
            while (fname) {
                info = fread(fname);
                enqueue(first, last, info);
            }
        default:
            cout << "Alles wird gut, спробуйте ще раз" << endl;
            k = 0;
        }
    } while (k == 0);
    do {
        cout << " Введіть дію : " << endl;
        cout << " [1] видалити зі списку усі парні значення " << endl;
        cout << " [2] значення з непарними номерами подвоїти " << endl;
        cout << " [3] вставити в список у задану позицію підсписок із заданою кількістю елементів " << endl;
        cout << " [4] вивести список на екран " << endl;
        cout << " [0] закінчити роботу прграми " << endl;
        cin >> k;
        switch (k)
        {
        case 1:
            //  DeleteParni(first, last);
        case 2:
            //  ValueUp(first, last, info);
        case 3:
            int under;
            cout << "Вкажіть після якого значення вставити додаткові значення : "; cin >> under;
            //  Insert(first, last, info, under);
        case 4:
            //   Print(first);
        case 0:
            break;
        default:
            cout << "Спробуйте щераз" << endl;
            k = 0;
        }
    } while (k == 0);
}
void Insert(Elem*& first, Elem*& last, Info info, int under)
{
    if (first->info == under)
    {
        int value;
        char ch;
        cout << "Введіть значення яке буде додане до списку : "; cin >> value;
        do {
            Elem* tmp = new Elem;
            tmp->info = value;
            tmp->link = first->link;
            first->link = tmp;
            tmp->link->prev = tmp;
            tmp->prev = first;
            cout << "Додати ще ? (Y/N || y/n)"; cin >> ch;
        } while (ch == 'y' && ch == 'Y');
    }
}
void DeleteParni(Elem*& first, Elem*& last)
{
    Elem* tmp = first->link; // 1
    int n;
    do {
        n = tmp->info;
        if ((n / 2) == 0) {
            delete first; // 3
            first = tmp; // 4
            if (first == NULL)
                last = NULL; // 5
            else
                first->link = tmp; // 6
        }

    } while (tmp != NULL);
}
void ValueUp(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = first;
    do {
        int n = tmp->info;
        tmp->info = pow(n, 2);
        tmp->link = tmp;
    } while (tmp != NULL);
}
int fread(char* fname)
{
    ifstream fin(fname);
    char s;

    while (!fin.eof())
    {
        fin >> s;
    }
    fin.close();
    return s;
}
void Print(Elem*& first)
{
    while (first != NULL)
    {
        cout << first->info;
        first = first->link;
    }
}
void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem; // 1
    tmp->info = value; // 2
    tmp->link = NULL; // 3
    if (last != NULL)
        last->link = tmp; // 4
    tmp->prev = last; // 5
    last = tmp; // 6
    if (first == NULL)
        first = tmp; // 7
}
Info dequeue(Elem*& first, Elem*& last)
{
    Elem* tmp = first->link; // 1
    Info value = first->info; // 2
    delete first; // 3
    first = tmp; // 4
    if (first == NULL)
        last = NULL; // 5
    else
        first->prev = NULL; // 6
    return value; // 7
}