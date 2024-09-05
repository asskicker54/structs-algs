#include "list.h"

int main(void) {
  list_t *list = NewList(10);
  PrintList(list);
  DeleteFirst(list);
  PrintList(list);
  AppendNode(list, 52);
  PrintList(list);
  DestructList(list);
  return 0;
}
