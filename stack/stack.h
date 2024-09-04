#ifndef STACK_H
#define STACK_H

typedef struct Node {
  // FIX: create own type for data field
  int data;
  struct Node *previous;
} stackNode_t;

typedef struct Stack {
  stackNode_t *topNode;
  int length;
} stack_t;

stack_t *NewStack(int data);
void DestructStack(stack_t *stack);

#endif
