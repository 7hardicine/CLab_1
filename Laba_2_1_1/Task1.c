#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#define MAX_SIZE 20

// - ������� ���������� � ��������� � ������������ 
// ����������������� � ������� ����������� ���� �������; 
// - ���������� ���������� ���������, ���������������� 
// ������� ������ ��������

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

void Input(struct Plane planes[], int plane_count)
{
	for (int i = 0; i < plane_count; i++)
	{
		puts("================================================");
		printf_s("������ #%d\n", i + 1);
		planes[i].number = input_int("������� �������� �����:");
		printf_s("������� �����: ");
		scanf("%s", &planes[i].mark);
		planes[i].capacity = input_int("������� �����������:");
		planes[i].weight = input_double("������� ����������������:");
		planes[i].year = input_int("������� ��� �������:");
	}
}

void Output(struct Plane planes[], int plane_count)
{
	puts("================================================================================================");
	puts("|| # || �������� ����� || ����������� || ���������������� || ��� ������� ||       �����       ||");
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

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Plane planes[MAX_SIZE];

	int plane_count = input_int("������� ���������� ��������:");
	Input(planes, plane_count);
	Output(planes, plane_count);

	double max_weight_value = Max_Weight_Find(planes, plane_count);
	struct Plane planes_max_weight[MAX_SIZE];
	for (int i = 0, j = 0; i < plane_count; i++)
	{
		if (planes[i].weight == max_weight_value)
		{
			max_weight[j] = i;
			j++;
			max_weight_size++;
		}
	}

	printf_s("������ � ������������ �����������������: ");

	for (int i = 0; i < max_weight_size; i++)
	{
		printf_s("#%d; ", max_weight[i] + 1);
	}
	puts("");

	int flag = 0;
	double weight_input = input_double("������� ����������������, �� ������� ������ �������� ���������: ");
	for (int i = 0; i < plane_count; i++)
	{
		planes[i].weight < weight_input ? flag++ : flag;
	}

	printf_s("���������� ��������, � ������� ���������������� ������ %.2lf ����� %d\n", weight_input, flag);

	system("pause");
}