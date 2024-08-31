#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    struct Node {
        int data;
        Node* previous;
    };
    Node* top;
    int length;
}stack_t;

stack_t* NewStack(int data);
void DestructStack(stack_t* stack);

int stackPush(stack_t* stack, int data);
int stackPop(stack_t* stack, int& data);

void getStackInfo(stack_t* stack);

#endif