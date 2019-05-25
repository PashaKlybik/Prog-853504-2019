/*
 Меры длины. Разработать программу, меню которой позволяет выполнить следующие функции:
 Ввод значения длины (километры, метры, сантиметры, миллиметры).
 Перевод длины в русские традиционные единицы (версты, аршины, сажени, вершки)
 Перевод длины в английские традиционные единицы (мили, ярды, футы, дюймы)
 Вывод отчета, представляющего введенное значение в 1)километрах, 2) метрах, 3) сантиметрах, 4) миллиметрах.
 Информация о версии и авторе программы
 Выход из программы.
 */

#include <stdio.h>
#include <locale.h>

void report(double centimeters)
{
    double millimeters = centimeters * 10,
    meters = centimeters / 100,
    kilometers = meters / 1000;
    printf("\nМиллиметры = %.3lf\nСантиметры = %.3lf\nМетры = %.3lf\nКилометры = %.3lf\n\n", millimeters, centimeters, meters, kilometers);
}

void convertToEnglishUnitsOfMeasure(double centimeters)
{
    double miles, yards, feet, inches;
    inches = centimeters / 2.54;
    feet = inches / 12;
    yards = feet / 3;
    miles = yards / 1760;
    printf("\nМили = %lf\nЯрды = %lf\nФуты = %lf\nДюймы = %lf\n\n", miles, yards, feet, inches);
}

void convertToRussianUnitsOfMeasure(double centimeters)
{
    double millimeters = centimeters * 10;
    double versts, arshina, fathom, tops;
    tops = millimeters / 44.45;
    arshina = tops / 16;
    fathom = arshina / 3;
    versts = fathom / 500;
    printf("\nВерсты = %lf\nАршины = %lf\nСажени = %lf\nВершки = %lf\n\n", versts, arshina, fathom, tops);
}

double converToCentimeters(double num, int unitsOfMeasure)
{
    double centimeters = 0;
    switch (unitsOfMeasure)
    {
        case 1:
            centimeters = num / 10;
            break;
        case 2:
            centimeters = num;
            break;
        case 3:
            centimeters = num * 100;
            break;
        case 4:
            centimeters = num * 100000;
            break;
    }
    return centimeters;
}

void information()
{
    printf("\nВерсия номер 1.0.1.\nПодготовила Ушакова Полина, группа 853504.\n\n");
}

int main()
{
    int unitsOfMeasure = 0, isInputTrue = 0, answer = 0, answer1 = 1;
    double number = 0;
    setlocale(LC_ALL, "Russian");
    while (1)
    {
        while(!isInputTrue)
        {
            printf("Введите число:\n");
            if (scanf("%lf", &number)==0)
            {
                printf("Не подходит условию.\n");
                return 0;
            }
            printf("Вырите единицы измерения\n1:мм\n2:см\n3:м\n4:км\n");
            scanf("%d", &unitsOfMeasure);
            if (number < 0 || unitsOfMeasure < 1 || unitsOfMeasure > 4)
            {
                printf("Не подходит условию.\n");
                isInputTrue = 0;
                continue;
            }
            else
            {
                number = converToCentimeters(number, unitsOfMeasure);
                do
                {
                    printf("1)Перевод длины в русские традиционные единицы\n2)Перевод длины в английские традиционные единицы\n3)Вывод отчета\n4)Информация\n5)Выход\n");
                    scanf("%d", &answer);
                    if(answer < 1 || answer > 5)
                    {
                        printf("Не подходит условию.\n");
                    }
                } while (answer < 1 || answer > 5);
                
                switch (answer)
                {
                    case 1:
                        convertToRussianUnitsOfMeasure(number);
                        break;
                    case 2:
                        convertToEnglishUnitsOfMeasure(number);
                        break;
                    case 3:
                        report(number);
                        break;
                    case 4:
                        information();
                        break;
                    case 5:
                        return 0;
                }
                printf("Если хотите ввести еще раз, нажмите 1\n");
                scanf("%d", &answer1);
                if (answer1 != 1)
                {
                    return 0;
                }
            }
        }
    }
}

