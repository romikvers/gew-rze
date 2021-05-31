// lab№12.2.
//Необхідно:
//-сформувати заданий список(списки);
//-роздрукувати його(їх) – вивести значення елементів на екран;
//-виконати вказані в завданні дії;
//-вивести результат на екран

//Визначити, чи список містить пару сусідніх елементів з однаковими значеннями
//інформаційного поля.



//  Працює



#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

typedef int Info;

struct Elem
{
    Elem* link;
    Info  info;
};

void enqueue(Elem*& first, Elem*& last, Info value);
void Print(Elem* L);
bool Check(Elem* first);


int main()
{
    SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

    Elem* first = NULL,
        * last = NULL;
    int N, m;

    cout << "Size steck : "; cin >> N;
    for (int i = 1; i <= N; i++) {
        m = 1 + rand() % 3;
        enqueue(first, last, m);
    }

    Print(first);
    cout << "\nВизначаємо чи список місить пару ссусідніх елемнтів : " << endl;
    if (Check(first))
        cout << "Список містить пару сусідніх елементів" << endl;
    else
        cout << "Список не містить пару сусідніх елементів" << endl;
    cout << endl;
    return 0;
}
void Print(Elem* L)
{
    while (L != NULL)
    {
        cout << L->info << " ";
        L = L->link;
    }
    cout << endl;
}
void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}
bool Check(Elem* first)
{
    while (first->link->link != NULL) {
        Info x = first->info;

        if (first->link->info == x) {
            first = first->link;
            if (first->link->info == x) {
                return true;
            }
        }
        else
            first = first->link;
    }
    return false;
}