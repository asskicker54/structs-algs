#include <stdio.h>

#include "array.h"

#define MAX_N 100


int main() {
    int arrayLength;
    printf("Array length: ");
    scanf("%d", &arrayLength);

    Array arr = NewArray(arrayLength);
    arr.show(&arr);

    destructArray(&arr);

    return 0;
}