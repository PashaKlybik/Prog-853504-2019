//Произвести некоторе количество преобразований и вывести сумму чисел получившегося массива
#include <stdio.h>

int main()
{
	int i, j = 0, n, min, a[1000], number, number1, sum = 0, b[1000], amount;
	printf("vvedite kolichestvo elementov massiva \n");
	scanf("%d", &n);
	printf("vvedite massiv \n");
	for (i = 0; i <n; i++)
		scanf("%d", &a[i]);
	printf("vvedite kolichestvo preobrazovanii \n");
	scanf("%d", &number1);
	min = a[1];
	if (number1 == 0)
	{
		for (i = 0; i < n; i++)
		{
			sum += a[i];
		}
		printf("%d\n", sum);
	}
	else
	{
		for (amount = 1; amount <= number1; amount++)
		{
			for (i = 0; i < n; i++)
			{
				if (min > a[i])
					min = a[i];
				int *ind;
				ind = &a[i];
				number = min - *ind;
				sum += number;
				b[j] = number;
				j++;
			}
		}
		printf("%d\n", sum);
	}
    return 0;
}
