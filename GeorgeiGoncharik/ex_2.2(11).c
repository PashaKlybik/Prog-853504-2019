/*
	2.2(11)
	��������� ��������� �������� ������� sin(x) � �������� � � ����������.
*/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

double fact(int n)
{
	if (n == 1)
		return 1;
	return n * fact(n - 1);
}
void compare(double x, double precission)
{
	double razloj = 0;
	double sinx = sin(x);
	int n = 0;
	short int sign = -1;
	do
	{
		n++;
		sign = -sign;
		razloj += ((double)sign) * powf(x, 2 * n - 1) / fact(2 * n - 1);
		if (n > 30)
		{
			printf("����� �������� �������� �� ����� ��������� � �������� ���������.\nsin(x) = %.8lf\n���������� = %.8lf\n", sinx, razloj);
		}
	} while (razloj - sinx > precission || razloj - sinx < -precission);
	printf("����� %d ������� � ��������� %.8lf :\nsin(x) = %.8lf\n���������� = %.8lf\n", n, precission, sinx, razloj);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	printf("��������� ��������� �������� ������� sin(x) � �������� � � ����������.\n");
	double x;
	double precission;
	char in_again = 'y';
	while (in_again == 'y')
	{
		printf("������� ����� x : ");
		while (!scanf("%lf", &x))
		{
		error1:
			while (getchar() != '\n');
			printf("�������� ����. ������� ��� ���: ");
		}
		if (getchar() != '\n')
		{
			goto error1;
		}
		printf("������� �������� �������� (�� ����� 1e-6): ");
		while (!scanf("%lf", &precission) || precission < 0 || fabs(precission) < 1e-6)
		{
		error2:
			while (getchar() != '\n');
			printf("�������� ����. ������� ��� ���: ");
		}
		if (getchar() != '\n')
		{
			goto error2;
		}
		while (x > 4)
			x -= 3.14159265;
		while (x < -4)
			x += 3.14159265;
		compare(x, precission);
		printf("������ ��� ���� x? (y \ another key) \t");
		scanf("%c", &in_again);
	}
	return 0;
}
