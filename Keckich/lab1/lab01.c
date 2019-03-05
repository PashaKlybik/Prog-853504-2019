#include <stdio.h>
#pragma hdrstop
#include <tchar.h>
#include <conio.h>
#pragma argsused
int _tmain(int argc, _TCHAR* argv[])
{
	unsigned long long numb, i = 1, CompareMask, MainMask, count;
	printf("Your number:");
	scanf("%llu",&numb);  // max number to enter: 4 294 967 295
	MainMask = CompareMask =  0x3;

 while (MainMask < numb) {
		count = i;
//using do while to write numbers in the binary system:
   do {
		if ((CompareMask & MainMask) && (i % 2 == 0)) {
//if the mask comparison does not give 0 and the sequence number is even:
		 printf("00");
		 CompareMask = CompareMask << 2;
	   }
//if the munber is odd:
		else if (CompareMask & MainMask) {
		 printf("11");
		 CompareMask = CompareMask << 2;
	   }
//if the mask comparison gives 0 and the sequence number is even:
		else if ((!(CompareMask & MainMask)) && (i % 2 == 0)) {
		 printf("11");
		 CompareMask = CompareMask << 2;
	   }
		else {
		 printf("00");
		 CompareMask = CompareMask << 2;
	   }
		count--;

	  }   while (count != 0) ;
//return the comparison mask to the initial state 0x3:
		CompareMask = CompareMask >> i*2;
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

