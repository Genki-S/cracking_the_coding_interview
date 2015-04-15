#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"

static valueType gType;

/****************************************
 * Private functions
****************************************/

static int _isEqual(mixed a, mixed b) {
  switch (gType) {
    case INTEGER:
      return a.intVal == b.intVal;
      break;
    case DOUBLE:
      return a.doubleVal == b.doubleVal;
      break;
    default:
      return -1;
  }
}

static void _printNodeValue(Node* n) {
  switch (gType) {
    case INTEGER:
      printf("%d", n->val.intVal);
      break;
    case DOUBLE:
      printf("%lf", n->val.doubleVal);
      break;
    default:
      break;
  }
}

/****************************************
 * APIs
****************************************/

void printLinkedList(LinkedList *list) {
  Node* p = list->head;
  while (p != NULL) {
    _printNodeValue(p);
    printf(" --> ");
    p = p->next;
  }
  printf("\n");
}

int linkedListInit(LinkedList* list, valueType type) {
  assert(
      type == INTEGER ||
      type == DOUBLE
      );
  gType = type;

  list->head = NULL;
  list->tail = NULL;
  return 0;
}

void linkedListAppend(LinkedList* list, mixed value) {
  Node* n = (Node*)malloc(sizeof(Node));
  n->prev = list->tail;
  n->next = NULL;
  n->val = value;

  if (list->head == NULL) {
    list->head = n;
    list->tail = n;
  } else {
    list->tail->next = n;
    list->tail = n;
  }
}

int linkedListIndexOf(LinkedList* list, mixed value) {
  Node* p = list->head;
  int i = 0;
  while (p != NULL) {
    if (_isEqual(p->val, value)) {
      return i;
    }
    p = p->next;
    ++i;
  }
  return -1;
}
