#include <stdio.h> 
#include <conio.h>
#include <math.h>
/*
Variant-6
*/
int main() 
{
	float fraction;
	int sumOfFirstThreeDigits = 0;

	printf("Enter fraction number: ");
	scanf_s("%f", &fraction);
	fraction = (fabs(fraction) - (int)(fabs(fraction))) * 1000;
	int threeDigits = fraction;
	for (int i = 0; i < 3; i++)
	{
		sumOfFirstThreeDigits += threeDigits % 10;
		threeDigits /= 10;
	}
	printf("Sum of the first three digits: %d", sumOfFirstThreeDigits);
	return 0;
}
