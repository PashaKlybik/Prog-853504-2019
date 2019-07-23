//Тетраэдр. Разработать программу, меню которой позволяет выполнить следующие функции:
//• Ввод длины ребра тетраэдра.
//• Вывод общей длины всех ребер тетраэдра.
//• Вывод площади всех граней тетраэдра.
//• Вывод объема тетраэдра.
//• Вывод высоты тетраэдра.
//• Вывод радиуса вписанного шара.
//• Информация о версии и авторе программы.
//• Выход из программы. 

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void menu() {
	printf("\n1) Calculate a length of all edges\n");
	printf("2) Calculate an area of all verges\n");
	printf("3) Calculate a volume\n");
	printf("4) Calculate a height\n");
	printf("5) Calculate a radius\n");
	printf("6) Change a lenght\n");
	printf("7) About\n");
	printf("8) Exit");
}

void edges(int length) {
	int result=length*6;
	printf("A length of all edges is: %d", result);
}

void verges(int length) {
	float result=(pow(length,2)*1.73205)/4.0;
	printf("An area of all verges is: %f", result);
}

void volume(int length) {
	float result=(pow(length,3)*1.41421)/12.0;
	printf("A volume is: %f", result);
}

void height(int length) {
	float result=sqrt(2.0/3.0)*length;
	printf("A height is: %f", result);
}

void radius(int length) {
	float result=length/(2*sqrt(6));
	printf("A radius is: %f", result);
}

int changelen() {
	int var;
	printf("Input a new value: ");
	scanf("%d", &var);
	return var;	
}

void about() {
	printf("------------------LAB2------------------\n");
	printf("Version: beta 1.0\n");
	printf("Author: JailSeed\n");
	printf("URL: jailseed.xyz\n");
	printf("----------------------------------------\n");
}

int main() {
	int length, choose;
	printf("Length: ");
        while (scanf("%d",&length) == 0 ) {
        	printf("Wrong input, input a new value: ");
        	while(getchar()!='\n'); // Чистим буфер
        }
	while(1) {
		menu();
		printf("\nChoose your option: ");
		scanf("%d", &choose);
		switch (choose) {
			case 1: system ("clear"); edges(length); break;
			case 2: verges(length); break;
			case 3: volume(length); break;
			case 4: height(length); break;
			case 5: radius(length); break;
			case 6: length=changelen();  break;
			case 7: about(); break;
			case 8: return 0; break;
			default: printf("Invalid input"); break;
		}
	}
}
