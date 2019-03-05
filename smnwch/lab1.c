#include <stdio.h>
#include <conio.h>
//variant28
int main()
{   int k, i, r, j=1, c=1;
	printf("input k: ");
	scanf_s("%d",&k);
	if (k==0) {
	   printf("0");
	} else	if (k==1||k==2)
	  {
		printf("1");
	  } else if (k>2)
		   { for ( i = 3; i <= k; i++) {
				  r=j+c;
				  j=c;
				  c=r;
				  }
			printf("%d",r);
			}
			else { printf("error");}

	 getch();
	 return 0;
}
