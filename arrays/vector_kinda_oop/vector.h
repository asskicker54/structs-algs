#ifndef VECTOR_H
#define VECTOR_H

typedef void (*Method_t)(void*);
typedef int (*MethodGet_t)(void*);
typedef void (*MethodSwap_t)(void*, int, int);
typedef void (*MethodChange_t)(void*, int);

typedef struct Vector{
    int* m_data;
    int m_length;

    Method_t print;
    MethodGet_t getLen;
    MethodGet_t max;
    MethodGet_t min;
    MethodSwap_t swap;
}vector_t;

vector_t* NewVector(int);
void DestructVector(vector_t*);

static void generateData(vector_t*);

void printVector(vector_t*);

int getLength(vector_t*);

int findMax(vector_t*);
int findMin(vector_t*);

void doSwap(vector_t*, int, int);

#endif