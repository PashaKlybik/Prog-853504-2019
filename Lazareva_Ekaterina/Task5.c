//По заданным координатам мада, и описанию поливалки, подсчитать и вывести, скольким деревьям в саду не достается воды.
#include <stdio.h>
#include <math.h>

int min (int, int);
int max (int, int);

int main()
{
	int X1, Y1, X2, Y2, Px, Py, Pr, result, S;
	printf ("Vvedite X1, Y1, X2, Y2\n");
	scanf ("%d%d%d%d", &X1, &Y1, &X2, &Y2);
	printf ("Vvedite Px, Py, Pr\n");
	scanf ("%d%d%d", &Px, &Py, &Pr);
	X1 -= Px;
	Y1 -= Py;
	X2 -= Px;
	Y2 -= Py;
	S = pow(Pr, 2);
	result = (X2 - X1 + 1) * (Y2 - Y1 + 1);
	for (int i = max(X1, -Pr); i<= min(X2, Pr); i++)
	{
		int j = sqrt(S - i * i);
		result -= min(j, Y2) - max(-j, Y1) +1;
	}
	printf("%d\n", result);
}

int min(int x, int y)
{
	return (x < y) ? x : y;
}

int max(int x, int y)
{
	return (x > y) ? x : y;
}
