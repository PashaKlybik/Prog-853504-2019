#include <stdio.h>
int main()
{
	int k, n, n1 =1, n2 = 1, result;
	int digits = 2;    //счетчик цифр
	printf("k: ");
	scanf_s("%d", &k);
	while (digits < k)
	{
		n = n1 + n2;		//считаем новое число фибоначчи
		n1 = n2;
		n2 = n;
		while (n)
		{
			digits++; //считаем кол-во цифр в числе n
			n/=10;
		}
	}
	if (k >=3) {
		//находим нужную цифру в числе n2
		while (digits > k)
		{
			digits--;
			n2 /= 10;
		}
		result = n2%10;
		printf("digit: %d", result);
	} else {printf("%d", 1); }
	return 0;
}
