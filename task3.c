#include <stdio.h>
#include <string.h>
#define MAX 1000000


int main()
{
    int count = 0, i, k = 0;
    long length;
    char  string[MAX], OutPutString[MAX], symbol;
    scanf("%s", string);
    symbol = string[0];
    length = strlen(string);
    for (i = 0; i < length; i++)
    {
        if (string[i] == symbol)
            count++;
        else
        {
            switch(count)
            {
                case 1:
                    OutPutString[k] = symbol; k++;
                    break;
                case 2:
                    OutPutString[k] = symbol; k++;
                    OutPutString[k] = symbol; k++;
                    break;
                default:
                    count = count + '0';
                    OutPutString[k] = count; k++;
                    OutPutString[k] = symbol; k++;
                    break;
            }
            symbol = string[i];
            count = 1;
        }
    }
    count = count + '0';
    OutPutString[k] = count; k++;
    OutPutString[k] = symbol;
    printf("%s", OutPutString);
}
