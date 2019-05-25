#include <stdio.h>
#include <stdlib.h>

// eVegetables. Торговое предприятие, реализующее продукты
//питания, планирует открыть интернет-магазин по продаже
//овощей.
//Предприятие заказывает вам разработку программного модуля
//на С, который должен выполнять следующие функции:
//• Заказ картофеля (кг).
//• Заказ моркови (кг).
//• Заказ свеклы (кг).
//• Корзина (вывод сведений о количестве заказанных овощей и
//их стоимости).
//• Расчет стоимости заказа (сведения о стоимости каждого вида
//овощей, затратах на доставку, скидке на данный заказ, общей
//стоимости заказа).
//Обратная связь (название магазина, номер лицензии,
//контактная
//информация).
//• Выход из программы. 

char string[500];  //переменная для ввода значений

int Input()       //проверка на ввод
{
	int value = 0;
	while (value==0)
	{		
		scanf("%s", string);
		value = atoi(string);
		if (value == 0) printf("Wrond input, try again\n");
		if (value < 0)
		{
			value = 0;
			printf("Wrond input, try again\n");
		}
	}
	return value;

}

void SetVegetables(int *potato, int *carrot, int *beet)  //указатели, чтобы изменялись значения переменных после ввода
{		
		printf("Set value of potato:");
		*potato = Input();
		printf("Set value of carrot:");
		*carrot = Input();
		printf("Set value of beet:");
		*beet = Input();	
}

void GetVegetables(int potato, int carrot, int beet)
{
	printf("Kg of potato:%d\n",potato);
	printf("Kg of carrot:%d\n", carrot);
	printf("Kg of beet:%d\n", beet);
	printf("To pay:%d\n", (potato * 500 + carrot * 1000+ beet * 700));
}

void Calculate(int potato, int carrot, int beet)
{	
	int cost_potato = potato * 500;
	int cost_carrot = carrot * 1000;
	int cost_beet = beet * 700;
	int all_cost = cost_potato + cost_carrot + cost_beet;
	printf("Cost of potato:%d\n",cost_potato);
	printf("Cost of potato:%d\n",cost_carrot);
	printf("Cost of potato:%d\n",cost_beet);
	printf("Cost of delivery:15000\n");
	float discount = 0;
	if ((potato+carrot+beet) > 50)
	{
		discount = 0.3;
	}
	else if ((potato + carrot + beet) > 25)
	{
		discount = 0.3;
	}
	else if ((potato + carrot + beet) > 10)
	{
		discount = 0.1;
	}

	printf("Discount:%d\n",(int)(discount*100));
	int total_cost = all_cost - (all_cost*discount) + 15000;
	printf("Total cost:%d\n", total_cost);

}

void Feedback()
{	
	printf("Name of shop - BsuirVegetables\n");
	printf("Number of licence - 931251189\n");
	printf("Mail - bsuir@gmail.com\n");
}


int main()
{
	int choice;
	int potato = 0, carrot = 0, beet = 0;
	while (1)
	{
		
		printf("1-Order vegetables\n2-Check list\n3-Calculate the cost of the order\n4-Feedback\n5-Exit\n");
		choice=Input();
		switch (choice)
		{
		case 1:SetVegetables(&potato, &carrot, &beet); break;
		case 2:GetVegetables(potato, carrot, beet); break;
		case 3:Calculate(potato, carrot, beet); break;
		case 4:Feedback(); break;
		case 5:return 0;
		default:printf("Incorrect choice\n");
		}
	}

	return 0;
}

