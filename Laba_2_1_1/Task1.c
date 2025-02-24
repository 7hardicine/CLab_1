#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#define MAX_SIZE 20

// - вывести информацию о самолетах с максимальной 
// грузоподъемностью в порядке возрастания года выпуска; 
// - определить количество самолетов, грузоподъемность 
// которых меньше заданной

struct Plain
{
	int number;
	char mark[10];
	int capacity;
	double weight;
	int year;
};

int input_int(char query[])
{
	int number;
	printf_s("%s ", query);
	while (scanf_s("%d", &number) == 0)
	{
		while (getchar() != '\n');
		puts("Ошибка - повторите ввод");
	}
	return number;
}

double input_double(char query[])
{
	double number;
	printf_s("%s ", query);
	while (scanf_s("%lf", &number) == 0)
	{
		while (getchar() != '\n');
		puts("Ошибка - повторите ввод");
	}
	return number;
}

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Plain plains[MAX_SIZE];

	int size = input_int("Введите количество самолётов:");

	for (int i = 0; i < size; i++)
	{
		puts("================================================");
		printf_s("Самолёт #%d\n", i + 1);
		plains[i].number = input_int("Введите бортовой номер:");
		printf_s("Введите марку: ");
		scanf("%s", &plains[i].mark);
		plains[i].capacity = input_int("Введите вместимость:");
		plains[i].weight = input_double("Введите грузоподъёмность:");
		plains[i].year = input_int("Введите год выпуска:");
	}

	puts("================================================================================================");
	puts("|| # || Бортовой номер || Вместимость || Грузоподъемность || Год выпуска ||       Марка       ||");
	puts("================================================================================================");

	for (int i = 0; i < size; i++)
	{
		printf_s("||%2d || %9d      || %7d     || %10.2lf       || %8d    || %10s        || \n", \
			i + 1, plains[i].number, plains[i].capacity, plains[i].weight, plains[i].year, plains[i].mark);
	}

	puts("================================================================================================");

	double temp;

	for (int i = 1; i < size; i++)
	{
		temp = plains[0].weight;
		if (plains[i].weight > temp)
		{
			temp = plains[i].weight;
		}
	}

	int max_weight[MAX_SIZE];
	int max_weight_size = 0;

	for (int i = 0, j = 0; i < size; i++)
	{
		if (plains[i].weight == temp)
		{
			max_weight[j] = i;
			j++;
			max_weight_size++;
		}
	}

	printf_s("Самолёт с максимальной грузоподъёмностью: ");

	for (int i = 0; i < max_weight_size; i++)
	{
		printf_s("#%d, ", max_weight[i] + 1);
	}
	puts("");

	int flag = 0;
	double weight_input = input_double("Введите грузоподъёмность, по которой хотите провести сравнение: ");
	for (int i = 0; i < size; i++)
	{
		plains[i].weight < weight_input ? flag++ : flag;
	}

	printf_s("Количество самолётов, у которых грузоподъёмность меньше %.2lf равно %d\n", weight_input, flag);

	system("pause");
}