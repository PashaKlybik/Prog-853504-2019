#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x1, y3, x2, y2, px, py, r, x, r, y, ans = 0;
double k;

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    scanf("%d %d %d %d", &x1, &y3, &x2, &y2);
    scanf("%d %d %d", &px, &py, &r);
    for (x = max(px - r, x1); x <= min(x2, px + r); x++)
    {
        k = (r * r) - ((x - px) * (x - px));
        y = trunc(sqrt(k) + py);
        ans += min(y, y2) - max(py, y3) + 1 + max(0, (min(py, y2) - max(py - (y - py), y3)));
        //printf("%f %d %d %d %d\n", k, x, y, ans, (min(py, y2) - max(py - (y - py), y3)));
    }
    printf("%d\n", (x2 - x1 + 1) * (y2 - y3 + 1) - ans);
    return 0;
}
