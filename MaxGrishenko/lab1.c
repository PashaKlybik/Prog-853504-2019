// 7 Вариант (Грищенко Максим)

#include <stdio.h>

int main()
{
	int Sequence,Result;
	printf ("Enter sequence : ");
	scanf("%d",&Sequence);
	if ((Sequence < 0) && (Sequence > 2701)) {		//Диапозон значений
		printf("Wrong diapason!");
		return 0;
	}
	int Way = Sequence % 3;					//Определяем нужный столбец для вычисления
	switch(Way){
		case 1:Result = Sequence / 270 + 1;break;	//Сотни
		case 2:Result = Sequence % 270 / 30;break;	//Десятки
		default:{					//Единицы
			if (!(Sequence % 30)) {			
				Result = 9;
			}
			else Result = Sequence % 30 / 3 - 1;	
			break;
		}
	}
	printf("Result : %d",Result);
	return 0;
}
