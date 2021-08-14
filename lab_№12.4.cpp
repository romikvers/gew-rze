//Збільшити значення інформаційного поля кожного елемента списку на задану 
//користувачем величину.

#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

typedef int Info;

struct Elem
{
    Elem* link,
        * prev;
    Info  info;
};

void enqueue(Elem*& first, Elem*& last, Info value);
void Print(Elem* L);
int Such_Equal(Elem* L);
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

    cout << "Перівіряємо чи перший елемент рівний останьому елементу :" << endl;
    int first_last = Such_Equal(first);
    if (first_last == 1)
    {
        cout << "Перший елемент рівний останьому" << endl;
    }
    else
    {
        cout << "Перший елемент не рівний останьому" << endl;
    }

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
int Such_Equal(Elem* L)
{
    Elem* T = L;
 
    Info first = T->info;
    Info last = 0;
    while(T != NULL)
    {
        last = T->info;
        T = T->link;
    }
    if (first == last)
    {
        return 1;
    }
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