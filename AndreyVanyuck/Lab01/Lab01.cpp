#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

int low(int);
int up(int);

int main()
{
	int N;
	printf("Enter N: ");
	scanf("%d", &N);

	for (int i = 10; i < N; i++)
	{
		int b = up(i);

		if (b != 0)
			printf("%d\n", i);
		else
		{
			b = low(i);
			if (b != 0)
				printf("%d\n", i);
		}
	}

	getch();
    return 0;
}

int up(int n)
{
    int b = n % 10;
    n /= 10;

    while (n > 0)
    {
        if (n % 10 >= b)
            return 0;
        else
            b = n % 10;

        n /= 10;
    }

    return 1;
}

int low(int n)
{
    int b = n % 10;
    n /= 10;

    while (n > 0)
    {
        if (n % 10 <= b)
            return 0;
        else
            b = n % 10;

        n /= 10;
    }

    return 1;
}
