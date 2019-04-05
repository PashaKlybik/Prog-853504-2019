/*
	2.1(11)
	Комплексное число. Разработать программу, меню которой
	позволяет выполнить следующие функции:
	1. Ввод комплексного числа.
	2. Вывод комплексного числа в алгебраической форме.
	3. Вывод комплексного числа в показательной форме.
	4. Получение сопряженного комплексного числа.
	5. Возведение комплексного числа в целую положительную
	степень.
	6. Информация о версии и авторе программы.
	7. Выход из программы.
*/	
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

void complexIn(double* real, double* imagine)
{
	printf("Число : ");
	while (scanf_s("%lf %lf", &(*real), &(*imagine)) < 2)
	{
	error:
		while (getchar() != '\n');
		printf("Неверный ввод. Попробуйте ещё раз : ");
	}
	if (getchar() != '\n')
	{
		goto error;
	}
}

void showAlgebraic(double* real, double* imagine)
{
	printf("Число в алгебраической форме : %.6lf%+.6lfi\n", *real, *imagine);
}

void showIndicative(double* real, double* imagine)
{
	printf("Число в показательной форме : exp(i * %lf)\n", atan(*real / (*imagine)));
}

void getMated(double* imagine)
{
	*imagine = -(*imagine);
	printf("Сделано.\n");
}

void complexPow(double* real, double* imagine)
{
	int value;
	printf("Введите целую положительную степень : ");
	while (!scanf_s("%d", &value) || value < 1)
	{
	error:
		while (getchar() != '\n');
		printf("Неверный ввод. Введите ещё раз : ");
	}
	if (getchar() != '\n')
	{
		goto error;
	}
	double fi = atan(*real / (*imagine)), r = pow(sqrt(pow(*real, 2) + pow(*imagine, 2)), value);
	*real = r * cos(value * fi);
	*imagine = r * sin(value * fi);
	printf("Сделано.\n");
}
void Info()
{
	printf("Version : 1.0\nDeveloped by Georgei Goncharik. 2019. All rights reserved.\n");
}
int main()
{
	setlocale(LC_ALL, "Russian");
	printf("Команды:\n 1-Ввод комплексного числа(вида a+(-)b)\n 2-Вывод комплексного числа в алгебраической форме\n 3-Вывод комплексного числа в показательной форме\n");
	printf(" 4-Получение сопряжённого комплексного числа\n 5-Возведение комплексного числа в целую положительную степень\n 6-Информация о версии и авторе программы\n 7-Выход из программы\n");
	char act;
	double Real = 1, Imagine = 1;
	double* ptrR = &Real, * ptrI = &Imagine;
	while (1)
	{
		printf("Действие : ");
		scanf_s("%c", &act);
		while ((unsigned int)act < 49 || (unsigned int)act > 55)
		{
		error:
			while (getchar() != '\n');
			printf("Неверный ввод. Введите ещё раз: ");
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
