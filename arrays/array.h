#ifndef ARRAY_H
#define ARRAY_H

struct _array;

typedef void (*PRINT)(struct _array*); // PrintArray

typedef struct _array {
    /* array with some useful information */
    /*-----------------------------------*/
    int length;
    int* data;

    /*methods*/
    PRINT show;
    // FIND getMax;
    // FIND getMin;
    // FIND getSum;
    // COUNT countElements;
    // SWAP swap;
    // MANIPULATION append;
    // MANIPULATION popByValue;
    // MANIPULATION popByIdx;

} Array;

void printArray(struct _array*);

static void fillArray(int [], int);

// typedef int (*FIND) (int [], int);
// int findMax(int [], int);
// int findMin(int [], int);
// int findSum(int [], int);

// typedef void(*COUNT) (int[], int);
// void countValues(int [], int);

// typedef void (*SWAP) (int [], int, int, int);
// void swap(int [], int, int, int);

// typedef void (*MANIPULATION) (Array*, int);
// static void append(Array*, int);
// static void popValue(Array*, int);
// static void popIdx(Array*, int);
Array NewArray(int);
void destructArray(struct _array*);

#endif