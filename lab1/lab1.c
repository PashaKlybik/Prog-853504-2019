#include "stdafx.h"
#include <stdio.h>
#include<math.h>
#include <conio.h>


int main()
{
	int N, i = 1, sum = 0, counter = 1;
	printf_s("vvedite N\n");
	scanf_s("%d", &N);
	for (i = 1; i<N; i++)
	{
		sum = 0;
		for (counter = 1; counter<i; counter++)
		{
			if (i%counter == 0)
				sum = sum + counter;
		}
		if (i == sum) printf_s("sovershennoe %d\n", i);
	}
	_getch();
	return 0;
}
