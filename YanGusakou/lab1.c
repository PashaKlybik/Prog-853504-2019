#include <stdio.h>
//var 8
int main()
{
	int number;

	printf("enter first number: ");
	scanf_s("%d", &number);
	number = number % 100 * 100 + number / 100;
	printf("result: %d", number);
	return 0;
}
