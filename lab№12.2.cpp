// lab№12.2.
//Необхідно:
//-сформувати заданий список(списки);
//-роздрукувати його(їх) – вивести значення елементів на екран;
//-виконати вказані в завданні дії;
//-вивести результат на екран

//Визначити, чи список містить пару сусідніх елементів з однаковими значеннями
//інформаційного поля.

#include <iostream>

struct Elem
{
    *top;
    *value;

};
void push(Elem*& top, Info value)
{
    Elem* tmp = new Elem; // 1
    tmp->info = value; // 2
    tmp->link = top; // 3
    top = tmp; // 4
}
void push(Elem*& top, Info value)
{
    Elem* tmp = new Elem; // 1
    tmp->info = value; // 2
    tmp->link = top; // 3
    top = tmp; // 4
}
void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem; // 1
    tmp->info = value; // 2
    tmp->link = NULL; // 3
    if (last != NULL)
        last->link = tmp; // 4
    last = tmp; // 5
    if (first == NULL)
        first = tmp; // 6
}
int main()
{
    
    enqueue(first, last, value);
   
    std::cout << "Hello World!\n";
}

