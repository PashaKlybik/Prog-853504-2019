#include <stdio.h>
#pragma hdrstop
#include <tchar.h>
#include <conio.h>
#pragma argsused
int _tmain(int argc, _TCHAR* argv[])
{
	unsigned long long numb, i = 1, MainMask, count;
	printf("Your number:");
	scanf("%llu",&numb);  // max number to enter: 4 294 967 295
	MainMask = 0x3;

 while (MainMask < numb) {
		count = 1;
   do {
		if (count % 2) {
		 printf("11");
	   }
		else {
		 printf("00");
	   }

		count++;

	  }   while (count <= i) ;

		printf (" - %llu\n", MainMask);

		MainMask = MainMask << 2;
		i++;
		if (i % 2 == 0) {
		  MainMask += 0x0;
		}
		else {
		MainMask += 0x3;
		}
	}
	getch();
	return 0;
}

