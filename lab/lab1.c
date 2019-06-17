#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

int main()
{//29 variant
    setlocale(LC_ALL, "RUS");
    int n;
    printf("Введите число n: ");
    scanf("%d",&n);
    printf("\n");
    char str[100];
    itoa(n,str,10);
    bool order=false;
    bool norder=false;
    bool equal=false;
    for(int i=0; i!=strlen(str)- 1; i++)

    {
        if(str[i]==str[i+1])
        {
            for(int i=0; i!=strlen(str)- 1; i++)
            {
                if(str[i]==str[i+1])
                    continue;
                else
                    equal=true;
            }
        }
        if(str[i] > str[i+1])
            order = true;

        if(str[i] < str[i+1])
            norder = true;

        if(norder&&order)
            break;
    }

    if(norder&&order)
        printf("Число неверное,попробуйте снова");
    else if (!equal)
        printf("Числа равны");
    else if(!order)
        printf("Все цифры упорядочены по возрастанию");
    else if (!norder)
        printf("Все цифры упорядочены по убыванию");
    return 0;
}
