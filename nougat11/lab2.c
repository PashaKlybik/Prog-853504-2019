/*Air Comfort. Компания занимается установкой стеклопакетов;
планируется, что после открытия сайта компании, пользователи
смогут спроектировать и рассчитать стоимость установки
стеклопакетов прямо в интернете. Вам поручается разработать
модуль на С, выполняющий следующие функции:
• Ввод количества окон в квартире
• Ввод количества балконов.
• Ввод этажа, на котором находится квартира
• Расчет и вывод параметров проекта: общая площадь
застекления, стоимость застекления окон, стоимость установки
балконной двери, процентная надбавка.
• Вывод общей стоимости проекта
• Краткая информация о компании и контакты.
• Выход из программы
Справочные сведения. Стоимость одного стандартного оконного
пакета(2,15х1,50 м) составляет $100, включая установку.
Стоимость балконной двери (0,70х2,15 м) составляет $150, 
включая установку. Если квартира находится выше первого
этажа, за установку каждого стеклопакета взимается
дополнительно 15% его стоимости.
*/
#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include<string.h>
int okna=0, balcony=0, floo=0, procent=0,q,kek;
float square=0,cost1=0,cost=0,square1,square2,cost2;
char s[50000];// Zadaiya laby))0)
void Func1()
{
    printf("Enter a number windows\n");
   scanf("%s",s);
   okna=atoi(s);
    system("@cls||clear");
    if (okna==0) kek=system("D:\\1.mp4");
}
void Func2()
{
    printf("Vvelide kol-vo balkonov\n");
   scanf("%s",s);
   okna=atoi(s);
   system("@cls||clear");
    if (balcony==0) kek=system("D:\\1.mp4");
}
void Func3()
{
    printf("Enter floor\n");
    scanf("%s",s);
    okna=atoi(s);
    system("@cls||clear");
    if (floo==0) kek=system("D:\\1.mp4");
}
void Func4()
{
    square1=2.15*1.5*okna;
    cost1=square1*100;
    square2=0.7*2.15*balcony;
    square=square1+square2;
    printf("Square of window = %f\n",square1);
    printf("Cost of glass = %f $\n",cost1);
    cost2=square1*150;
    printf("Cost setup balcona = %f $\n", cost2);
    if (floo>1) procent=15;
    printf("Procentnaya nadbavka - %d procentov\n",procent);
}
void Func5()
{
    printf("Cost of project - %f $",cost1+cost2);
    printf("Press any key to continue...");
}
void Func6()
{
    printf("Author - Vlad Kuzma. Number +37522813371488\n");
     printf("press any key to continue...");
}

int main()
{
    setlocale(LC_ALL,"Rus");
    for (;;)
    {
        printf("What are you doing, man?\n");
        printf("1 - Enter a number of Window in your flat\n");
        printf("2 - Enter a number of balcony in yout flat.\n");
        printf("3 - Enter a number of floor of youe flat.\n");
        printf("4 - Output settings Project\n");
        printf("5 - Output cost project\n");
        printf("6 - Output Author\n");
        printf("7 - Exit\n");
	      scanf("%s",s);
	      if (strcmp(s,"1")==0) Func1(); else
        if (strcmp(s,"2")==0) Func2(); else
        if (strcmp(s,"3")==0) Func3(); else
        if (strcmp(s,"4")==0) Func4(); else
        if (strcmp(s,"5")==0) Func5(); else
        if (strcmp(s,"6")==0) Func6(); else
        if (strcmp(s,"7")==0) return 0; else
	    printf("Vvedite norm");
    }
}
