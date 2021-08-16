// lab_№12.6.cpp : 

//  Промоделювати процес посадки в літак, що розрахований на 100 місць. В черзі на 
// посадку стоять 100 пасажирів.Першою входить старий чоловік.Зайшовши в салон, він сідає
// на будь - яке випадково вибране місце.Кожний з наступних пасажирів, зайшовши в салон,
// сідає на своє(позначене в білеті) місце, якщо воно вільне, і на будь - яке з вільних – в
// протилежному випадку.Яка ймовірність, що останній в черзі пасажир сяде на своє місце ?

#include <iostream>
#include <time.h>
#include <vector>
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
void PrintTicket(int* Stuhl);
void enqueue(Elem*& first, Elem*& last, Info value);
void Print(Elem* L);
Info dequeue(Elem*& first, Elem*& last);
int Check(const int placepassenger, int* busy, const int size, bool on_off);
int Rechnung(int* Stuhl, int* busy);

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
    CreatTicket(Stuhl);
    PrintTicket(Stuhl);
    int k = Rechnung(Stuhl, busy);

    int size = sizeof(busy) / sizeof(*busy);   // розмір масиву
    Info m = 0; // Особа яка сідає на місце під номером ...
    for (int k = 0; k < size; k++)     //  порядок заповнення пасажирами літак
    {
        m = busy[k];
        enqueue(first, last, m);
    }
    cout << "\nМісця на які сіли пасажири від 1-100 :";
    // Print(first);
    Info value = 0;
    for (int i = 0; i < size; i++)
    {
        value = dequeue(first, last);
        cout << value << " ";
    }
    if(k == 1 || value == busy[size - 1])
    {
       cout << endl;
       cout << "Пасажир сів на місце, яке є вказане в його білеті" << endl;
       cout << endl;
    }
    else {
        cout << endl;
        cout << "Пасажир не сів на місце, яке є вказане в його білеті" << endl;
        cout << endl;
    }
    return 0;
}
void CreatTicket(int* Stuhl)
{
    int buy = 0,    // номер купленого квитка дідом 
        index_buy = 0,
        num_ticket = 0;
    vector<int> ticket{};    //   загружаємо у вектор номера квитків
    for (int num_ticket = 1; num_ticket <= 100; num_ticket++)  //  заповнюємо вектор номерами квитків
    {
        ticket.push_back(num_ticket);
    }
    for (int i = 0; i < 100; i++)   // (індекс це особа, значення - це квиток...
    {
        int size_vec = ticket.size();
        
        index_buy = 1 + rand() % size_vec;    // квиток особи

        buy = ticket[index_buy - 1];   // починаються адреси мисивів з 0

        Stuhl[i] = buy;     //  присвоємо особі з індексом [ i ], значення buy

        ticket.erase(ticket.begin() + index_buy - 1);    // видаляємо елемент з вектору, який вже записаний в масив Stuhl[]
    }
}
void PrintTicket(int* Stuhl)   // зчитуємо 
{
    int k = 1,    //  пасажир №...
        i = 0;    //  квиток з номером крісла...
    cout << "Пасажири з квитками:\n [" << k << "] - " << Stuhl[i];
    for (i = 1; i < 100; i++)
    {
        k = i;
        cout << ", [" << k + 1 << "] - " << Stuhl[i];
    }
}
int Check(const int placepassenger, int* busy, const int size, bool on_off)
{
    for (int i = 0; i < size; i++)
    {
        if (busy[i] == NULL) {
            break;
        }
        if (placepassenger == busy[i]) {
            return false;
        }
    }
    return true;
}
int Rechnung(int* Stuhl, int* busy)
{
    int Mann;    // Номер чоловіка який заходить
    Mann = 0;    // особа яка заходить (дід),  0 - індекс першої особи - ДІДА

    int biletnum = Stuhl[Mann];         // білет діда на якому є номер крісла на яке він має сісти  

    int placeOpa = 1 + rand() % 100;    //   місце, на яке сідає дідо 

    busy[Mann] = placeOpa;           // місця на якому сидить дід, записали як зайняте

    int placepassenger = 0; // Особа займає місце під номером...

    int size = sizeof(busy) / sizeof(*busy);   //  визначаємо загальний розмір масива

    if (biletnum == placeOpa)    // Дідо сів на зазначене в білеті місце
    {
        Mann++;   //   тому що, діда вже записали
        while (Stuhl[Mann] != NULL) {
            placepassenger = Stuhl[Mann];

            busy[Mann] = placepassenger;

            Mann++;
        }
        return 1;
    }
    if (biletnum != placeOpa)       //   дідо не сів на місце під номером biletnum
    {
        int switch_on_off = 0,    // вказує -1- коли в busy[...] є це місця
        busynumm = 0;     //   місце під номером
        do
        {
            Mann++;
            switch_on_off = 0;

                for (int i = 0; i < 100; i++)
                {
                    if (busy[i] == NULL) {
                        break;
                    }
                    if (Stuhl[Mann] == busy[i]) {
                        switch_on_off = 1;
                        break;
                    }
                }
                if (switch_on_off == 0)
                {
                    placepassenger = Stuhl[Mann];
                }
                else
                    if (switch_on_off == 1)
                    {
                        bool chek = true,
                        on_off = true;    // перевіряє чи зайняте задане рандомно місце, true - не зайняте. 
                        do {
                            placepassenger = 1 + rand() % 100;
                        } while ((chek = Check(placepassenger, busy, size, on_off)) == false);
                    }

             busynumm++;
             busy[busynumm] = placepassenger;
        } while (Stuhl[Mann] != NULL);
    }
    return 0;
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