#include <stdio.h>

void func(int * some, int dec, char L);

int main()
{
	int num;
	do {
		printf("\n\nenter number:\n");
		if (scanf_s("%d", &num) == 1){
		 func(&num, 10000, 'X'); // X большое означает 10тыс
            	 func(&num, 9000, '1'); // MX
          	 func(&num, 5000, 'V');
           	 func(&num, 4000, '2'); // MV
           	 func(&num, 1000, 'M');
           	 func(&num, 500, 'D');
            	 func(&num, 400, '3'); // CD
            	 func(&num, 100, 'C');
            	 func(&num, 50, 'L');
            	 func(&num , 40, '4'); // xL

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
    if (*some>=9000 && dec==9000) {printf("%s", "MX"); *some-=9000;}
     else if (*some>=4000 && dec==4000) {printf("%s", "MV"); *some-=4000;}
       else if (*some>=400 && dec==400) {printf("%s", "CD"); *some-=400;}
         else if (*some>=40 && dec==40) {printf("%s", "xL"); *some-=40;} else
         {
            int num = *some;
            int ost = num / dec;
            if (ost > 0)
            {
                int i;
                for (i = 0; i < ost; i++) printf("%c", L);
            }
            num -= ost * dec;
             *some = num;}
}
