/*
	2.1(11)
	����������� �����. ����������� ���������, ���� �������
	��������� ��������� ��������� �������:
	1. ���� ������������ �����.
	2. ����� ������������ ����� � �������������� �����.
	3. ����� ������������ ����� � ������������� �����.
	4. ��������� ������������ ������������ �����.
	5. ���������� ������������ ����� � ����� �������������
	�������.
	6. ���������� � ������ � ������ ���������.
	7. ����� �� ���������.
*/	
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

void complexIn(double* real, double* imagine)
{
	printf("����� : ");
	while (scanf_s("%lf %lf", &(*real), &(*imagine)) < 2)
	{
	error:
		while (getchar() != '\n');
		printf("�������� ����. ���������� ��� ��� : ");
	}
	if (getchar() != '\n')
	{
		goto error;
	}
}

void showAlgebraic(double* real, double* imagine)
{
	printf("����� � �������������� ����� : %.6lf%+.6lfi\n", *real, *imagine);
}

void showIndicative(double* real, double* imagine)
{
	printf("����� � ������������� ����� : exp(i * %lf)\n", atan(*real / (*imagine)));
}

void getMated(double* imagine)
{
	*imagine = -(*imagine);
	printf("�������.\n");
}

void complexPow(double* real, double* imagine)
{
	int value;
	printf("������� ����� ������������� ������� : ");
	while (!scanf_s("%d", &value) || value < 1)
	{
	error:
		while (getchar() != '\n');
		printf("�������� ����. ������� ��� ��� : ");
	}
	if (getchar() != '\n')
	{
		goto error;
	}
	double fi = atan(*real / (*imagine)), r = pow(sqrt(pow(*real, 2) + pow(*imagine, 2)), value);
	*real = r * cos(value * fi);
	*imagine = r * sin(value * fi);
	printf("�������.\n");
}
void Info()
{
	printf("Version : 1.0\nDeveloped by Georgei Goncharik. 2019. All rights reserved.\n");
}
int main()
{
	setlocale(LC_ALL, "Russian");
	printf("�������:\n 1-���� ������������ �����(���� a+(-)b)\n 2-����� ������������ ����� � �������������� �����\n 3-����� ������������ ����� � ������������� �����\n");
	printf(" 4-��������� ����������� ������������ �����\n 5-���������� ������������ ����� � ����� ������������� �������\n 6-���������� � ������ � ������ ���������\n 7-����� �� ���������\n");
	char act;
	double Real = 1, Imagine = 1;
	double* ptrR = &Real, * ptrI = &Imagine;
	while (1)
	{
		printf("�������� : ");
		scanf_s("%c", &act);
		while ((unsigned int)act < 49 || (unsigned int)act > 55)
		{
		error:
			while (getchar() != '\n');
			printf("�������� ����. ������� ��� ���: ");
			scanf_s("%c", &act);
		}
		if (getchar() != '\n')
		{
			goto error;
		}
		switch (act)
		{
		case '1':
			complexIn(ptrR, ptrI);
			break;
		case '2':
			showAlgebraic(ptrR, ptrI);
			break;
		case '3':
			showIndicative(ptrR, ptrI);
			break;
		case '4':
			getMated(ptrI);
			break;
		case '5':
			complexPow(ptrR, ptrI);
			break;
		case '6':
			Info();
			break;
		case '7':
			return 0;

		}
	}
}