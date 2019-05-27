#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int x1, y1, x2, y2;
    int x, y, r;
    int sum = 0;
    int IsAnswer = 1;
    printf("Введите коориданы сада\n");
    do
    {
        printf("x1 = ");
        scanf("%d", &x1);
        printf("y1 = ");
        scanf("%d", &y1);
        printf("x2 = ");
        scanf("%d", &x2);
        printf("y2 = ");
        scanf("%d", &y2);
        if (x1 < -pow(10, 6) && x2 < -pow(10, 6) &&
            x1 > pow(10, 6)  && y2 < -pow(10, 6) &&
            y1 > pow(10, 6)  && x2 > pow(10, 6)  &&
            x2 < x1 && y1 < -pow(10, 6) && y2 > pow(10, 6) && y2 < y1)
        {
            printf("Ошибка\n");
            IsAnswer = 0;
        }
    }
    while(!IsAnswer);
    printf("Координаты и радиус действия поливалки\n");
    do
    {
        printf("x = ");
        scanf("%d", &x);
        printf("y = ");
        scanf("%d", &y);
        printf("r = ");
        scanf("%d", &r);
        if (x < -pow(10, 6)&& x >pow(10,6) &&
            y < -pow(10,6) && y > pow(10, 6) &&
            r < 0 && r > pow(10, 6))
        {
            printf("Ошибка\n");
            IsAnswer = 0;
        }
    }
    while(!IsAnswer);
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            double answer = sqrt((i - x) * (i - x) + (j - y) * (j - y));
            if (answer > r)
                sum++;
        }
    }
    printf("%d", sum);
    return 0;
}
