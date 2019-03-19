#include <stdio.h>

int main()
{
	int detectNumb = 9;
	int const maxNumb = 100;
	int const multipleNumb = 10;

	while (detectNumb < maxNumb)
	{
		detectNumb++;
		int label = 1;
		int sum = detectNumb / 10 + detectNumb % 10;
		int NumbForMultiple = 2;
		while (NumbForMultiple < multipleNumb) //подсчет суммы чисел при умножении на 2,3,4 ...
		{
			int newSum = (NumbForMultiple * detectNumb) / 100 + ((NumbForMultiple * detectNumb) / 10) % 10 + (NumbForMultiple * detectNumb) % 10;

			if (newSum != sum)
			{
				label = 0;
				break;
			}

			NumbForMultiple++;			
		}
		if (label == 1)
		{
			printf("%d\n", detectNumb);
		}		
	}
	system("pause");	
	return 0;
}
