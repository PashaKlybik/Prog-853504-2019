/*
	ex_4.1(11)
	Отцентрировать (т.е. обеспечить осевую симметрию текста на
	экране добавлением пробелов слева) вводимый с клавиатуры текст.
	Первый символ помещается в 40-ю позицию; второй – в 41-ю;
	появление третьего и каждого последующего нечетного символа
	вызывает удаление одного пробела слева. Так продолжается до
	конца строки; ввод следующих строк – аналогично.
*/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
void moveByOne(char* Text, unsigned short int strNum, unsigned short int indexBeg, unsigned short int indexEnd)
{
	for (int i = indexBeg; i < indexEnd; i++)
	{
		*(Text + strNum * 92 + i) = *(Text + strNum * 92 + i + 1);
	}
	*(Text + strNum * 92 + indexEnd) = ' ';
}

void fillSpace(char* Text)
{
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 92; j++)
			* (Text + i * 92 + j) = ' ';
}

int main()
{
	setlocale(LC_ALL, "Russian");
	printf("Вводите строки ( не более 90 символов).\n");
	char* Text = (char*)malloc(20 * 92 * sizeof(char));
	fillSpace(Text);
	unsigned short int countIn = 0;
	unsigned short int pos = 44;
	unsigned short int border = 44;
	char buf, checkContinue;
	unsigned short int strNum = 0;
	do
	{
		countIn = 0;
		pos = 44;
		border = 44;
		while (countIn < 90 && '\n' != (buf = getchar()))
		{
			*(Text + strNum * 92 + pos) = buf;
			countIn++;
			if (countIn % 2 == 1)
			{
				border--;
				moveByOne(Text, strNum, border, pos);
			}
			else
				pos++;
		}
		if (countIn == 90)
			while (getchar() != '\n');
		strNum++;
		if (strNum < 20)
		{
			printf("Продолжить ввод? (y)  -  ");
			scanf_s("%c", &checkContinue);
			while (getchar() != '\n');
		}
		else
			break;

	} while (checkContinue == 'y');
	for (int i = 0; i <= strNum; i++)
	{
		for (int j = 0; j < 90; j++)
			printf("%c", *(Text + i * 92 + j));
		printf("\n");
	}
	free(Text);
	return 0;
}