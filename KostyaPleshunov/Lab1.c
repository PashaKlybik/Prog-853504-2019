#include "pch.h"
#include <stdio.h>
#include <cstdlib>
int main()
{
    int i = 0;
    for (int m = 1; ; ++m)
	for (int k = 1; k <= m; ++k)
	    for (int l = k; l <= m; ++l)
	     if (k * k + l * l == m * m)
	{
             printf("(%i,%i,%i)\n", x, y, z);
	     if (++i == 10)
	     goto t;
        }
    t:
    system("pause");
return 0;
}
