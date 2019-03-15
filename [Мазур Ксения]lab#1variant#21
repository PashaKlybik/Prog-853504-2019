#include <stdio.h>
#include <conio.h>

int main()
{
	  int k,l,n,t=0,i;
	  printf("Input k:");
	  scanf("%d", &k);
	  printf("Input l:");
	  scanf("%d", &l);
	  n=k;
	   while(k>0)
	   {
		 k=k/10;
		 t++;
	   }
	  if(k%l==0)
	  {
		 printf("  %d|%d",n,l);
		 printf("\n -%d|---",n);
		 printf("\n  ",n);

		  for(i=0;i<t;i++)
		{
		  printf("-");
		}

		  printf(" %d",n/l);
		  printf("\n");

		  for(i=0;i<t;i++)
		{
		   printf(" ");
		}
		   printf(" 0");
	  }
	  else     printf("Error");
	  getch();
	  return 0;
}
