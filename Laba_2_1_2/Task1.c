#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>
#define MAX_SIZE 20

/*
- определить среднюю стоимость товара каждого вида на складе;
- вывести информацию о товарах, поступивших в указанный день, цена на которые меньше
*/

struct Date
{
	int day;
	int month;
	int year;
};

struct Good
{
	char type[MAX_SIZE];
	int amount;
	double unit_price;
	struct Date date;
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

void Output(char mess[], struct Good* goods, int goods_count)
{
	printf_s("%s\n", mess);
	puts("========================================================================================");
	puts("|| # || Вид товара || Количество товара || Дата поступления на склад || Цена за штуку ||");
	puts("========================================================================================");

	for (int i = 0; i < goods_count; i++)
	{
		printf_s("||%2d ||%8s    ||%9d          ||%4d%4d%6d             ||%8.2lf       ||\n", \
			i + 1, (goods + i)->type, (goods + i)->amount, (goods + i)->date.day, (goods + i)->date.month, (goods + i)->date.year, (goods + i)->unit_price);
		puts("========================================================================================");
	}
}

void Input(struct Good* goods, int goods_count)
{
	(goods + goods_count)->amount = input_int("Введите количество товаров на складе:");
	(goods + goods_count)->date.day = input_int("Введите день поступления товара на склад:");
	(goods + goods_count)->date.month = input_int("Введите месяц поступления товара на склад:");
	(goods + goods_count)->date.year = input_int("Введите год поступления товара на склад:");
	(goods + goods_count)->unit_price = input_double("Введите цену за товара за шуку:");
	puts("");
}

char* gets(char*);

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Good* goods = (struct Good*)calloc(MAX_SIZE, sizeof(struct Good));
	int Is_Not_Enter = 1;
	int goods_count = 0;

	do
	{
		printf_s("Товар №%d, введите его вид (enter для прекращения ввода):", goods_count + 1);
		if (strcmp(gets((goods + goods_count)->type), "") != 0)
		{
			Input(goods, goods_count);
			while (getchar() != '\n');
			goods_count++;
		}
		else
		{
			Is_Not_Enter = 0;
		}
	} while (Is_Not_Enter);

	Output("Исходный массив:", goods, goods_count);

	goods = (struct Good*)realloc(goods, goods_count * sizeof(struct Good));

	system("pause");
}
