#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool fl(long long chis)
{
    while (chis > 0)
    {
        int last = chis % 10;
        if ((last == 4) || (last == 7))
            return true;
        chis /= 10;
    }
    return false;
}


int main()
{
    int res_i, i, flag, ans = 0;
    long long n;
    scanf("%lld", &n);
    for (long long i = 1; i < round(sqrt(n)); i++)
    {
        if ((n % i) == 0)
	{
            if (fl(i))
		ans++;
            if (((n / i) != i) && fl(n/i))
		ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}

