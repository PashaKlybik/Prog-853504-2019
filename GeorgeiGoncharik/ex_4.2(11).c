/*
	ex_4.2(11)
	Текстовый файл содержит текст произвольной длины. Построить
	вертикальную гистограмму числа вхождений в текст каждой
	строчной латинской буквы.
*/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#pragma warning (disable : 4996)
struct Pair
{
	char symbol;
	unsigned int num;
};

void initialize(struct Pair* array)
{
	for (int i = 97, index = 0; i <= 122; i++, index++)
	{
		(*(array + index)).symbol = (char)i;
		(*(array + index)).num = 0;
	}
}

int main()
{
	char getFile[100];
	setlocale(LC_ALL, "Russian");
	printf("Введите путь файла : ");
	scanf_s("%s", getFile);
	getchar();
	FILE* myFile = fopen((getFile), "r");
	while (!myFile)
	{
		printf("Данного файла не существует. Введите ещё раз : ");
		scanf_s("%s", getFile);
		getchar();
		myFile = fopen(getFile, "r");
	}
	struct Pair* alphas = (struct Pair*)malloc(26 * sizeof(struct Pair));
	initialize(alphas);
	while (!feof(myFile))
	{
		switch (getc(myFile))
		{
		case 'a': alphas[0].num++;     break;
		case 'b': alphas[1].num++;     break;
		case 'c': alphas[2].num++;     break;
		case 'd': alphas[3].num++;     break;
		case 'e': alphas[4].num++;     break;
		case 'f': alphas[5].num++;     break;
		case 'g': alphas[6].num++;     break;
		case 'h': alphas[7].num++;     break;
		case 'i': alphas[8].num++;     break;
		case 'j': alphas[9].num++;     break;
		case 'k': alphas[10].num++;    break;
		case 'l': alphas[11].num++;    break;
		case 'm': alphas[12].num++;    break;
		case 'n': alphas[13].num++;    break;
		case 'o': alphas[14].num++;    break;
		case 'p': alphas[15].num++;    break;
		case 'q': alphas[16].num++;    break;
		case 'r': alphas[17].num++;    break;
		case 's': alphas[18].num++;    break;
		case 't': alphas[19].num++;    break;
		case 'u': alphas[20].num++;    break;
		case 'v': alphas[21].num++;    break;
		case 'w': alphas[22].num++;    break;
		case 'x': alphas[23].num++;    break;
		case 'y': alphas[24].num++;    break;
		case 'z': alphas[25].num++;    break;
		default:                       break;

		}
	}
	for (int i = 0; i < 26; i++)
		printf("%c  -  %d\n", alphas[i].symbol, alphas[i].num);
	free(alphas);
	return 0;
}