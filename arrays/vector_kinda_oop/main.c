#include <stdio.h>

#include "vector.h"

int main() {
    vector_t* vector = NewVector(10);
    vector->print(vector);
    vector->swap(vector, 9, 0);
    vector->print(vector);
    DestructVector(vector);
    return 0;
}