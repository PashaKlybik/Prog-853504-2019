#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
int main()
{
    for(int i=1; i<=1000; i++)
    {
         int n=1;
         int s=1;

        while(i>(pow(10,n)))
        {
            n++;
        }

        for(int j=0; j<n; j++)
        {
            s=s*10;
        }

        if((((i*i)-i)%s)==0)
        {
            printf("%d",i);
            printf(" ");
        }
    }

    getch();
    return 0;
}
