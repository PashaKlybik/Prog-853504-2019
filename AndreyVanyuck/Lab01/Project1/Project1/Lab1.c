#include <stdio.h>
#include <math.h>

void main() {
	int k, cube, temp, a;
	int num = 0; //номер цифры числа в последовательности
	int count;   // кол-во цифр в числе 

	printf("Enter k:");
	scanf_s("%d", &k);
	printf("Out sequence:");

	for (int i = 1; num < k; i++) {
		cube = pow(i, 3);
		printf("%d",cube);
		count = 1;

		for (temp = 10; cube / temp != 0; count++) {
			temp *= 10;
		}

		num += count;  //номер последней цифры
	}

	num -= count;
	temp /= 10;

	while(num != k){
		a = cube / temp % 10;
		num++;
		temp /= 10;
	}

	printf("\nK-th digit sequence: %d", a);
}