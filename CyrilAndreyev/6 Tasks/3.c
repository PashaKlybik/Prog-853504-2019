#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[500000], buf;
    int len = 1, i;
    scanf("%s", s);
    strcat(s, "~");
    buf = s[0];
    for (i = 1; i < strlen(s); i++)
    {
        if (s[i] == s[i - 1])
            len++;
        else
        {
            if (len > 2)
                printf("%d%c", len, buf);
            if (len == 2)
                printf("%c%c", buf, buf);
            if (len == 1)
                printf("%c", buf);
            len = 1;
            buf = s[i];
        }
    }
    printf("\n");
    return 0;
}
