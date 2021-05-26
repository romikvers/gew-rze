//Поміняти місцями елементи списку – перший з другим, третій з четвертим і т.д.


//  Працює 


#include <iostream>
#include <time.h>
#include <Windows.h>

typedef int Info;

struct Elem
{
    Elem* link,
        * prev;
    Info  info;
};

using namespace std;

void enqueue(Elem*& first, Elem*& last, Info value);
void Print(Elem* L);
void Swap(Elem* first);
Info dequeue(Elem*& first, Elem*& last);

int main()
{
    srand((unsigned)time(NULL));
    SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

    Elem* first = NULL,
        * last = NULL;
    int N;

    cout << "Size steck : "; cin >> N;
    for (int i = 1; i <= N; i++) {
        Info m = 1 + rand() % 4;
        enqueue(first, last, m);
    }
    Print(first);

    Swap(first);
    cout << "\nSwap ([1] = [2]; [2] = [1]) : " << endl;
    while (first != NULL) {
        cout << " " << dequeue(first, last);
    }
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
    tmp->prev = last;
    last = tmp;
    if (first == NULL)
        first = tmp;
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
void Swap(Elem* first)
{
    while (first != NULL && first->link != NULL)
    {
        Info value = first->info;
        first->info = first->link->info;
        first->link->info = value;

        first = first->link->link;
    }
}