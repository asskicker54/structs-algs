#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

#define ARRAY_LENGTH 20

void fillArray(int* array);
void printArray(int* array);
void selectionSort(int* array);
int maxIdx(int* array);

int main() {
    int array[ARRAY_LENGTH];
    fillArray(array);
    printArray(array);
    selectionSort(array);
    printArray(array);
}

void fillArray(int* array) {
    for (int i  = 0; i < ARRAY_LENGTH; i++) {
        array[i] = (rand() % 201 - 100);
    }
}

void printArray(int* array) {
    printf("[ ");
    for (int i  = 0; i < ARRAY_LENGTH; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

int maxIdx(int* array) {
    int max = INT_MIN;
    int maxi = -1;
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        if (array[i] > max) {
            max = array[i];
            maxi = i;
        }
    }
    return maxi;
}

void selectionSort(int* array) {
    int sorted[ARRAY_LENGTH];
    int maxi;
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        maxi = maxIdx(array);
        sorted[i] = array[maxi];
        array[maxi] = INT_MIN; 
    }
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        array[i] = sorted[i];
    }
}