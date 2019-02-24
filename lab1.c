#include <stdio.h>
///////////////////
///////////////////   вариант 24
///////////////////
int fact(int x);

int main()
{
	 int n, sum = 0, proizv=1;
	  int i, j,s;
	printf("Input n:");
	scanf_s("%d", &n);

	for (i = 1; i <= n; i++)
	{
		proizv = 1;		
		for (j = 1; j <= i; j++)
		{
			proizv *= (fact(j + i) / fact(i));
		}
		sum += proizv;
	}

	printf("sum=%d", sum);

	scanf_s("%d", &n);
	return 0;
}

int fact(int x)
{
	if (x <= 1) return x;
	else  return x * fact(x - 1);
}
