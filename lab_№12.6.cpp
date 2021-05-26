// lab_№12.6.cpp : 

/*Необхідно:
-сформувати заданий список(списки);
-роздрукувати його(їх) – вивести значення елементів на екран;
-виконати вказані в завданні дії;
-вивести результат на екран.
*/
//  Промоделювати процес посадки в літак, що розрахований на 100 місць. В черзі на 
// посадку стоять 100 пасажирів.Першою входить старий чоловік.Зайшовши в салон, він сідає
// на будь - яке випадково вибране місце.Кожний з наступних пасажирів, зайшовши в салон,
// сідає на своє(позначене в білеті) місце, якщо воно вільне, і на будь - яке з вільних – в
// протилежному випадку.Яка ймовірність, що останній в черзі пасажир сяде на своє місце ?

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

void CreatTicket(int* Stuhl);
int CompareTicket(int* Repeat, int buy);
void PrintTicket(int* Stuhl);
void enqueue(Elem*& first, Elem*& last, Info value);
void Print(Elem* L);
Info dequeue(Elem*& first, Elem*& last);
int Rechnung(Elem*& first, Elem*& last, int* Stuhl, int* busy);

int main()
{
    srand((unsigned)time(NULL));
    SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

    Elem* first = NULL,
        * last = NULL;

    cout << "Size steck = 100" << endl;

    int Stuhl[100]; 
    int busy[100];      //    зайняті місця
    cout << "Білет кожного пасажира :\n";
    CreatTicket(Stuhl);
    PrintTicket(Stuhl);
    int k = Rechnung(first, last, Stuhl, busy);
    if(k == 1)
    {
       cout << "Пасажир сів на місце, яке є вказане в його білеті" << endl;
    }
    else 
       cout << "Пасажир не сів на місце, яке є вказане в його білеті" << endl;
    Info m; // Особа яка сідає на місце під номером ...
    for (int k = 0; k < 100; k++)     //  порядок заповнення пасажирами літак
    {
        m = busy[k];
        enqueue(first, last, m);
    }
    // Print(first);
    cout << "" << dequeue(first, last);

    return 0;
}
void CreatTicket(int* Stuhl)
{
    int buy, k;
    int Repeat[100];
    for (int i = 0; i < 100; i++)
    {
        do {
            buy = 1 + rand() % 100;

            k = CompareTicket(Repeat, buy);
        } while (k == 0);

        Stuhl[i] = buy;

        Repeat[i] = buy;
    }
}
int CompareTicket(int* Repeat, int buy)
{
    for (int l = 0; l < 100; l++)
    {
        if (Repeat[l] == buy) {
            return 0;
        }
    }
    return 1;
}
void PrintTicket(int* Stuhl)
{
    int k = 1, i = 0;
    cout << " [" << k << "] - " << Stuhl[i];
    for (i = 1; i < 100; i++)
    {
        k = i;
        cout << ", [" << k + 1 << "] - " << Stuhl[i];
    }
}
int Rechnung(Elem*& first, Elem*& last, int* Stuhl, int* busy)
{
    int Mann;    // Номер чоловіка який заходить
    Mann = 0;    // перша особа яка заходить (дід)

    int biletnum = Stuhl[Mann];         // білет діда на якому є номер крісла на яке він має сісти  

    int placeOpa = 1 + rand() % 100;    //   місце, за яке сідає дідо 

    busy[Mann] = placeOpa;           // місця на яких вже сидять пасажири

    int placepassenger; // Особа займає місце під номером...
    if (biletnum == placeOpa)    // Дідо сів на зазначене в білеті місце
    {
        while (Stuhl[Mann] != NULL) {
            placepassenger = Stuhl[Mann];

            busy[Mann] = placepassenger;

            Mann++;
        }
        return 1;
    }
    if (biletnum != placeOpa)       //   дідо не сів на місце під номером biletnum
    {
        do
        {
            Mann++;
            int busynumm;     //   місце під номером
            do {
                for (busynumm = 0; busynumm < 100; busynumm++)
                {
                    if (Stuhl[Mann] == busy[busynumm])
                        break;
                }
                if (Stuhl[Mann] != busy[busynumm])
                {
                    placepassenger = Stuhl[Mann];
                }
                else
                    if (Stuhl[Mann] == busy[busynumm])
                    {
                        placepassenger = 1 + rand() % 100;
                    }
            } while (placepassenger != Stuhl[Mann]);

            busy[busynumm++] = placepassenger;

        } while (Stuhl[Mann] != NULL);
       // cout << "Пасажир не сів на місце, яке є вказане в його білеті" << endl;
        return 0;
    }
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
void Print(Elem* L)
{
    while (L != NULL)
    {
        cout << L->info << " ";
        L = L->link;
    }
    cout << endl;
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