#include <stdio.h>

void func(int * some, int dec, char L);

int main()
{
	int num;
	do {
		printf("\n\nenter number:\n");
		scanf_s("%d", &num);
		func(&num, 10000, 'X'); // X большое означает 10тыс
		func(&num, 5000, 'ṽ');
		func(&num, 1000, 'M');
		func(&num, 500, 'D');
		func(&num, 100, 'C');
		func(&num, 50, 'L');
		func(&num, 10, 'x'); // х малое означает 10
		func(&num, 5, 'V');
		func(&num, 1, 'I');
	} while (1);
	return 0;
}

void func(int * some, int dec, char L)
{
	int num = *some;
	int ost = num / dec;
	if (ost > 0)
	{
		for (int i = 0; i < ost; i++) printf("%c",L);
	}
	num -= ost * dec;
	*some = num;
}
