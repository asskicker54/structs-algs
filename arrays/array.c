#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stddef.h>

#include "array.h"

void printArray(struct _array* this) {
    printf("[ ");
    for (int i = 0; i < this->length; i++) {
        printf("%d ", this->data[i]);
    }
    printf("]\n");
}

static void fillArray(int a[], int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        a[i] = rand() % 201 - 100;
    }
}

// int findMax(int a[], int length) {
//     int maxValue = -1 * (INT_MAX - 1);
//     for (int i = 0; i < length; i++) {
//         if (a[i] > maxValue) {
//             maxValue = a[i];
//         }
//     }

//     return maxValue;
// }

// int findMin(int a[], int length) {
//     int minValue = -1 * (INT_MIN + 1);
//     for (int i = 0; i < length; i++) {
//         if (a[i] < minValue) {
//             minValue = a[i];
//         }
//     }

//     return minValue;
// }

// int findSum(int a[], int length) {
//     int sum = 0;
//     for (int i = 0; i < length; i++) {
//         sum += a[i];
//     }

//     return sum;
// }

// void countValues(int a[], int length) {
//     // TODO: realize countValue function
// }

// void swap(int a[], int length, int x, int y) {
//     // TODO: realize swap function
// }

// static void append(Array* arr, int x) {
//     // TODO: relize append method
//     int newData [arr->length + 1];
//     for (int i = 0; i < arr->length; i++) {
//         newData[i] = arr->data[i];
//     }
//     newData[arr->length] = x;
//     arr->data = newData;

// }

// static void popValue(Array* arr, int x) {
//     // TODO: realize popValue function
// }

// static void popIdx(Array* arr, int idx) {
//     // TODO: realize popIdx function
// }

Array NewArray(int length) {
    int* data = malloc(length * sizeof(int));
    fillArray(data, length);

    Array arr = {
        .length = length,
        .data=data,
        .show=printArray,
        // .getMax=findMax,
        // .getMin=findMin,
        // .getSum=findSum,
        // .countElements=countValues,
        // .swap=swap,
        // .append=append,
        // .popByValue=popValue,
        // .popByIdx=popIdx
    };

    return arr;
}

void destructArray(struct _array* array) {
    free(array->data);
    array->data = NULL;
}