#ifndef ARRAY_H
#define ARRAY_H

typedef struct {
    /* array with some useful information */
    /*-----------------------------------*/
    int length;
    int* data;
    int max;
    int min;
    int sum;

    /*methods*/
    PRINT show;
    FIND getMax;
    FIND getMin;
    FIND getSum;
    SWAP swap;
    MANIPULATION append;
    MANIPULATION popByValue;
    MANIPULATION popByIdx;

} Array;

Array NewArray(int);

typedef void (*PRINT) (int [], int);
void printArray(int [], int);

static void fillArray(int [], int);

typedef int (*FIND) (int [], int);
int findMax(int [], int);
int findMin(int [], int);
int findSum(int [], int);

typedef void(*COUNT) (int[], int);
void countValues(int [], int);

typedef void (*SWAP) (int [], int, int, int);
void swap(int [], int, int, int);

typedef int (*MANIPULATION) (Array*, int);
int append(Array*, int);
int popValue(Array*, int);
int popIdx(Array*, int);

#endif