#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#define MAX_SIZE 20

// - вывести информацию о самолетах с максимальной 
// грузоподъемностью в пор€дке возрастани€ года выпуска; 
// - определить количество самолетов, грузоподъемность 
// которых меньше заданной

struct Plain
{
	int number;
	char mark[20];
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
		puts("ќшибка - повторите ввод");
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
		puts("ќшибка - повторите ввод");
	}
	return number;
}

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Plain plains[MAX_SIZE];

	int size = input_int("¬ведите количество самолЄтов:");

	for (int i = 0; i < size; i++)
	{
		printf_s("—амолЄт #%d", i + 1);
		plains[i].number = input_int("¬ведите бортовой номер:");
		scanf_s("%s", &plains[i].mark);
		plains[i].capacity = input_int("¬ведите вместимость:");
		plains[i].weight = input_double("¬ведите грузоподъЄмность:");
		plains[i].year = input_int("¬ведите год выпуска:");
	}

	for (int i = 0; i < size; i++)
	{
		printf_s("—амолЄт #%d", i + 1);
		printf_s("\nбортовой номер: %d\nвместимость: %d\nгрузоподъЄмность: %lf\nгод выпуска: %d\nмарка: %s", plains[i].number, plains[i].capacity, plains[i].weight, plains[i].year, plains[i].mark);
	}

	system("pause");
}