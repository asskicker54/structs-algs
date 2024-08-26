#ifndef VECTOR_H
#define VECTOR_H

typedef void (*Method_t)(void*);
typedef int (*MethodGet_t)(void*);
typedef void (*MethodChange_t)(void*, int, int);
typedef void (*MethodAddDelete_t)(void*, int);
typedef int (*MethodFind_t)(void*, int);

// TODO: copy method

typedef struct Vector{
    int* m_data;
    int m_length;

    Method_t print;
    MethodGet_t getLen;
    MethodGet_t max;
    MethodGet_t min;
    MethodChange_t swap;
    MethodAddDelete_t append;
    MethodChange_t push;
    MethodFind_t getIdxByValue;
    MethodAddDelete_t popByIdx;
    MethodAddDelete_t popByValue;
}vector_t;

vector_t* NewVector(int);
void DestructVector(vector_t*);

static void generateData(vector_t*);

void printVector(vector_t*);

int getLength(vector_t*);

int findMax(vector_t*);
int findMin(vector_t*);

void doSwap(vector_t*, int, int);

void doAppend(vector_t*, int);

void doPush(vector_t*, int, int);

int findIdx(vector_t*, int);

void doPopByValue(vector_t*, int);
void doPopByIdx(vector_t*, int);

#endif