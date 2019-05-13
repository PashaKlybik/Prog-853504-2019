/* ¬ариант 3
 “ри отрезка.–азработать программу, меню которой позвол€ет
 пользователю выполнить следующие функции :
 Х ¬вести координаты начала и конца трех отрезков в двумерном
 пространстве.
 Х ќпределить, можно ли из этих отрезков составить треугольник.
 Х ≈сли это возможно, то определить вид треугольника
 (правильный, пр€моугольный, равнобедренный, произвольного
 вида).
 Х ¬ычислить периметр образованного треугольника.
 Х ¬ычислить площадь треугольника
 Х »нформаци€ о версии и авторе программы.
 Х ¬ыход из программы.
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define SIZE 3
#define MAX 128

struct coordinateOfPoint {
	int X;
	int Y;
};

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

double getDistance(struct coordinateOfPoint point1, struct coordinateOfPoint point2) {
	return sqrt(pow((double)(point1.X - point2.X), 2) + pow((double)(point1.Y - point2.Y), 2));
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
	struct coordinateOfPoint coordinatesOfSegmentPoints[2];
	double sideLength[SIZE];

	bool isReenter = true;
	int temp;

	while (isReenter) {
		printf("1 - Data input\n");
		printf("2 - IsTriangle\n");
		printf("3 - Type  of triangle\n");
		printf("4 - Perimeter\n");
		printf("5 - Area\n");
		printf("6 - Copyright\n");
		printf("7 - Exit\n\n");
		
		char str[MAX];
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
				printf("\nThe coordinates of the points of the segment: \n");
				
				printf("X1 = ");
				
				gets(str);
				if (isInt(str)) {
					coordinatesOfSegmentPoints[0].X = atoi(str);
				}
				else {
					printf("\nWrong input! Try again!\n\n");
					break;
				}
				
				printf("Y1 = ");

				gets(str);
				if (isInt(str)) {
					coordinatesOfSegmentPoints[0].Y = atoi(str);
				}
				else {
					printf("\nWrong input! Try again!\n\n");
					break;
				}

				printf("X2 = ");

				gets(str);
				if (isInt(str)) {
					coordinatesOfSegmentPoints[1].X = atoi(str);
				}
				else {
					printf("\nWrong input! Try again!\n\n");
					break;
				}

				printf("Y2 = ");
				
				gets(str);
				if (isInt(str)) {
					coordinatesOfSegmentPoints[1].Y = atoi(str);
				}
				else {
					printf("\nWrong input! Try again!\n\n");
					break;
				}
				
				sideLength[i] = getDistance(coordinatesOfSegmentPoints[0], coordinatesOfSegmentPoints[1]);
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
			if (isEquilateral(sideLength)) {
				printf("\Area is %lf\n\n", getArea(sideLength));
			}
			else {
				printf("\nIt's not a triangle\n\n");
			}
			break;
		case 6:
			printf("Version:    1.0.0\nCopyright  2019 Andrey Vanyuck\n\n");
			break;
		case 7:
			isReenter = false;
			break;
		}
	}

	return 0;
}