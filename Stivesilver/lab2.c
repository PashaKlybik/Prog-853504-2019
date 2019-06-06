#include <stdio.h>
//Функция для заказа продуктов
void setVeg(int *a, int *b, int *c){
	do{
		printf ("Кол-во картофеля\n");
		scanf("%d",&(*a));
	}
	while (*a < 0);
	do{
		printf ("Кол-во моркови\n");
		scanf("%d",&(*b));
	}
	while (*b < 0);
	do{
		printf ("Кол-во свеклы\n");
		scanf("%d",&(*c));
	}
	while (*c < 0);
}
//Функция для вывода инфрормации про продукты и их стоймость
void getVeg(int a, int b, int c){
	printf ("У вас: ");
	printf ("Кол-во кортофеля - %d, стоймость - %d р.\n", a, a*500);
	printf ("Кол-во морковочки - %d, стоймость - %d р.\n", b, b*1000);
	printf ("Кол-во кортофеля - %d, стоймость - %d р.\n", c, c*700);
}
//Функция расчета стоймости заказа
void getCash(int a, int b, int c){
	int aSum = a*500;
	int bSum = b*1000;
	int cSum = c*700;
	int allSum = aSum+bSum+cSum;
	int delivery = 15000;

	printf("Стоймость картофеля - %d р.\n", aSum);
	printf("Стоймость марковь - %d p.\n", bSum);
	printf("Стоймость свеклы - %d p.\n", cSum);
	printf("Стоймость доставки - %d p.\n", delivery);
	float discount = 0; 
	if ((a+b+c) > 50)
	{
		discount  = 0.3;
	}
	else if ((a+b+c) >25)
	{
		discount  = 0.3;
	}
	else if ((a+b+c) >10)
	{
		discount  = 0.1;
	}
	printf("Скидка на данный заказ - %d p.\n",(int)(discount*100));
	int cash = allSum-(int)(allSum*discount) + delivery;
	printf("------------------------------\n");
	printf("Общая стоймость - %d p.\n",cash);
}
//информация о магазине 
void info(){
	printf("Название магазина - BsuirVegetables\n");
	printf("Номер лизензии - 931251189\n");
	printf("Контактная информация - someadress@gmail.com\n");
}
//Выход из программы
void exitFromThisProgram(){
	printf("Спасибо, что выбрали BsuirVegetables\n");
	exit(0);
}

int main(){
	int a = 0, b = 0, c = 0;
	while (1){
		int ch;
		printf("Добро пожаловать в магазин BsuirVegetables!\n");
		printf("1. Заказ товаров\n");
		printf("2. Корзина\n");
		printf("3. Рассчет стоймости заказа\n");
		printf("4. Обратная связь\n");
		printf("5. Выход\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				setVeg(&a,&b,&c);
				break;
			case 2:
				getVeg(a,b,c);
				break;
			case 3:
				getCash(a,b,c);
				break;
			case 4: 
				info();
				break;
			case 5:
				exitFromThisProgram();
		}
		printf("********************************\n");
	}
}
