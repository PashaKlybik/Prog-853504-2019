/* Меры длины. Разработать программу, меню которой позволяет выполнить следующие функции :
    • Ввод значения длины(километры, метры, сантиметры, миллиметры).
	• Перевод длины в русские традиционные единицы(версты, аршины, сажени, вершки)
	• Перевод длины в английские традиционные единицы(мили, ярды, футы, дюймы)
	• Вывод отчета, представляющего введенное значение в 1)километрах, 2) метрах, 3) сантиметрах, 4) миллиметрах.
	• Информация о версии и авторе программы
	• Выход из программы.
*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <assert.h>

#define versh 0.04445
#define arsh 0.7112
#define saz 2.1336
#define verst 1066.8
#define inch 0.0254
#define foot 0.3048
#define yard 0.9144
#define mile 1609.344
#define MAX 2000000000

double a, digit;

double inputLenght(double lenght)
{
	system("cls");
	int chose = 0;
	printf("1 -> Kilometers\n");
	printf("2 -> Metres\n");
	printf("3 -> Centimeters\n");
	printf("4 -> Millimeters\n");
	scanf_s("%d", &chose);
	assert(chose >= 1 && chose <= 4); //Макрос, проверяющий условие expression 
		switch (chose)
		{
		case 1:
			lenght = lenght * 1000;
			break;
		case 2:
			break;
		case 3: 
			lenght = lenght / 100;
			break;
		case 4: 
			lenght = lenght / 1000;
			break;
		default:
			break;
		}
	return lenght;
}

void showLenght(double list)
{
	printf("Kilometers: %lf", list / 1000);
	printf("\nMeters: %lf", list);
	printf("\nCentimeters: %lf", list * 100);
	printf("\nMillimeters: %lf\n", list * 1000);
}

void conversionRus(double con)
{
	printf("Vershki: %lf", digit / versh);
	printf("\nArshini: %lf", digit / arsh);
	printf("\nSazni: %lf", digit / saz);
	printf("\nVersty: %lf", digit / verst);
}

void conversionEng(double tradi)
{
	printf("Inches: %lf", digit / inch);
	printf("\nFoots: %lf", digit / foot);
	printf("\nYards: %lf", digit / yard);
	printf("\nMiles: %lf", digit / mile);
}

void Information()
{
	printf("Performed the laboratory by the student group 853504 Vecherinsky Maxim\n");
	printf("Project 1 - Debug - Win32 - Assembly");
}

int main()
{
	while (1)
	{
		system("cls");
		printf("1 -> Enter the value\n");
		printf("2 -> Conversion to traditional Russion measure\n");
		printf("3 -> Conversion to traditional English measure\n");
		printf("4 -> Report\n");
		printf("5 -> About programm\n");
		printf("6 -> Exit\n");
		int chosing;
		scanf_s("%d", &chosing);
		assert(chosing >= 1 && chosing <= 6); 
		switch (chosing)
		{
		case 1: 
			system("cls"); // отчистка консоли
			printf("Input digit\n");
			scanf_s("%lf", &a);	
			assert(a >= 1 && a <= MAX);
			digit = inputLenght(a);
			break;
		case 2:
			system("cls");
			conversionRus(a);
			_getch();// выход из case по нажатию клавиши
			break;
		case 3:
			system("cls");
			conversionEng(a);
			_getch();
			break;
		case 4:
			system("cls");
			showLenght(digit);
			_getch();
			break;
		case 5:
			system("cls");
			Information();
			_getch();
			break;
		case 6: 
			exit(0);
		}
	}
	return 0;
}
