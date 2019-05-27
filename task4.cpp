#include <stdio.h>
#include <stdlib.h>

int main()
{
    int min, max, difference;
    printf ("введите диапазон и разницу\n");
    scanf ("%d", &min);
    scanf ("%d", &max);
    scanf ("%d", &difference);
    int count = 0;
    for (int i = min; i <= max; i++)
    {
        int sale = 0, price = i;
        while (price > 0)
        {
            sale = sale * 10 + price % 10;
            price = (price - price % 10) / 10;
        }
        if (abs (i - sale) <= difference)
            count ++;
    }
    printf ("кол-во товаров: %d\n", count);
    return 0;
}

