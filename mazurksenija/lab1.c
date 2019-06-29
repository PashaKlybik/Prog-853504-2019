#include <stdio.h>
#include <conio.h>
#include <malloc.h>

int main()
{
	int t=0,i=0,j,h,s,p,f=0,m=0,g=0,d=0,r,q,e=0,digit,counter=0 ,plus=0,number,*a,per,number2;
	float k,l, y,n;
	  printf("Input k:");
	  scanf("%f", &k);
	  printf("Input l:");
	  scanf("%f", &l);
	   s=k; p=l;
		 n=k/l;


	 number2= number=k;
		while(number2>0)
		{
			number2/=10;   plus++;
		}

		a=(int*)malloc(plus*sizeof(int));
		counter=plus-1;
		while(number>0)
		{
		 digit =number%10;
		 a[counter]=digit;
		 number/=10;  counter--;
		}

	  //////////////////////////////////////////////////
	  /*деление **/
	  if (s%p==0)   /*предсчет*/
	  {  while(k>=1)
	   {
		 k=k/10;
		 t++;
	   }

		printf("  %d|%d\n",s,p);

		while(n>=1)
		{
		  n=n/10;
		  f++;
		}
		  n=n*10;      counter=0;
		 /*сам цикл/////////////////////////////////*/
		 for (i=0;i<=f-1;i++)
		{
			  h=n;
			  j=(h-g*m)*l;
			  n=n*10;
			  m=10;
			  g=n/m;
			  y=j;
			  /*ПЕРВЫЙ ЦИКЛ*/
		 if (i==0)
		{ if(a[0]>=l)   {per=a[0]-j; } else {per=(a[0]*10+a[1])-j;}
		  while(y>=1)
			{
			 y=y/10.0;
			  q++;
			}
		  printf(" -%d",j);
		 for(j=0;j<t-q;j++)
		 {	printf(" ");}
		 printf("|----\n"); d++;  }

			  /*ВТОРОЙ*/
		 if (i==1)
		{  if(a[0]>=l){   for(r=0;r<d;r++)
				{ printf(" ");   }
			   printf(" %d%d ",per,a[1]); printf(" %d\n",s/p);
			  for(r=0;r<d;r++)
			   {  printf(" "); }
		  if(j>9){	   printf("-%d\n",j); } else printf(" -%d\n",j);

			   d++;	 per=(per*10)+a[1]-j; }
			   else {
			 for(r=0;r<d;r++)
			 { printf(" ");   }
			   printf("  %d%d",per,a[2]); printf("  %d\n",s/p);
			for(r=0;r<d;r++)
			 {  printf(" "); }
			  if(j<10){	   printf("  -%d\n",j); } else printf(" -%d\n",j);
			   d++;	    per=(per*10)+a[2]-j;   }      }


		  if (i>1)
		   {     if(a[0]>=l) {
				for(r=0;r<d;r++)
				{ printf(" ");   }
			   printf(" %d%d\n ",per,a[i]);
			  for(r=0;r<d-1;r++)
			   {  printf(" "); }
			   if(j>9){	   printf("-%d\n",j); } else printf(" -%d\n",j);
				  d++;    per=(per*10)+a[counter]-j; }
			   else
			 {

			for(r=0;r<d;r++)
				{ printf(" ");   }
				   printf("  %d%d\n",per,a[counter+1]);
			  for(r=0;r<d;r++)
			   {  printf(" "); }
			  if(j>9){	   printf(" -%d\n",j); } else printf("  -%d\n",j);

			 d++;      per=(per*10)+a[counter+1]-j;

				   }     }  e++;counter++;  }

				   ///////////////////////////////////////////

		  if (e==1)
		{ printf("  ");
		 for(i=0;i<t;i++)
		   {
		   printf("-");
		   }
			      printf(" !%d\n",s/p);

		  for(i=0;i<t+1;i++)
		   {
		   printf(" ");
		   }
		   printf("0");
		}


		  //////////////////////////////
		if(e>=2)
		{  printf(" "); for(i=0;i<t;i++)
		{
		   printf("-");
		}
			 printf("-\n");
		  for(i=0;i<t+1;i++)
		{
		   printf(" ");
		}
		   printf("0");     }
					  }
	  else     printf("Error");
	  getch();
	  return 0;
}
