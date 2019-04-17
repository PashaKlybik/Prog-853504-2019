/*
	Лабиринт. Лабиринт задан массивом a(n, n), в котором элемент a(k,
	m) = 0, если клетка (k, m) «проходима», и a(k, m) = 1, если клетка
	«непроходима» (задается случайным образом). Начальное
	положение путника указывается в проходимой клетке (i, j). Путник
	может перемещаться по проходимым клеткам, имеющим общую
	сторону. Выяснить, может ли путник выйти из лабиринта (т.е.
	попасть в граничную клетку). Если да – распечатать путь. 
*/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
#include <malloc.h>
#pragma warning( disable : 4996)
void fillInt(short int* array, int n, int mod)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			* (array + n * i + j) = (rand() + 39 * 123) % mod;
}
struct Bars
{
	_Bool been;
	_Bool seen;
	short int range;
};

void fillBars(struct Bars* array, int n, int mod)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			(*(array + n * i + j)).been = 0;
			(*(array + n * i + j)).seen = 0;
			(*(array + n * i + j)).range = -1;
		}
}

void showArray(short int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (*(array + n * i + j) != -1)
				printf("%d ", *(array + n * i + j));
			else
				printf("@ ");
		}
		printf("\n");
	}
}
struct Index
{
	int i;
	int j;
};
int length;
void erase0(struct Index* queue)
{
	for (int i = 1; i < length; i++)
	{
		queue[i - 1].i = queue[i].i;
		queue[i - 1].j = queue[i].j;
	}
	length--;
}
void fixPath(struct Bars* checkArray, int n, short int* array, struct Index toBegin, struct Index Begin)
{
	*(array + toBegin.i * n + toBegin.j) = -1;
	for (; (*(checkArray + toBegin.i * n + toBegin.j)).range != 0; *(array + toBegin.i * n + toBegin.j) = -1)
	{
		*(array + toBegin.i * n + toBegin.j) = -1;
		if (toBegin.i < n && toBegin.i > 0 && toBegin.j - 1 > 0 && toBegin.j - 1 < n && (*(checkArray + toBegin.i * n + toBegin.j)).range - (*(checkArray + toBegin.i * n + toBegin.j - 1)).range == 1)
		{
			toBegin.j -= 1;
			continue;
		}
		if (toBegin.i < n && toBegin.i > 0 && toBegin.j + 1 > 0 && toBegin.j + 1 < n && (*(checkArray + toBegin.i * n + toBegin.j)).range - (*(checkArray + toBegin.i * n + toBegin.j + 1)).range == 1)
		{
			toBegin.j += 1;
			continue;
		}
		if (toBegin.i + 1 < n && toBegin.i + 1 > 0 && toBegin.j > 0 && toBegin.j < n && (*(checkArray + toBegin.i * n + toBegin.j)).range - (*(checkArray + (toBegin.i + 1) * n + toBegin.j)).range == 1)
		{
			toBegin.i += 1;
			continue;
		}
		if (toBegin.i - 1 < n && toBegin.i - 1 > 0 && toBegin.j > 0 && toBegin.j < n && (*(checkArray + toBegin.i * n + toBegin.j)).range - (*(checkArray + (toBegin.i - 1) * n + toBegin.j)).range == 1)
		{
			toBegin.i -= 1;
			continue;
		}
	}
	showArray(array, n);

}
bool findPath(short int* array, int n, int i, int j)
{
	struct Bars* checkArray = (struct Bars*)malloc(n * n * sizeof(struct Bars));
	fillBars(checkArray, n, 1);
	struct Index queue[625];
	length = 0;
	int curElem = 0;
	short int  range = 0;
	int buf1 = 1, buf2 = 1, beenElements = 0;
	bool allowed = 1;
	length++;
	queue[0].i = i;
	queue[0].j = j;
	while (length > 0)
	{
		if ((*(checkArray + queue[curElem].i * n + queue[curElem].j)).been == 1)
		{
			erase0(queue);
			continue;
		}
		(*(checkArray + queue[curElem].i * n + queue[curElem].j)).been = 1;
		(*(checkArray + queue[curElem].i * n + queue[curElem].j)).seen = 1;

		beenElements++;

		(*(checkArray + queue[curElem].i * n + queue[curElem].j)).range = range;
		//abs(queue[curElem].i - i) + abs(queue[curElem].j - j);
		if (queue[curElem].i == n - 1 || queue[curElem].i == 0 || queue[curElem].j == n - 1 || queue[curElem].j == 0)
		{
			struct Index exitIndex;
			struct Index Begin;
			Begin.i = i;
			Begin.j = j;
			exitIndex.i = queue[curElem].i;
			exitIndex.j = queue[curElem].j;
			fixPath(checkArray, n, array, exitIndex, Begin);
			return 1;
		}
		if (*(array + queue[curElem].i * n + queue[curElem].j + 1) == 0 && (*(checkArray + queue[curElem].i * n + queue[curElem].j + 1)).seen == 0)
		{
			length++;
			queue[length - 1].i = queue[curElem].i;
			queue[length - 1].j = queue[curElem].j + 1;
			(*(checkArray + queue[length - 1].i * n + queue[length - 1].j)).seen = 1;
			buf1++;
		}
		if (*(array + queue[curElem].i * n + queue[curElem].j - 1) == 0 && (*(checkArray + queue[curElem].i * n + queue[curElem].j - 1)).seen == 0)
		{
			length++;
			queue[length - 1].i = queue[curElem].i;
			queue[length - 1].j = queue[curElem].j - 1;
			(*(checkArray + queue[length - 1].i * n + queue[length - 1].j)).seen = 1;
			buf1++;

		}
		if (*(array + (queue[curElem].i + 1) * n + queue[curElem].j) == 0 && (*(checkArray + (queue[curElem].i + 1) * n + queue[curElem].j)).seen == 0)
		{
			length++;
			queue[length - 1].i = queue[curElem].i + 1;
			queue[length - 1].j = queue[curElem].j;
			(*(checkArray + queue[length - 1].i * n + queue[length - 1].j)).seen = 1;
			buf1++;
		}
		if (*(array + (queue[curElem].i - 1) * n + queue[curElem].j) == 0 && (*(checkArray + (queue[curElem].i - 1) * n + queue[curElem].j)).seen == 0)
		{
			length++;
			queue[length - 1].i = queue[curElem].i - 1;
			queue[length - 1].j = queue[curElem].j;
			(*(checkArray + queue[length - 1].i * n + queue[length - 1].j)).seen = 1;
			buf1++;
		}
		if (buf2 == beenElements)
		{
			allowed = 1;
		}
		if (allowed)
		{
			buf2 = buf1;
			allowed = 0;
			range++;
		}
		erase0(queue);
	}
	free(checkArray);
	return 0;


}
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
begin:
	printf("Поиск выхода из лабиринта.( 0 - клетка проходима, 1 - клетка непроходима).\n");
	printf("Введите размерность n(не меньше 3 и не больше 25) = ");
	int n;
	while (!scanf("%d", &n) || n < 3 || n > 25)
	{
	error:
		while (getchar() != '\n');
		printf("Неверный ввод. Попробуйте ещё раз : ");
	}
	if (getchar() != '\n')
		goto error;
	short int* array = (short int*)malloc(n * n * sizeof(short int));
	fillInt(array, n, 2);
	int i, j;
	showArray(array, n);
	printf("Введите начальное положение через пробел (i,j) :\n");
	while (1)
	{
		printf(" i = ");
		while (!scanf("%d", &i) || i > n || i < 1)
		{
		error2:
			while (getchar() != '\n');
			printf("Неверный ввод. Попробуйте ещё раз : ");
		}
		if (getchar() != '\n')
			goto error2;
		printf(" j = ");
		while (!scanf("%d", &j) || j > n || j < 1)
		{
		error3:
			while (getchar() != '\n');
			printf("Неверный ввод. Попробуйте ещё раз : ");
		}
		if (getchar() != '\n')
			goto error3;
		if ((unsigned short int) * (array + (i - 1) * n + (j - 1)))
		{
			printf("Данная клетка является 1. Выберите другую :\n");
			continue;
		}
		break;
	}
	if (findPath(array, n, i - 1, j - 1) == 1)
		printf("Выход найден\n");
	else
		printf("Выхода нет\n ");
	free(array);
	printf("Ещё раз ? (y) ");
	if (getchar() == 'y')
	{
		while (getchar() != '\n');
		goto begin;
	}
	return 0;
}