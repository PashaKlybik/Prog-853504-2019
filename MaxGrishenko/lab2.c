//Тетраэдр.Разработать программу, меню которой позволяет выполнить следующие функции : 
//Ввод длины ребра тетраэдра.
//Вывод общей длины всех ребер тетраэдра, высоты, радиус вписанного шара, площади всех граней тетраэдра
//Информация о программе и выход.
//"Грищенко Максим Михайлович 853504
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

float GetFloatData()
{
	float Data;
	char Str[5000];
	while(1)
	{
		scanf("%s",Str);
		Data = atof(Str);
		if (Data != 0) return Data;
		system("clear");
		printf("Wrong 'float' input! Try Again : ");
	}
}

int GetRightMenu()
{
	int Choose;
	char Str[5000];
	while(1)
	{
		scanf("%s",Str);
		Choose = atoi(Str);
		if (Choose != 0 && Choose > 0 && Choose < 9) return Choose;
		system("clear");
		printf("Wrong 'int' input [1;8]! Try Again : ");
	}
}

int main()
{
	system("clear");
	float Data;
	printf("Input the initial data : ");
	Data = GetFloatData();
	while(1) {
		int Choose;
		printf("Choose operation :\n1 - Change data\n2 - Show perimeter\n3 - Show area\n4 - Show volume\n5 - Show height\n6 - Show radius of inserted ball\n7 - Show info\n8 - Exit\n");
		Choose = GetRightMenu();
		system("clear");
		switch(Choose)
		{
			case 1: printf("Input new data : "); Data = GetFloatData(); break;
			case 2: printf("Perimeter = %f", 6 * Data); break;
			case 3: printf("Area = %f",  Data * Data * sqrtf(3)); break;
			case 4: printf("Volume = %f", ((Data * Data * Data * sqrtf(2)) / 12)); break;
			case 5: printf("Height = %f", ((Data * sqrtf(6)) / 3)); break;
			case 6: printf("Radius = %f", ((Data * sqrtf(6)) / 12)); break;
			case 7: printf("Version 1.0.0; Max Grischenko; All rights reserved"); break;
			case 8: return 0;
			default: printf("Wrong Input, try again!"); break;
		}
	}
}
