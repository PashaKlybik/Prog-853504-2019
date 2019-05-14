/* 3. Три отрезка. Разработать программу, меню которой позволяет
пользователю выполнить следующие функции:
• Ввести координаты начала и конца трех отрезков в двумерном
пространстве.
• Определить, можно ли из этих отрезков составить треугольник.
• Если это возможно, то определить вид треугольника
(правильный, прямоугольный, равнобедренный, произвольного
вида).
• Вычислить периметр образованного треугольника.
• Вычислить площадь треугольника
• Информация о версии и авторе программы.
• Выход из программы.
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define SIZE 3
#define MAX 128

bool isInt(char str[]) {
	int length = strlen(str);

	for (int i = 0; i < length; i++) {
		bool condition = str[i] < '0' || str[i] > '9';
		if (condition) {
			return false;
		}
	}

	return true;
}

double getDistance(int x1, int y1, int x2, int y2) {
	return sqrt(pow((double)(x1 - x2), 2) + pow((double)(y1 - y2), 2));
}

bool isTriangle(double sideLength[]) {
	double maxLengthOfSide = sideLength[0];
	int indexOfMaxSideLength = 0;

	for (int i = 1; i < SIZE; i++) {
		if (maxLengthOfSide < sideLength[i]) {
			maxLengthOfSide = sideLength[i];
			indexOfMaxSideLength = i;
		}
	}

	double sumOfSide = 0;

	for (int i = 0; i < SIZE; i++) {
		sumOfSide += indexOfMaxSideLength != i ? sideLength[i] : 0;
	}
	return maxLengthOfSide < sumOfSide;
}

bool isEquilateral(double sideLength[]) {
	return sideLength[0] == sideLength[1] == sideLength[2];
}

bool isRight(double sideLength[]) {
	double maxLengthOfSide = sideLength[0];
	int indexOfMaxSideLength = 0;

	for (int i = 1; i < SIZE; i++) {
		if (maxLengthOfSide < sideLength[i]) {
			maxLengthOfSide = sideLength[i];
			indexOfMaxSideLength = i;
		}
	}

	double sumOfSquaresSides = 0;

	for (int i = 0; i < SIZE; i++) {
		sumOfSquaresSides += indexOfMaxSideLength != i ? pow(sideLength[i], 2) : 0;
	}
	
	return pow(maxLengthOfSide, 2) == sumOfSquaresSides;
}

bool isIsosceles(double sideLength[]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			if (sideLength[i] == sideLength[j]) {
				return true;
			}
		}
	}
	return false;
}

double getPerimeter(double sideLength[]) {
	double sum = 0;

	for (int i = 0; i < SIZE; i++) {
		sum += sideLength[i];
	}

	return sum;
}

double getArea(double sideLength[]) {
	double halfPerimeter = getPerimeter(sideLength) / 2;
	double area = sqrt(halfPerimeter * (halfPerimeter - sideLength[0]) * (halfPerimeter - sideLength[1]) * (halfPerimeter - sideLength[2]));
	
	return area;
}

int main() {
	double sideLength[SIZE];

	bool isReenter = true;

	while (isReenter) {
		printf("1 - Data input\n");
		printf("2 - IsTriangle\n");
		printf("3 - Type  of triangle\n");
		printf("4 - Perimeter\n");
		printf("5 - Area\n");
		printf("6 - Copyright\n");
		printf("7 - Exit\n\n");
		
		char str[MAX];
		int temp;
		
		gets(str);
		
		if (isInt(str)) {
			temp = atoi(str);
		}
		else {
			printf("\nWrong input! Try again!\n\n");
			continue;
		}

		switch (temp) {
		case 1:
			for (int i = 0; i < SIZE; i++) {
				int x1, y1, x2, y2;
				
				printf("\nThe coordinates of the points of the segment: \n");
				printf("X1 = ");
				
				gets(str);
				
				if (isInt(str)) {
					x1 = atoi(str);
				}
				else {
					printf("\nWrong input! Try again!\n\n");
					break;
				}
				
				printf("Y1 = ");

				gets(str);
				
				if (isInt(str)) {
					y1 = atoi(str);
				}
				else {
					printf("\nWrong input! Try again!\n\n");
					break;
				}

				printf("X2 = ");

				gets(str);
				
				if (isInt(str)) {
					x2 = atoi(str);
				}
				else {
					printf("\nWrong input! Try again!\n\n");
					break;
				}

				printf("Y2 = ");
				
				gets(str);
				
				if (isInt(str)) {
					y2 = atoi(str);
				}
				else {
					printf("\nWrong input! Try again!\n\n");
					break;
				}
				
				sideLength[i] = getDistance(x1, y1, x2, y2);
			}
			break;
		case 2:
			if (isTriangle(sideLength)) {
				printf("\nThis is a triangle\n\n");
			}
			else {
				printf("\nIt's not a triangle\n\n");
			}
			break;
		case 3:
			if (isTriangle(sideLength)) {
				bool isArbitrary = true;
				
				if (isEquilateral(sideLength)) {
					printf("\nTriangle is equilateral\n\n");
					isArbitrary = false;
				}

				if (isRight(sideLength)) {
					printf("\nTriangle is right\n\n");
					isArbitrary = false;
				}

				if (isIsosceles(sideLength)) {
					printf("\nTriangle is isosceles\n\n");
					isArbitrary = false;
				}
			
				if (isArbitrary) {
					printf("\nTriangle is arbitrary\n\n");
				}
			}
			else
			{
				printf("\nIt's not a triangle\n\n");
			}
			break;

		case 4:
			if (isTriangle(sideLength)) {
				printf("\nPerimeter is %lf\n\n", getPerimeter(sideLength));
			}
			else {
				printf("\nIt's not a triangle\n\n");
			}
			break;
		case 5: 
			if (isTriangle(sideLength)) {
				printf("\nArea is %lf\n\n", getArea(sideLength));
			}
			else {
				printf("\nIt's not a triangle\n\n");
			}
			break;
		case 6:
			printf("\nVersion:    1.0.0\nCopyright  2019 Andrey Vanyuck\n\n");
			break;
		case 7:
			isReenter = false;
			break;
		}
	}

	return 0;
}
