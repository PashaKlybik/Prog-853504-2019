#include <stdio.h>
#define MAX 100000

long MinElement(long *array,  int amountOfElements)
{
    int i;
    long minimalElement = array[0];
    for (i = 0; i < amountOfElements; i++)
    {
        if (array[i] < minimalElement)
        {
            minimalElement = array[i];
        }
    }
    return minimalElement;
}

void Conversions(long numberOfConversions, int amountOfElements, long *array, long minimalElement)
{
    int i;
    if (numberOfConversions == 0)
        return;
    
    for (i = 0; i < amountOfElements; i++)
        array[i] = minimalElement - array[i];
    
    if (numberOfConversions  % 2 == 0)
    {
        minimalElement = MinElement(array, amountOfElements);
        for (i = 0; i < amountOfElements; i++)
        {
            array[i] = minimalElement - array[i];
        }
    }
}

int main()
{
    int amountOfElements;
    long minimalElement;
    long  i, arrayA[MAX],numberOfConversions;
    printf("input amount of elements:");
    scanf("%d", &amountOfElements);
    printf("input array:");
    for (i = 0; i < amountOfElements; i++)
        scanf("%li", &arrayA[i]);
    printf("input number of conversions:");
    scanf("%li", &numberOfConversions);
    if (numberOfConversions < 0)
    {
        printf("Error");
        return 0;
    }
    minimalElement = MinElement(arrayA, amountOfElements);
    Conversions(numberOfConversions, amountOfElements, arrayA, minimalElement);
    for (i = 0; i < amountOfElements; i++)
        printf("%li ", arrayA[i]);
}


