#include "list.h"
#include <stdio.h>
#include <stdlib.h>

node_t *NewNode(int data) {
  node_t *newNode = malloc(sizeof(node_t));
  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

list_t *NewList(int data) {
  list_t *list = malloc(sizeof(list_t));
  list->head = NewNode(data);
  list->length = 1;

  return list;
}

void DestructList(list_t *list) {
  node_t *currentNode;
  while (list->head->next) {
    currentNode = list->head->next;
    free(list->head);
    list->head = currentNode;
  }
  free(list->head);
  list->head = NULL;
  currentNode = NULL;

  free(list);
  list = NULL;
}

int IsListEmpty(list_t *list) {
  if (list->length == 0 && list->head == NULL) {
    return 1;
  } else {
    return 0;
  }
}

void AppendNode(list_t *list, int data) {
  node_t *newNode = NewNode(data);
  node_t *currentNode = list->head;
  while (currentNode->next) {
    currentNode = currentNode->next;
  }
  currentNode->next = newNode;
  list->length++;
}

void PrintList(list_t *list) {
  if (IsListEmpty(list)) {
    printf("List is empty\n");
  } else {
    printf("<list_t>[%d]: { ", list->length);
    node_t *currentNode = list->head;
    while (currentNode->next) {
      printf("%d ", currentNode->data);
      currentNode = currentNode->next;
    }
    printf("%d }\n", currentNode->data);
  }
}
