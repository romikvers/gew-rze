//Збільшити значення інформаційного поля кожного елемента списку на задану 
//користувачем величину.

// Працює

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
void Swap(Elem*& first);
void InfoUp(Elem*& first, int n);
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
    cout << "Список : ";
    Print(first);

    char c;
    int n;
    cout << "\nБажаєте збільшити інформацію кожного поля на n разів(Y/y or N/n) ? " << endl; cin >> c;
    if (c == 'Y' || c == 'y') {
        cout << "n = "; cin >> n;
        InfoUp(first, n);
    }

    cout << "Trans : ";
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
void InfoUp(Elem*& first, int n)
{
    int x = 0;
    Elem* L = first;
    while (L != NULL) {
        x = L->info;
        x += n;
        L->info = x;
        L = L->link;
    }
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