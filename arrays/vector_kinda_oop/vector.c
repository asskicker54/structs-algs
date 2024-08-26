#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <limits.h>

#include "vector.h"

vector_t* NewVector(int length) {
    vector_t* vector = malloc(sizeof(vector_t)); // creates a dynamic vector variable
    vector->m_data = malloc(length * sizeof(int)); // creates a dynamic array for vector data
    vector->m_length = length;
    vector->print = printVector;
    vector->getLen = getLength;
    vector->max = findMax;
    vector->min = findMin;
    generateData(vector);

    return vector;
}

void DestructVector(vector_t* vector) {
    free(vector->m_data);
    vector->m_data = NULL;

    free(vector);
    vector = NULL;
}

static void generateData(vector_t* vector) {
    srand(time(NULL));
    for (int i = 0; i < vector->m_length; i++) {
        vector->m_data[i] = (rand() % 201 - 100);
    }
}

void printVector(vector_t* this) {
    printf("[ ");
    for (int i = 0; i < this->m_length; i++) {
        printf("%d ", this->m_data[i]);
    }
    printf("]\n");
}

int getLength(vector_t* this) {
    return this->m_length;
}

int findMax(vector_t* this) {
    int maxVal = INT_MIN;
    for (int i = 0; i < this->m_length; i++) {
        if (this->m_data[i] > maxVal) {
            maxVal = this->m_data[i];
        }
    }
    return maxVal;
}

int findMin(vector_t* this) {
    int minVal = INT_MAX;
        for (int i = 0; i < this->m_length; i++) {
            if (this->m_data[i] < minVal) {
                minVal = this->m_data[i];
            }
        }
        return minVal;
}
