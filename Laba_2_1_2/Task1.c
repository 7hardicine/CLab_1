#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <Windows.h>
#define MAX_SIZE 20

/*
- определить среднюю стоимость товара каждого вида на складе;
- вывести информацию о товарах, поступивших в указанный день, цена на которые меньше ?(средней)
*/

struct Good
{
	char type[MAX_SIZE];
	int amount;
	double unit_price;
	struct tm date;
};

struct GoodsAvCost
{
	char type[MAX_SIZE];
	double summ;
	int count;
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
		printf_s("||%2d ||%8s    ||%9d          ||      %2d.%2d.%4d           ||%8.2lf       ||\n", \
			i + 1, (goods + i)->type, (goods + i)->amount, (goods + i)->date.tm_wday, (goods + i)->date.tm_mon, \
			(goods + i)->date.tm_year, (goods + i)->unit_price);
		puts("========================================================================================");
	}
}

void Input(struct Good* goods, int goods_count)
{
	(goods + goods_count)->amount = input_int("Введите количество товаров на складе:");
	(goods + goods_count)->date.tm_wday = input_int("Введите день:");
	(goods + goods_count)->date.tm_mon = input_int("Введите месяц:");
	(goods + goods_count)->date.tm_year = input_int("Введите год:");
	(goods + goods_count)->unit_price = input_double("Введите цену за товара за шуку:");
	puts("");
}

int GoodsAvCostFunc(struct Good* goods, int goods_count, struct GoodsAvCost* goods_av_cost)
{
	int types_count = 0;
	strcpy((goods_av_cost)->type, (goods)->type);
	for (int i = 0; i < goods_count; i++)
	{
		int flag = -1;
		for (int j = 0; j < types_count; j++)
		{
			if (strcmp((goods + i)->type, (goods_av_cost + j)->type) == 0)
			{
				flag = j;
			}
		}
		if (flag == -1)
		{
			flag = types_count;
			types_count++;
		}
		strcpy((goods_av_cost + flag)->type, (goods + i)->type);
		(goods_av_cost + flag)->count++;
		(goods_av_cost + flag)->summ += (goods + i)->unit_price;
	}
	for (int i = 0; i < types_count; i++)
	{
		printf_s("Вид '%s', средняя стоимость = % .2lf\n", (goods_av_cost + i)->type, ((goods_av_cost + i)->summ / (goods_av_cost + i)->count));
	}
	return types_count;
}

int GoodsThatPriceLess(struct Good* goods, int goods_count, struct Good* goods_less_price)
{
	double average_price = 0;
	for (int i = 0; i < goods_count; i++)
	{
		average_price += (goods + i)->unit_price;
	}
	average_price /= goods_count;
	int goods_less_price_count = 0;
	for (int i = 0; i < goods_count; i++)
	{
		if ((goods + i)->unit_price < average_price)
		{
			goods_less_price[goods_less_price_count] = goods[i];
			goods_less_price_count++;
		}
	}
	return goods_less_price_count;
}

char* gets(char*);

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const time_t timer = time(NULL);
	printf("%s\n", ctime(&timer));

	struct Good* goods = (struct Good*)calloc(MAX_SIZE, sizeof(struct Good));
	int Is_Not_Enter = 1;
	int goods_count = 0;

	do
	{
		printf_s("Товар №%d, введите его вид (enter для прекращения ввода): ", goods_count + 1);
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
	
	struct GoodsAvCost* goods_av_cost = (struct GoodsAvCost*)calloc(MAX_SIZE, sizeof(struct GoodsAvCost));
	int goods_av_cost_count = GoodsAvCostFunc(goods, goods_count, goods_av_cost);

	struct Good* goods_less_price = (struct Good*)calloc(MAX_SIZE, sizeof(struct Good));
	int goods_less_price_count = GoodsThatPriceLess(goods, goods_count, goods_less_price);

	Output("Массив с товарами по указанной дате, цена на которые ниже средней:", goods_less_price, goods_less_price_count);

	free(goods);
	free(goods_less_price);
	free(goods_av_cost);

	system("pause");
}