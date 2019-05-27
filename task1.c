

#include <stdio.h>
#include <math.h>

int isDividerHappy (long long divider)
{
    while (divider != 0)
        if (divider % 10 == 4 || divider % 10 == 7)
            return 1;
        else divider /= 10;
    return 0;
}

int main()
{
    long long number,firstDivider, secondDivider;
    int rootOfNumber, currentNumber, countOfHappyDividers = 0;
    printf("Input number:");
    scanf("%lli", &number);
    rootOfNumber = sqrt(number); //корень числа
    for (currentNumber = 1; currentNumber <= rootOfNumber; currentNumber++)
    {
        if (!(number % currentNumber))
        {
            firstDivider = currentNumber;
            secondDivider = number / currentNumber;
            if (isDividerHappy(firstDivider)) countOfHappyDividers++;
            if (isDividerHappy(secondDivider)) countOfHappyDividers++;
        }
    }
    printf("%d\n", countOfHappyDividers);
    return 0;
}
