#include <stdio.h>

void func(int * some, int dec, char L);

int main()
{
	int num;
	do {
		printf("\n\nenter number:\n");
		if (scanf_s("%d", &num) == 1){
		func(&num, 10000, 'X'); // X большое означает 10тыс
		func(&num, 5000, 'V');
		func(&num, 1000, 'M');
		func(&num, 500, 'D');
		func(&num, 100, 'C');
		func(&num, 50, 'L');
		func(&num, 10, 'x'); // х малое означает 10
                if (num > 3 && num <= 9) {
			switch (num)
			{
			case 9: printf("Ix"); break;
			case 8: printf("VIII"); break;
			case 7: printf("VII"); break;
			case 6: printf("VI"); break;
			case 5: printf("V"); break;
			case 4: printf("IV"); break;
				
			} num = 0;
		}
		func(&num, 1, 'I');
		printf("\n");}
		else break;
	} while (1);
	return 0;
}

void func(int * some, int dec, char L)
{
	int num = *some;
	int ost = num / dec;
	if (ost > 0)
	{
		int i=0;
		for (i = 0; i < ost; i++) printf("%c",L);
	}
	num -= ost * dec;
	*some = num;
}
