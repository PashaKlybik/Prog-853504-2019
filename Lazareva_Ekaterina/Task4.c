//Имеются товары с ценами от S до F включительно. На каждую цену имеется ровно один товар. Вывести, у скольких товаров стоимость поменяется не больше, чем на K рублей. 
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int S, F, K, j, ind, sum = 0, ind1 = 0;
	printf("Vvedite cenovoi diapazon tovarov i priemlemoe izmenenie ceni:\n");
        scanf("%d%d%d", &S, &F, &K);
	j = S;
      	int d = 0, n = 0, i = 0, cnt = 0, shift = 1;
       	d = j;
        n = d;
        do
       {
           cnt++;
           n/=10;
       }
        while(n!=0);
        for( i=0; i<cnt-1; i++)
       	shift*=10;
        n = d;
        d = 0;
        do
       {
           d+=((n % 10) * shift);
           n/=10;
           shift/=10;
       }
        while(shift!=0);
        for (j; j <= F; j++)
	 {
       	     ind = abs (j - d);
      	     if (ind <= K)
		 {
		     ind1++;
		     sum+=ind1;
		 }
         }
        printf("%d\n", sum);
        return 0;        
}
