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
    vector->swap = doSwap;
    vector->append = doAppend; 
    generateData(vector);

    return vector;
}

void DestructVector(vector_t* vector) {
    free(vector->m_data);
    // vector->m_data = NULL;

    free(vector);
    // vector = NULL;
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

void doSwap(vector_t* this, int idx1, int idx2) {
    if ((idx1 >= 0 && idx2 >= 0) && (idx1 <= this->m_length - 1 && idx2 <= this->m_length - 1)) {
        int temp;
        temp = this->m_data[idx1];
        this->m_data[idx1] = this->m_data[idx2];
        this->m_data[idx2] = temp;
    } else {
        printf("Failed to swap elements: index is not valid!\n");
    }
}

void doAppend(vector_t* this, int newValue) {
    this->m_data = realloc(this->m_data,  ((this->m_length + 1) * sizeof(int)));
    this->m_data[this->m_length] = newValue;
    this->m_length += 1;
}

