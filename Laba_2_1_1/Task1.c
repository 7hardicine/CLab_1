#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#define MAX_SIZE 20

// - ������� ���������� � ��������� � ������������ 
// ����������������� � ������� ����������� ���� �������; 
// - ���������� ���������� ���������, ���������������� 
// ������� ������ ��������

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

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Plain plains[MAX_SIZE];

	int size = input_int("������� ���������� ��������:");

	for (int i = 0; i < size; i++)
	{
		puts("================================================");
		printf_s("������ #%d\n", i + 1);
		plains[i].number = input_int("������� �������� �����:");
		printf_s("������� �����: ");
		scanf("%s", &plains[i].mark);
		plains[i].capacity = input_int("������� �����������:");
		plains[i].weight = input_double("������� ����������������:");
		plains[i].year = input_int("������� ��� �������:");
	}

	puts("================================================================================================");
	puts("|| # || �������� ����� || ����������� || ���������������� || ��� ������� ||       �����       ||");
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

	printf_s("������ � ������������ �����������������: ");

	for (int i = 0; i < max_weight_size; i++)
	{
		printf_s("#%d, ", max_weight[i] + 1);
	}
	puts("");

	int flag = 0;
	double weight_input = input_double("������� ����������������, �� ������� ������ �������� ���������: ");
	for (int i = 0; i < size; i++)
	{
		plains[i].weight < weight_input ? flag++ : flag;
	}

	printf_s("���������� ��������, � ������� ���������������� ������ %.2lf ����� %d\n", weight_input, flag);

	system("pause");
}