#include <stdio.h> 
#include <conio.h>
#include <string.h>
/*
Variant-6
*/
int ConvertCharToInt(char letter)
{
	switch (letter)
	{
	case '1':return 1;
	case '2':return 2;
	case '3':return 3;
	case '4':return 4;
	case '5':return 5;
	case '6':return 6;
	case '7':return 7;
	case '8':return 8;
	case '9':return 9;
	case '0':return 0;
	}
}

int main() {
	char fraction[15];

	printf("Enter fraction number: ");
	gets_s(fraction, 14);
	int lengthOfFraction = strlen(fraction);
	for (int i = 0; i < lengthOfFraction; i++)
	{
		if (fraction[i] == '.')
		{
			int sumOfFirstThreeDigits = 0;
			for (int j = i + 1; j <= i + 3; j++)
			{
				sumOfFirstThreeDigits += ConvertCharToInt(fraction[j]);
			}
			printf("the sum of the first three digits after the decimal point: %d\n", sumOfFirstThreeDigits);
		}
	}
	return 0;
}
