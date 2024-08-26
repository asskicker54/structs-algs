#include <stdio.h>

#include "vector.h"

int main() {
    printf("Vector length: ");
    int length;
    scanf("%d", &length);
    printf("\n");
    vector_t* vector = NewVector(length);
    vector->print(vector);
    printf("Max: %d\n", vector->max(vector));
    printf("Min: %d\n", vector->min(vector));
    DestructVector(vector);
}