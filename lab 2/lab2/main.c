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
    printf("���� ������ � ��-");
    scanf("%d",&europrice);
    printf("������� ����� ���������(� �� ���.)-");
    scanf("%d",&enginecap);
    printf("��� ������� ����������-");
    scanf("%d",&year);
    printf("���������� �������(� ��)-");
    scanf("%d",&carrun);
    printf("-------------------------------------------------------------------------");
     printf("\n");
    if (year<=3)
    {
        printf("���� ������-%1.2f ����",europrice+carrun*0.5+enginecap*0.6);
    }
    if (year>3&year<=10)
    {
        if(enginecap<2500)
            printf("���� ������-%1.2f ����",europrice+carrun*0.5+enginecap*0.35);
        if(enginecap>=2500)
            printf("���� ������-%1.2f ����",europrice+carrun*0.5+enginecap*0.6);
    }
    if (year>10&year<14)
    {
        printf("���� ������-%1.2f ����",europrice+carrun*0.5+enginecap*0.6);
    }
    if (year>=14)
    {
        printf("���� ������-%1.2f ����",europrice+carrun*0.5+enginecap*2);
    }
    return 0;
}
