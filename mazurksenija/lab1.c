#include <stdio.h>
#include <conio.h>

int main()
{
	int t=0,i,j,h,s,p,f=0,m=0,g=0,d=1,r,q;
	float k,l,o,y,n;
	  printf("Input k:");
	  scanf("%f", &k);
	  printf("Input l:");
	  scanf("%f", &l);
	   s=k; p=l;
		 n=k/l;
	  if (s%p==0)
	  {  while(k>=1)
	   {
		 k=k/10.0;
		 t++;
	   }

		printf("  %d|%d\n",s,p);
		 o=n*10;
		 while(n>=1)
		{
		  n=n/10;
		  f++;
		}
		n=n*10;
			 for (i=0;n!=o;i++)
		{
			  h=n;
			  j=(h-g*m)*l;
			  n=n*10;
			  m=10;
			  g=n/m;
			  y=j;
		 if (i==0)
		{  while(y>=1)
			{
		 y=y/10.0;
		 q++;
		 } printf(" -%d",j);
		 for(j=0;j<t-q;j++)
		 {	printf(" ");}
		 printf("|----\n"); }
		  if (i==1)
		   { for(r=0;r<d;r++)
				{ printf(" ");   }
			  printf("  %d  %d\n",j,s/p);
			  for(r=0;r<d;r++)
			   {  printf(" "); }
			   printf(" -%d\n",j);
				d++;   }
		  if(i>1)
		  {for(r=0;r<d;r++)
			   { printf(" ");   }
			printf("  %d\n",j);
		   for(r=0;r<d;r++)
			{	printf(" "); }
			printf(" -%d\n",j);
			 d++;     }     }
			////////////////////////////////////
		  if (i==1)
		{ printf("  ");
		 for(i=0;i<t;i++)
		   {
		   printf("-");
		   }
			  //printf("-");
			printf(" %d\n",s/p);
		  for(i=0;i<t;i++)
		   {
		   printf(" ");
		   }
		   printf(" 0");
		}

		 printf("  ");
		  //////////////////////////////
			  if (i>=2)
		{  for(i=0;i<t-1;i++)
		{
		   printf("-");
		}
			 printf("-\n");  // printf(" %d\n",s/p);
		  for(i=0;i<t;i++)
		{
		   printf(" ");
		}
		   printf(" 0");     }
								   }
	  else     printf("Error");
	  getch();
	  return 0;
}
