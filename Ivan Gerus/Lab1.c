#include <stdio.h>
int fvozrastanie(int a);
int fybivanie(int a);
int main()
{
    int Number,vybor,i;
    printf("Vvedyte number:");
    if (scanf("%d", &Number) != 1||Number<=0)//Проверка введённого числа
    {
        printf("You died\n");
        return 0;
    }
    printf("Choose:\n1)Vozrastanie;\n2)Ybivanie.\nYour choise:");
    scanf("%d", &vybor);
    if (vybor!=1&&vybor!=2)//Проверка выбора
    {
        printf("You died\n");
        return 0;
    }
    switch(vybor)
    {
        case 1:
            for(i=10; i<Number; i++)
            {
                if(fvozrastanie(i))
                {
                    printf("%d\n", i);
                };
            };
            break;
        case 2:
            for(i=10; i<Number; i++)
            {
                if(fybivanie(i))
                {
                    printf("%d\n", i);
                };
            };
            break;
    }
    return 0;
}
int fvozrastanie(int a)
{
    while(a>0)
    {
        int ostatok1,ostatok2;
        ostatok1=a%10;
        a/=10;
        ostatok2=a%10;
        if(a==0)
            return 1;
        if(ostatok2<ostatok1)
        {
            continue;
        }
        
        else
            return 0;
    }
    return 0;
}
int fybivanie(int a)
{
    while(a>0)
    {
        int ostatok1,ostatok2;
        ostatok1=a%10;
        a/=10;
        ostatok2=a%10;
        if(ostatok2>ostatok1)
        {
            continue;
        }
        if(a==0)
            return 1;
        else
            return 0;
    }
    return 0;
}
