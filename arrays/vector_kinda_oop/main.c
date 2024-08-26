#include <stdio.h>

#include "vector.h"

int main() {
    vector_t* vector = NewVector(10);
    //
    DestructVector(vector);
    return 0;
}