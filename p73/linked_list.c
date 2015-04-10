#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "linked_list.h"

static char gType[8];

int linkedListInit(LinkedList* list, char* type) {
  assert(
      strcmp(type, "int") == 0 ||
      strcmp(type, "double") == 0
      );
  strcpy(gType, type);

  list->head = NULL;
}
