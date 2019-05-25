/*Ввод радиуса шара, вывод площади, объема, длины ребра вписанного тетраэдра,
  площади сечения на вводимом расстоянии от центра*/

#include <stdio.h>
#include <math.h>
#include <limits.h>

struct Shar
{
    double s;
    double v;
    double l;
    double s1;
};

double RadInput(int min, int max)
{
    double a;
    int res = 0;
    do
    {
       scanf("%le",&a);
       if ((a < min) || (a > max))
       {
           printf("Invalid input, try again!\n");
       }
       else
       {
           res = 1;
       }
       //fflush(stdin);
    }while (res!=1);
    return a;
}

int Input (int min, int max)
{
    int a,res = 0;
    do
    {
        scanf("%d",&a);
        fflush(stdin);
        if ((a < min) || (a > max))
        {
           printf("Invalid input, try again!\n");
        }
        else
        {
           res = 1;
        }
    }while (res!=1);
}

double CountS(double r)
{
    return 4*r*r*M_PI;
}

double CountV(double r)
{
    return 4/3*r*r*r*M_PI;
}

double CountL(double r)
{
    return r*2*sqrt(6)/3;
}

double CountS1(double r, double dist)
{
    return M_PI*(r-dist)*(r+dist);
}

//конец сторонних функций

int main()
{
    double r = -1, dist = 0;
    int choice, res;
    _Bool cont = 1;
    struct Shar shar;
    char progInfo[] = "Lab 2 v0.0.3 beta, developed by me.\n";
    shar.l = -1;
    do
    {
        printf("What do you want?\n");
        printf("1 - Enter radius\n");
        printf("2 - Enter distance from the center to a cross-section\n");
        printf("3 - Show info about the sphere\n");
        printf("4 - Show info about the program \n");              
        printf("5 - Exit \n \n");
        choice = Input(1, 5);
        if (choice == 1)
        {
            r = RadInput(0, INT_MAX);
            dist = 0;
            continue;
        }

        if (choice == 2)
        {
            if (r == -1)
            {
                printf("Enter radius first!\n");
                continue;
            }
            dist = RadInput(0,r); 
            continue;
        }      

        if (choice == 3)
        {
            if (r == -1)
            {
                printf("No radius entered. There's no info.\n");
                continue;
            }
            shar.s = CountS(r);
            shar.v = CountV(r);
            shar.l = CountL(r);
            shar.s1 = CountS1(r,dist);          
            printf("Radius: %.3le\n",r);        
            printf("Square: %.3le\n",shar.s);        
            printf("Volume: %.3le\n",shar.v);        
            printf("square of a cross-section %.3le from the center: %.3le\n\n", dist, shar.s1);        

        }

        if (choice == 4)
        {
            printf("%s\n",progInfo);
        }

        if (choice == 5)
        {
            cont = 0;
        }
    }while(cont);
}
