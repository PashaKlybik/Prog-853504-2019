#include <stdio.h>
#include <stdlib.h>

int bg1, x, y, x1, y11, n, i, j, a[1005][1005], ramx[1000000], ramy[1000000], m, xn, yb, xk, yk, bg, en, ox[100000], oy[1000000];

int main()
{
    scanf("%d", &n);
    for (i = 0; i <= (n + 1); i++)
        for (j = 0; j <= (n + 1); j++)
            a[i][j] = -1;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1)
            {
                ramx[m] = i;
                ramy[m] = j;
                m++;
                a[i][j] = -1;
            }
            if (a[i][j] == 0)
                a[i][j] = 9999;
        }
    scanf("%d %d %d %d", &xn, &yb, &xk, &yk);
/*----------------------------------------------------------------------------------------------------*/
    a[xn][yb] = 0;
    bg = 1;
    en = 2;
    ox[bg] = xn;
    oy[bg] = yb;
    while (bg < en)
    {
        x = ox[bg];
        y = oy[bg];
        bg++;
        x1 = x;
        y11 = y;
        while ((a[x1][y11 - 1] >= (a[x][y] + 1)) && (a[x1][y11 - 1] > 0))
        {
                y11--;
                oy[en] = y11;
                ox[en] = x1;
                en++;
                a[x1][y11] = a[x][y] + 1;
        }
        x1 = x;
        y11 = y;
        while ((a[x1][y11 + 1] >= (a[x][y] + 1)) && (a[x1][y11 + 1] > 0))
        {
                y11++;
                oy[en] = y11;
                ox[en] = x1;
                en++;
                a[x1][y11] = a[x][y] + 1;
        }
        x1 = x;
        y11 = y;
        while ((a[x1 + 1][y11] >= (a[x][y] + 1)) && (a[x1 + 1][y11] > 0))
        {
                x1++;
                oy[en] = y11;
                ox[en] = x1;
                en++;
                a[x1][y11] = a[x][y] + 1;
        }
        x1 = x;
        y11 = y;
        while((a[x1 - 1][y11] >= (a[x][y] + 1)) && (a[x1 - 1][y11] > 0))
        {
                x1--;
                oy[en] = y11;
                ox[en] = x1;
                en++;
                a[x1][y11] = a[x][y] + 1;
        }
    }
    printf("%d ", a[xk][yk]);
/*----------------------------------------------------------------------------------------------------*/
    bg1 = 0;
    while (m > 0)
    {
        bg = 1;
        en = 2;
        ox[bg] = xn;
        oy[bg] = yb;

        a[ramx[bg1]][ramy[bg1]] = 99999;
        ox[bg] = xn;
        oy[bg] = yb;

        while (bg < en)
        {
            x = ox[bg];
            y = oy[bg];
            bg++;
            x1 = x;
            y11 = y;
            while((a[x1][y11 - 1] >= (a[x][y] + 1)) && (a[x1][y11 - 1] > 0))
            {
                y11--;
                oy[en] = y11;
                ox[en] = x1;
                en++;
                a[x1][y11] = a[x][y] + 1;
            }
            x1 = x;
            y11 = y;
            while((a[x1][y11 + 1] >= (a[x][y] + 1)) && (a[x1][y11 + 1] > 0))
            {
                y11++;
                oy[en] = y11;
                ox[en] = x1;
                en++;
                a[x1][y11] = a[x][y] + 1;
            }
            x1 = x;
            y11 = y;
            while((a[x1 + 1][y11] >= (a[x][y] + 1)) && (a[x1 + 1][y11] > 0))
            {
                x1++;
                oy[en] = y11;
                ox[en] = x1;
                en++;
                a[x1][y11] = a[x][y] + 1;
            }
            x1 = x;
            y11 = y;
            while((a[x1 - 1][y11] >= (a[x][y] + 1)) && (a[x1 - 1][y11] > 0))
            {
                x1--;
                oy[en] = y11;
                ox[en] = x1;
                en++;
                a[x1][y11] = a[x][y] + 1;
            }
        }
    a[ramx[bg1]][ramy[bg1]] = -1;
    bg1++;
    m--;
    }
    printf("%d\n", a[xk][yk]);
    return 0;
}
