#include <stdio.h>

int findMaximumPowerOfTwoInRange(int rangeStart, int rangeEnd) {
    int maxPowOfTwoInRange = 1;
    while ((maxPowOfTwoInRange * 2 - 1) <= rangeEnd)
        maxPowOfTwoInRange *= 2;
    return maxPowOfTwoInRange;
}

void printBinaryFormOfNumber(int number)
{
    if (number > 1)
        printBinaryFormOfNumber(number / 2);
    printf("%d", number % 2);
}

int main(int argc, const char * argv[]) {
    int rangeStart, rangeEnd;
    printf("Enter range start: ");
    scanf("%d", &rangeStart);
    printf("Enter range end: ");
    scanf("%d", &rangeEnd);
    int numWithMaxNumberOfOnes = rangeEnd <= 3 ? rangeEnd : findMaximumPowerOfTwoInRange(rangeStart, rangeEnd) - 1;
    printf("Number with maximum count of ones in decimal representation: %d\n", numWithMaxNumberOfOnes);
    printf("Number with maximum count of ones in binary representation: ");
    printBinaryFormOfNumber(numWithMaxNumberOfOnes);
    printf("\n");
    return 0;
}
