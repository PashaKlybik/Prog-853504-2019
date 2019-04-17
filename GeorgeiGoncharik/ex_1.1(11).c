/*
	1.1(11)
	Длина высоты. Треугольник ABC задан длинами своих сторон.
	Найти длину высоты, опущенной из вершины А.
	Экстремальные тесты: сумма двух сторон равна третьей; одна из
	сторон равна нулю. 
*/
#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c;

	printf("Input a, b, c:\n");
	scanf_s("%f", &a);
	scanf_s("%f", &b);
	scanf_s("%f", &c);
	if ((a != 0 && b != 0 && c != 0) && (a + b > c && a + c > b && b + c > a))
	{
		float semiPer = (a + b + c) / 2;
		float height = 2 / a * sqrt(semiPer * (semiPer - a) * (semiPer - b) * (semiPer - c));
		printf("Height: %f\n", height);
	}
	else
		printf("Error.\n");
	return 0;
}