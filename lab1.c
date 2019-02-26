#include <conio.h>
#include <stdio.h>

void help(int * some, int dec, char L);

int main()
{
	int num;
	do {
		printf("\n\nenter number:\n");
		scanf_s("%d", &num);
		help(&num, 10000, 'X'); // X большое означает 10тыс
		help(&num, 5000, 'ṽ');
		help(&num, 1000, 'M');
		help(&num, 500, 'D');
		help(&num, 100, 'C');
		help(&num, 50, 'L');
		help(&num, 10, 'x'); // х малое означает 10
		help(&num, 5, 'V');
		help(&num, 1, 'I');
	} while (1);
	_getch();
	return 0;
}

void help(int * some, int dec, char L)
{
	int num = *some;
	//printf("\nnum=%d  ost=%d", num, dec);
	int ost = num / dec;
	//printf("\nnum=%d  ost=%d", num, ost);
	if (ost > 0)
	{
		for (int i = 0; i < ost; i++) printf("%c",L);
	}
	num -= ost * dec;
	*some = num;
	
}
