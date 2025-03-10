#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#define MAX_SIZE 20

// - вывести информацию о самолетах с максимальной 
// грузоподъемностью в порядке возрастания года выпуска; 
// - определить количество самолетов, грузоподъемность 
// которых меньше заданной

struct Plane
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

void Input(struct Plane planes[], int plane_count)
{
	for (int i = 0; i < plane_count; i++)
	{
		puts("================================================");
		printf_s("Самолёт #%d\n", i + 1);
		planes[i].number = input_int("Введите бортовой номер:");
		printf_s("Введите марку: ");
		scanf("%s", &planes[i].mark);
		planes[i].capacity = input_int("Введите вместимость:");
		planes[i].weight = input_double("Введите грузоподъёмность:");
		planes[i].year = input_int("Введите год выпуска:");
	}
}

void Output(struct Plane planes[], int plane_count)
{
	puts("================================================================================================");
	puts("|| # || Бортовой номер || Вместимость || Грузоподъемность || Год выпуска ||       Марка       ||");
	puts("================================================================================================");

	for (int i = 0; i < plane_count; i++)
	{
		printf_s("||%2d || %9d      || %7d     || %10.2lf       || %8d    || %10s        || \n", \
			i + 1, planes[i].number, planes[i].capacity, planes[i].weight, planes[i].year, planes[i].mark);
	}

	puts("================================================================================================");
}

double Max_Weight_Find(struct Plane planes[], int plane_count)
{
	double temp = planes[0].weight;
	for (int i = 1; i < plane_count; i++)
	{
		planes[i].weight > temp ? temp = planes[i].weight : temp;
	}
	return temp;
}

int Max_Weight_Arr(struct Plane planes[], int plane_count, double max_weight_value, struct Plane planes_max_weight[])
{
	int j = 0;
	for (int i = 0; i < plane_count; i++)
	{
		if (planes[i].weight == max_weight_value)
		{
			planes_max_weight[j] = planes[i];
			j++;
		}
	}
	return j;
}

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Plane planes[MAX_SIZE];

	int plane_count = input_int("Введите количество самолётов:");
	Input(planes, plane_count); // Вводим самолёты
	Output(planes, plane_count); // Выводим таблицу

	double max_weight_value = Max_Weight_Find(planes, plane_count); // Находим максимальную грузоподъёмность
	struct Plane planes_max_weight[MAX_SIZE]; // Описываем новую структуру

	int plane_max_weight_count = Max_Weight_Arr(planes, plane_count, max_weight_value, planes_max_weight); 
	// Находим количество самолётов с максимальной грузоподъёмностью и заполняем структуру
	Output(planes_max_weight, plane_max_weight_count); // Выводим таблицу

	int flag = 0;
	double weight_input = input_double("Введите грузоподъёмность, по которой хотите провести сравнение: ");
	for (int i = 0; i < plane_count; i++)
	{
		planes[i].weight < weight_input ? flag++ : flag;
	}

	printf_s("Количество самолётов, у которых грузоподъёмность меньше %.2lf равно %d\n", weight_input, flag);

	system("pause");
}