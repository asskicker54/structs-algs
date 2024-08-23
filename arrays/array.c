#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include "array.h"

Array NewArray(int length) {
    int data[length];
    fillArray(data, length);

    int maxV = max(data, length);
    int minV = min(data, length);

    Array array = {
        .length = length,
        .data=data,
        .max=maxV,
        .min=minV,
        .sum=sum(data, length)
    };
}

void printArray(int a[], int length) {
    printf("[ ");
    for (int i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }
    printf("]\n");
}

static void fillArray(int a[], int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        a[i] = rand() % 201 - 100;
    }
}

int max(int a[], int length) {
    int maxValue = -1 * (INT_MAX - 1);
    for (int i = 0; i < length; i++) {
        if (a[i] > maxValue) {
            maxValue = a[i];
        }
    }

    return maxValue;
}

int min(int a[], int length) {
    int minValue = -1 * (INT_MIN + 1);
    for (int i = 0; i < length; i++) {
        if (a[i] < minValue) {
            minValue = a[i];
        }
    }

    return minValue;
}

int sum(int a[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += a[i];
    }

    return sum;
}

void swap(int a[], int length, int x, int y) {

}