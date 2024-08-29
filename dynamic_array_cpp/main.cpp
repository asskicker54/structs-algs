#include <iostream>

typedef struct Vector {
    int* data;
    int length;
} vector_t;

vector_t* NewVector(int length) {
    vector_t* vector = new vector_t;
    vector->data = new int[length];
    vector->length = length;

    for (int i{0}; i < vector->length; i++) {
        vector->data[i] = i;
    }

    return vector;
}

void DestructVector(vector_t* vector) {
    delete [] vector->data;
    vector->data = nullptr;
    delete vector;
    vector = nullptr;
}

void printVector(vector_t* vector) {
    std::cout << "[ ";
    for (int i{0}; i < vector->length; i++) {
        std::cout << vector->data[i] << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    vector_t* vector = NewVector(10);
    printVector(vector);
    DestructVector(vector);
}