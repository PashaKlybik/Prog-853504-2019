#include "stdafx.h"
#include <stdio.h>
#include<math.h>
#include <conio.h>
#include <stdlib.h>

int main(void)
{
	int N, i, sum = 0, counter = 1;
	printf_s("vvedite N\n");
	scanf_s("%d", &N);
	i = 1;
	counter = 1;
	while (i < N)
	{
		sum = 0;
		counter = 1;
		while (counter < i)
		{
			if (i%counter == 0)
				sum = sum + counter;
			counter++;
		}
		if (i == sum) printf_s("sovershennoe %d\n", i);
		i++;
	}
	system("pause");
    return 0;
}
