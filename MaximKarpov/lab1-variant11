#include <stdio.h>


int getInteger()
{
    int number;
    char c;
    while (1)
    {
        if (!scanf("%d", &number) || getchar() != '\n')
        {
            while ((c = getchar()) != '\n' && c != EOF);
        }
        else return number;
        
        printf("Необходимо ввести число.\nПовторите ввод: ");
    }
}

int getLength (int newNum){
    int length = 0;
    while(newNum){
        newNum = newNum / 10;
        length ++;
    }
    return length;
}

int theNthDigit(int square, int n){
    int digit=0;
    while(n){
        digit = square % 10;
        square /= 10;
        n--;
    }
    return digit;
}

int main(int argc, const char * argv[]) {
    int numberInSequence = 0;
    while(numberInSequence <= 0){
        printf("Введите номер цифры в последовательности (n >= 0): ");
        numberInSequence = getInteger();
    }
    int rezerv = 0;
    int sqnum = 1;
    int squareValue = 0;
    for (; rezerv < numberInSequence; sqnum++){
        squareValue = sqnum * sqnum;
        rezerv = rezerv + getLength(squareValue);
    }
    int numberInSquare = rezerv - numberInSequence + 1;
    printf("%dя цифра в последовательности это: %d\n", numberInSequence, theNthDigit(squareValue, numberInSquare));
    return 0;
}
