/*
 lab_13_2.
 Обчислити площу круга, знайти максимум з двох чисел, використовуючи
 макроси піднесення до квадрата, виведення результатів, знаходження
 максимального значення. За допомогою директив умовної компіляції
 активізувати різні частини програми.
*/
#pragma warning(disable : 4996) // функція scanf застаріла, тому пропускаю попеередження
#include <math.h>
#include <stdio.h>
#include <conio.h>

#define z 1 // директива препроцесора – макровизначення
#define MAX(x, z) (x, z)
#define MIN(x, z) (x + z, x * z)
#define PLUS(value) (fabs(value))
#define SQR(value) (value)*(value)   // макрос з параметром – визначення квадрата числа
#define MULTI(value, k) (pow(value, k))   // макрос визначення найбільшого з двох чисел
#define MOREMAX(a_kvadr, value) ((a_kvadr)>(value))?(a_kvadr):(value) // макрос як умовний вираз

#define SECOND(x, z) pow(pow(abs(x - z), z), 2) // виводимо значення поточного виразу
#define PRINTI(w) puts("control output"); \
 printf(#w"=%d\n",w)
 // використовується символ продовження макроса '\'
 // символ '#' використовується для об’єднання рядків
 // виведення повідомлення та значення дійсного числа
#define PRINTR(w) puts ("rezult :"); \
 printf (#w"=%f",(float)w)

void main()
{
	puts("Lab 13.2. Using macros and preprocessing directive");
	int x, y, k, // змінні для розрахунків
		max, min,
		modul, // модуль
		a_kvadr, // квадрат числа
		value, stepin,
		maxim; // максимальне з трьох чисел
	char ch; // відповідь чи продовжувати виконання програми
	do
	{
#if (5 < z && z < 10) // якщо умова істинна,
		// то шукаємо максимум з трьох чисел
		puts("define maximum of two numbers");
		puts("Input 3 integer numbers");
		puts("x : ");
		scanf("%d", &x);// введення числа
		PRINTI(x); // макрос виведення числа
		puts("y : ");
		scanf("%d", &y);// введення числа
		PRINTI(y); // макрос виведення числа
		puts("z : ");
		PRINTI(z); // макрос виведення числа
		max = MAX(x, z);
		min = MIN(x, z);
		value = min * max;  // розв'язуємо приклад
		PRINTR(value);
		modul = PLUS(value);
		PRINTR(modul); // виводимо значення по модулю
		a_kvadr = SQR(value); // макрос визначення квадрату числа
		PRINTR(a_kvadr);
		puts("Пiднести до степеня в рази - : ");
		scanf("%d", &k);// введення числа
		stepin = MULTI(value, k);
		PRINTR(stepin);  // Виводим значення піднесене до степеня
		puts("Пмаксимальне значення між ЧИСЛОМ(Т) і ЧИСЛОМ(Т) у квадраті  - : ");
		maxim = MOREMAX(a_kvadr, value); // пошук максимуму з двох чисел
		PRINTR(maxim); // макрос виведення результату*/
#else // компілювати іншу частину програми, якщо N >= 10
		{
			puts("define maximum of two numbers");
			puts("Input 3 integer numbers");
			puts("x : ");
			scanf("%d", x);// введення числа
			PRINTI(x); // макрос виведення числа
			puts("z : ");
			PRINTI(z); // макрос виведення числа
			value = SECOND(x, z);  // розв'язуємо приклад
			PRINTR(value);
			modul = PLUS(value);
			puts("Module : ");
			PRINTR(modul); // виводимо значення по модулю
			puts("Корiнь числа : ");
			a_kvadr = SQR(value); // макрос визначення квадрату числа
			PRINTR(a_kvadr);
			puts("Пiднести до степеня в : ");
			scanf("%d", &k);// введення числа
			stepin = MULTI(value, k);
			PRINTR(stepin);
		}
#endif // завершення блоку умовної компіляції
		puts("Repeat? y /n "); ch = getch();
	} while (ch == 'y');
}
