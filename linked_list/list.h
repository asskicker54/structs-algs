#pragma once

typedef struct Node {
  int data;
  struct Node *next;
} node_t;

typedef struct LinkedList {
  node_t *head;
  int length;
} list_t;

node_t *NewNode(int data);

list_t *NewList(int data);
void DestructList(list_t *list);

int IsListEmpty(list_t *list);
void AppendNode(list_t *list, int data);

void PrintList(list_t *list);
