//Сжать строку из латинских букв алгоритмом RLE и вывести результат
#include <stdio.h>

int main()
{
        char line[1000000];
        int i, number;
        printf("Vvedite stroky: ");
        scanf("%s", line);
        for (i = 0; line[i] != '\0'; i++)
        {
                if (line[i] == line[i + 1])
                {
                        number++;
                }
                else
                {
                        if (number > 1)
                        {
                                printf("%d%c", number + 1, line[i]);
                                number = 0;
                                continue;
                        }
                        if (number == 1)
                        {
                                printf("%c%c", line[i], line[i]);
                        }
                        else
                        {
                                printf("%c", line[i]);
                        }
                        number = 0;
                }
        }
    printf("\n");
    return 0;
}
