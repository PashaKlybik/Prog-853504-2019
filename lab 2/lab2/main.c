#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    printf("\n");
    int europrice;
    int year;
    int carrun;
    int enginecap;
    printf("Цена машины в ЕС-");
    scanf("%d",&europrice);
    printf("Рабочий объем двигателя(в см куб.)-");
    scanf("%d",&enginecap);
    printf("Год выпуска автомобиля-");
    scanf("%d",&year);
    printf("Расстояние прогона(в км)-");
    scanf("%d",&carrun);
    printf("-------------------------------------------------------------------------");
     printf("\n");
    if (year<=3)
    {
        printf("Цена машины-%1.2f евро",europrice+carrun*0.5+enginecap*0.6);
    }
    if (year>3&year<=10)
    {
        if(enginecap<2500)
            printf("Цена машины-%1.2f евро",europrice+carrun*0.5+enginecap*0.35);
        if(enginecap>=2500)
            printf("Цена машины-%1.2f евро",europrice+carrun*0.5+enginecap*0.6);
    }
    if (year>10&year<14)
    {
        printf("Цена машины-%1.2f евро",europrice+carrun*0.5+enginecap*0.6);
    }
    if (year>=14)
    {
        printf("Цена машины-%1.2f евро",europrice+carrun*0.5+enginecap*2);
    }
    return 0;
}
