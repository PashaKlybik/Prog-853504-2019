#include <stdio.h>
#include <stdlib.h>

int rec(int k)
{
if (k == 0) return 0;
if ((k%2) == 1) return 1;
if ((k%2) == 0) return 2;
}

int main()
{
    int a[100500], n, i, minimum, k, s = 0, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &k);
    k = rec(k);

    for (i = 1; i <= k; i++)
    {
        minimum = a[1];
        for (j = 1; j <= n; j++)
            if (a[j] < minimum)
                minimum = a[j];
        for (j = 1; j <= n; j++)
            a[j] = minimum - a[j];
    }

    for (j = 1; j <= n; j++)
        s += a[j];
    printf("%d\n", s);
    return 0;
}
