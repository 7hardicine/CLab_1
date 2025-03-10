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

struct Good
{
	char type[MAX_SIZE];
	int amount;
	double unit_price;
	struct Date date;
};

struct Date
{
	int day;
	int month;
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

void Output(char mess[], struct Good* goods, int goods_count)
{
	printf_s("%s\n", mess);
	puts("========================================================================================");
	puts("|| # || Вид товара || Количество товара || Дата поступления на склад || Цена за штуку ||");
	puts("========================================================================================");

	for (int i = 0; i < goods_count; i++)
	{
		printf_s("||%2d ||%6s      ||%9d          ||%14d             ||%8.2lf       ||\n", \
			i + 1, (goods + i)->type, (goods + i)->amount, (goods + i)->date, (goods + i)->unit_price);
		puts("========================================================================================");
	}
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
			(goods + goods_count)->amount = input_int("Введите количество товаров на складе:");
			(goods + goods_count)->date = input_int("Введите дату поступления товара на склад:");
			(goods + goods_count)->unit_price = input_double("Введите цену за товара за шуку:");
			puts("");
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