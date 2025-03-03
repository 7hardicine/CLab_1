#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>
#define MAX_SIZE 20

struct Good
{
	char type[MAX_SIZE];
	int amount;
	double unit_price;
	int date;
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

char* gets(char*);

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Good* goods = (struct Good*)calloc(MAX_SIZE, sizeof(struct Good));
	int count = 0;
	int Is_Not_Enter = 1;

	do
	{
		printf_s("����� �%d, ������� ��� ��� (enter ��� ����������� �����): ", count + 1);
		if (strcmp(gets((goods + count)->type), "") != 0)
		{
			(goods + count)->amount = input_int("������� ���������� ������� �� ������: ");
			(goods + count)->date = input_int("������� ���� ����������� ������ �� �����: ");
			(goods + count)->unit_price = input_double("������� ���� �� ������ �� ����: ");
			puts("");
			while (getchar() != '\n');
			count++;
		}
		else
		{
			Is_Not_Enter = 0;
		}
	} while (Is_Not_Enter);

	goods = (struct Good*)realloc(goods, count * sizeof(struct Good));

	puts("========================================================================================");
	puts("|| # || ��� ������ || ���������� ������ || ���� ����������� �� ����� || ���� �� ����� ||");
	puts("========================================================================================");

	for (int i = 0; i < count; i++)
	{
		printf_s("||%2d ||%6s      ||%9d          ||%14d             ||%8.2lf       ||\n", \
			i + 1, (goods + i)->type, (goods + i)->amount, (goods + i)->date, (goods + i)->unit_price);
		puts("========================================================================================");
	}

	char* buff = (char*)malloc(MAX_SIZE * sizeof(char));
	int buff_size = 1;
	for (int i = 0; i < count; i++)
	{
		int k = 0;
		for (int j = 0; j < buff_size; j++)
		{
			printf_s("%d %d\n", i, j);
			strcmp((goods + i)->type, *(buff + j)) == 0 ? k++ : k;
			printf_s("%d\n", k);
		}
		k == 1 ? *(buff + buff_size) = (goods + i)->type, buff_size++ : k;
	}

	printf_s("%d\n", buff_size);

	system("pause");
}