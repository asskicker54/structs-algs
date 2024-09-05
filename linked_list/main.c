#include "list.h"

int main(void) {
  list_t *list = NewList(10);
  PrintList(list);
  AppendNode(list, 20);
  AppendNode(list, 30);
  PrintList(list);
  DeleteListElement(list, 1);
  AppendNode(list, 52);
  PrintList(list);
  DestructList(list);
  return 0;
}
