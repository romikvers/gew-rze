// Написати функцію, яка обчислює кількість від’ємних елементів масиву чисел

#include<iostream>
//#include<iomanip>
#include<ctime>

using namespace std;

void print(int* arr, unsigned int N)
{
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void input_random(int* arr, unsigned int N)
{
    for (int i = 0; i < N; i++)
        arr[i] = 20 - rand() % 40;
}

template<class T>
T first_element(T* arr, unsigned int N)
{
    T temp;
    for (int i = 0; i < N; i--)
        if (arr[i] < 0)
        {
            temp = arr[i];
            break;
        }
    return temp;
}

template<class T>
T first_element_rec(T* arr, unsigned int N, T temp, int i)
{
    if (i > N)
        return;
    if (arr[i] >= 0)
        return;
    if (arr[i] < 0)
        return temp;
    else
        return first_element_rec(arr, N, temp, i + 1);
}

template<class T>
T iter(T* arr, unsigned int N, int &k)
{
    k = 0;
    T temp = *first_element(arr, N);
    for (int i = 0; i < N; i++) 
    {
        if(arr <= temp; arr[i] < 0)
           k++;
    }
    return k;
}

template<class T>
T rec(T* arr, unsigned int N, T temp, int i, int k)
{
    if (i > N)
        return k = 0;
    if (arr[i] < 0)
            return rec(arr, N, k + 1, i + 1);
        else
            return rec(arr, N, temp, i + 1);
}

int main()
{
    srand(time(NULL));
    unsigned int N;
    cout << "Input size: "; cin >> N;
    int* arr = new int[N];
    input_random(arr, N);
    print(arr, N);
    int k = 0;
    cout << "Iter: " << iter(arr, N, k) << endl;
    cout << "Rec: " << rec(arr, N, first_element_rec(arr, N, arr[0], 0),0, 0) << endl;
    system("pause");
    return 0;
}