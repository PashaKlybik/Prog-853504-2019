/************************************************************
 *1. Тетраэдр. Разработать программу, меню которой позволяет*
 *выполнить следующие функции:                              *
 *• Ввод длины ребра тетраэдра.                             *
 *• Вывод общей длины всех ребер тетраэдра.                 *
 *• Вывод площади всех граней тетраэдра.                    *
 *• Вывод объема тетраэдра.                                 *
 *• Вывод высоты тетраэдра.                                 *
 *• Вывод радиуса вписанного шара.                          *
 *• Информация о версии и авторе программы.                 *
 *• Выход из программы.                                     *
 ************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float a = 0;

void input()
{
    char str[100500];
    scanf("%s", str);
    a = atof(str);
    if (a <= 0)
        printf("Неверный ввод!\n");
}

void notInitialized()
{
    printf("Ещё не задана длина ребра тетраэдра!\n");
}

void allEdges()
{
    if (a > 0)
        printf("%f\n", 6.0 * a);
    else
        notInitialized();
}

void allVertices()
{
    if (a > 0)
        printf("%f\n", sqrt(3) * a * a);
    else
        notInitialized();
}

void volume()
{
    if (a > 0)
        printf("%f\n", sqrt(2) * a * a * a / 12.0);
    else
        notInitialized();
}

void height()
{
    if (a > 0)
        printf("%f\n", sqrt(2.0/3.0) * a);
    else
        notInitialized();
}

void insphereRadius()
{
    if (a > 0)
        printf("%f\n", sqrt(6) * a / 12.0);
    else
        notInitialized();
}

void info()
{
    printf("Version 1.0 Public Release.\n");
    printf("Автор: Андреев Кирилл Васильевич, гр. 853504.\n");
}

void vyhod()
{
    exit(0);
}

void menu()
{
    char s[100500];
    printf("1 — Ввод длины ребра тетраэдра.\n");
    printf("2 — Вывод общей длины всех ребер тетраэдра.\n");
    printf("3 — Вывод площади всех граней тетраэдра.\n");
    printf("4 — Вывод объема тетраэдра.\n");
    printf("5 — Вывод высоты тетраэдра.\n");
    printf("6 — Вывод радиуса вписанного шара.\n");
    printf("7 — Информация о версии и авторе программы.\n");
    printf("8 — Выход из программы.\n");
    scanf("%s", s);
    if (strlen(s) != 1)
    {
        printf("Неверный ввод!\n");
        return;
    }
    int ans = atoi(s);
    switch (ans)
    {
        case 1:
            input();
            break;
        case 2:
            allEdges();
            break;
        case 3:
            allVertices();
            break;
        case 4:
            volume();
            break;
        case 5:
            height();
            break;
        case 6:
            insphereRadius();
            break;
        case 7:
            info();
            break;
        case 8:
            vyhod();
            break;
        default:
            printf("Неверный ввод!\n");
            break;
    }
}

int main()
{
    /*Цикл бесконечный для того, чтобы пользователь
    имел возможность ввести входные данные несколько раз
    без повторного запуска программы. 
    Выход из программы осуществляется в функции void menu()
    при выборе пользователем соответствующего пункта меню.*/
    while (1)
    {
        menu();
    }
    return 0;
}