#include <stdio.h>
#include <stdlib.h>

int l1, r1, k, a[100000005], l, ans;
int main()
{
    scanf("%d %d %d", &l1, &r1, &k);
    a[0] = 0;
    l = 10;
    for (int i = 1; i <= 100000000; i++)
    {
        if (i == l)
            l *= 10;
        a[i] = (i % 10) * (l / 10) + a[i / 10];
        if ((i >= l1) && (i <= r1) && (abs(i - a[i]) <= k))
            ans++;
    }
        printf("%d\n", ans);
    return 0;
}