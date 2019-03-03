#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
//19 variant

void main()
{
	int s = 0, five = 0, three = 0;
	bool number = false;
		while (true)
		{
			printf("number greater than 7 and less than 10^9: ");
			scanf_s("%d", &s);
			if (s <= 7)
			{
				printf("read carefully, take one more chance \n");
				number = true;
			}
			else if (s >= 1000000000)
			{
				printf("read carefully, take one more chance \n");
				number = true;
			}
				else break;
		}
		for (int i = s; i > 0; i -= 3)
		{
			if (i % 5 == 0)
			{
				five = i / 5;
				break;
			}
			++three;
		}
		printf("number of threes: ");
		printf("%d", three);
		printf("\nnumber of fives: ");
		printf("%d", five);
	_getch();
}
