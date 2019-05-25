//Определить, сколько есть почти счастливых делителей числа N
#include <stdio.h>

long long Input (long long min)
{
	long long x, c;
	int y = 0;
	min = 0;
	do
	{
		printf("Enter N:");
		scanf("%lld", &x);
        	if (x < min)
	{
		printf("Error! try Again!\n");
	}
	else
	{
		y = 1;
		int sum2 = 0;
        for (long long i = 1; i <= x; i++)
        {
                if (x % i == 0)
                {
                        c = i;
         while (c)
             {
                  long long num;
                  num = c % 10;
                  c /= 10;
                  if (num == 4 || num == 7)
                  {
                        int sum = 0;
                        sum++;
                        sum2 += sum;
                  }
             }
                }
        }
        printf("%d\n", sum2);
	}
	}
	while (y!=1);
		return x;
}

int main()
{
	long long N;
	Input (N);
	return 0;
}
