#include "list.h"

int main(void) {
  list_t *list = NewList(10);
  AppendNode(list, 20);
  AppendNode(list, 30);
  PrintList(list);
  DestructList(list);
  return 0;
}
