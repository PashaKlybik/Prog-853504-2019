#include <stdio.h>
int main()
{
	int k, n, n1 =1, n2 = 1, result;
	int digits = 2;    //счетчик цифр
	printf("input k: ");
	scanf_s("%d", &k);
	if (k<3) {
		printf("digit: 1");
	} else {
	   while (digits < k)
	 {
		n = n1 + n2;//считаем новое число фибоначчи n
		n1 = n2;
		n2 = n;
		for (;n;n/=10)
		{
			digits++; //считаем кол-во цифр в числе n
		}
	 }
		//находим нужную цифру в числе n2
		 for (; digits > k; digits--)
		{
			n2 /= 10;
		}
		result = n2%10;
		printf("digit: %d", result);
	}
	return 0;
}
