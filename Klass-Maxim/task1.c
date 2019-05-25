//task 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num, i, i1, answer=0;
    printf("Enter ur number: ");
    scanf("%d", &num);
    for (i = 1; i<=num/2; i++)
    {
        if (!(num % i))
        {
            i1 = i;
            while(i1)
            {
                if (i1%10 == 4 || i1%10 == 7)
                {
                    answer++;
                    break;
                }
                i1 /= 10;
            }

        }
    }

    while(num)
    {
        if (num % 10 == 4 || num%10 == 7)
        {
            answer++;
        }
        num /= 10;
    }
    printf("%d \n", answer);
    return 0;
}

