#include "list.h"
#include <stdio.h>
#include <stdlib.h>

node_t *NewNode(int data) {
  node_t *newNode = malloc(sizeof(node_t));
  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

void DestructNode(node_t *node) {
  node->next = NULL;
  free(node);
  node = NULL;
}

list_t *NewList(int data) {
  list_t *list = malloc(sizeof(list_t));
  list->head = NewNode(data);
  list->length = 1;

  return list;
}

void DestructList(list_t *list) {
  if (!IsListEmpty(list)) {
    node_t *currentNode;
    while (list->head->next) {
      currentNode = list->head->next;
      DestructNode(list->head);
      list->head = currentNode;
    }
    free(list->head);
    list->head = NULL;
    currentNode = NULL;
  }

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

void DeleteFirst(list_t *list) {
  if (list->length > 0) {
    node_t *newHead = list->head->next;
    DestructNode(list->head);
    list->head = newHead;
    list->length--;
  } else {
    printf("Can not delete element from <list_t> of legth 0\n");
  }
}

void DeleteLast(list_t *list) {
  if (list->length == 1) {
    DeleteFirst(list);
  } else if (list->length >= 2) {
    DeleteListElement(list, (list->length - 1));
  } else {
    printf("Can not delete element from <list_t> of length 0\n");
  }
}

void DeleteListElement(list_t *list, int idx) {
  if (list->length == 0) {
    printf("Can not delete element from <list_t> of length 0\n");
  } else if (list->length <= idx) {
    printf("Can not delete element from <list_t>: index is out of range\n");
  } else if (idx == 0) {
    DeleteFirst(list);
  } else {
    int count = 0;
    node_t *currentNode = list->head;
    while (count != (idx - 1)) {
      currentNode = currentNode->next;
      count++;
    }
    node_t *nodeToDelete = currentNode->next;
    currentNode->next = nodeToDelete->next;
    DestructNode(nodeToDelete);
    list->length--;
  }
}
