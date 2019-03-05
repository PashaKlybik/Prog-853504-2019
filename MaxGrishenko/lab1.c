// 7 Вариант (Грищенко Максим)

#include <stdio.h>
#include <conio.h>

int main()
{
	int Sequence,Result;
	printf ("Enter sequence : ");
	scanf("%d",&Sequence);
	if ((Sequence > 0) && (Sequence < 2701)) {        //Проверка допустимых знач. k-ой послед.
		int Number = 100,Counter = 0;
		if (Sequence / 3 >= 1) {			   	//Обработка исключения для 3-x знач.ч.
			while (Counter < Sequence / 3){	//Ищем нужное трехзначное число
				Number++;
				Counter++;
			}
			if (Sequence % 3 == 0) {           //Обработка для перехода на другое ч.
				Number--;
			}
		}
		printf("Number of threes : %d\n",Number);
		int Way = Sequence % 3;                //Определяем ветку
		switch(Way){                    //Изымаем нужную цифру из 3-х знач. ч.
			case 1:printf("Result : %d", Number / 10 / 10);break;
			case 2:printf("Result : %d", Number / 10 % 10);break;
			default:printf("Result : %d", Number % 100 % 10);break;
		}
	}
	else printf("Wrong diapason!");
	getch();
	return 0;
}
