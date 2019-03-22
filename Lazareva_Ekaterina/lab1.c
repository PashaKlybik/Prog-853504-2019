#include "stdafx.h"
#include <math.h>
#include <stdlib.h>

bool check(int n)
{
	int sum = 0;
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
			sum += i;
	}
	return (sum == n);
}
int Euclidean_formula(int n)
{
	return pow(2, n - 1) * (pow(2, n) - 1);
}
int main()
{
	int N;
	printf_s("Vvedite N\n");
	scanf_s("%d", &N);
	for (int i = 2; Euclidean_formula(i) < N; i++)
	{
		if (check(Euclidean_formula(i)))
		{
			printf_s("%d\n", Euclidean_formula(i));
		}
	}
	system("pause");
	return 0;
}
