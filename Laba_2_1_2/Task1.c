#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>
#define MAX_SIZE 20

/*
- ���������� ������� ��������� ������ ������� ���� �� ������;
- ������� ���������� � �������, ����������� � ��������� ����, ���� �� ������� ������
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
		puts("������ - ��������� ����");
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
		puts("������ - ��������� ����");
	}
	return number;
}

void Output(char mess[], struct Good* goods, int goods_count)
{
	printf_s("%s\n", mess);
	puts("========================================================================================");
	puts("|| # || ��� ������ || ���������� ������ || ���� ����������� �� ����� || ���� �� ����� ||");
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
		printf_s("����� �%d, ������� ��� ��� (enter ��� ����������� �����):", goods_count + 1);
		if (strcmp(gets((goods + goods_count)->type), "") != 0)
		{
			(goods + goods_count)->amount = input_int("������� ���������� ������� �� ������:");
			(goods + goods_count)->date = input_int("������� ���� ����������� ������ �� �����:");
			(goods + goods_count)->unit_price = input_double("������� ���� �� ������ �� ����:");
			puts("");
			while (getchar() != '\n');
			goods_count++;
		}
		else
		{
			Is_Not_Enter = 0;
		}
	} while (Is_Not_Enter);

	Output("�������� ������:", goods, goods_count);

	goods = (struct Good*)realloc(goods, goods_count * sizeof(struct Good));

	system("pause");
}