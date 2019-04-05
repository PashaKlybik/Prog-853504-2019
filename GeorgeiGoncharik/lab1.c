#include <stdio.h> 
#include <math.h>
//Variant-6
int main() 
{
	float fractNumber;
	int sumOfFirstThreeFractDigits = 0;

	printf("Enter fraction number: ");
	scanf_s("%f", &fractNumber);
	int firstThreeFractDigits = (fabs(fractNumber) - (int)(fabs(fractNumber))) * 1000;
	for (int i = 0; i < 3; i++)
	{
		sumOfFirstThreeFractDigits += firstThreeFractDigits % 10;
		firstThreeFractDigits /= 10;
	}
	printf("Sum of the first three digits: %d", sumOfFirstThreeFractDigits);
	return 0;
}
