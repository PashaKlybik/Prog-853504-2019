/*
	Дано натуральное k и последовательность цифр
	100101102103104…
	в которой выписаны все трехзначные числа. Определить k-ю цифру
	последовательности.
*/
#include <stdio.h> 
#include <math.h>

int main()
{
	char sequenceArray[2701];
	char threeDigitNumber[4];
	int searchValueIndex;

	printf("Enter k: ");
	scanf_s("%d", &searchValueIndex);
	if (!(searchValueIndex < 1 && searchValueIndex > 2700))
	{
		for (int i = 100, j = 0; i <= 999; i++, j += 3)
		{
			itoa(i, threeDigitNumber, 10);
			sequenceArray[j] = threeDigitNumber[0];
			sequenceArray[j + 1] = threeDigitNumber[1];
			sequenceArray[j + 2] = threeDigitNumber[2];
		}
		for (int j = 0; j < searchValueIndex; j++)
		{
			printf("%c", sequenceArray[j]);
		}
		printf("\n\nk-th number of the sequence is equal: %c", sequenceArray[searchValueIndex - 1]);
		return 0;
	}

}