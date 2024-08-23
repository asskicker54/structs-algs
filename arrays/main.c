#include <stdio.h>

#include "array.h"

#define MAX_N 100


int main() {
    int arrayLength;
    printf("Array length: ");
    scanf("%d", &arrayLength);

    int array[arrayLength];
    fillArray(array, arrayLength);
    printArray(array, arrayLength);

    printf("MAX: %d\n", max(array, arrayLength));
    printf("MIN: %d\n", min(array, arrayLength));

    return 0;
}