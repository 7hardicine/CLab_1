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
		printf_s("������ #%d", i + 1);
		plains[i].number = input_int("������� �������� �����:");
		scanf_s("%s", &plains[i].mark);
		plains[i].capacity = input_int("������� �����������:");
		plains[i].weight = input_double("������� ����������������:");
		plains[i].year = input_int("������� ��� �������:");
	}

	for (int i = 0; i < size; i++)
	{
		printf_s("������ #%d", i + 1);
		printf_s("\n�������� �����: %d\n�����������: %d\n����������������: %lf\n��� �������: %d\n�����: %s", plains[i].number, plains[i].capacity, plains[i].weight, plains[i].year, plains[i].mark);
	}

	system("pause");
}