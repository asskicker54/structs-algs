#include <stdio.h>

#include "vector.h"

int main() {
    vector_t* vector = NewVector(10);
    vector->print(vector);
    vector->push(vector, 111, 11);
    vector->print(vector);
    DestructVector(vector);
    return 0;
}