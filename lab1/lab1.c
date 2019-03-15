#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int coef(int i, int j);

int main()
{
	int sum = 0, proizv = 1;
	int i, j, s,n;
	printf("Input n:");
	scanf_s("%d", &n);

	for (i = 1; i <= n; i++)
	{
		proizv = 1;
		for (j = 1; j <= i; j++)
		{
			proizv *= coef(j,i);
		}
		sum += proizv;
	}

	printf("sum=%u", sum);
	scanf("%d", &n);	
	return 0;
}


int coef(int j, int i)
{
	int n = i+1;

	for (int count = n+1; count <= i+j; count++)
	{
		n *= count;
	}

	return n;

}
