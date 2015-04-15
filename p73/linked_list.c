#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"

/****************************************
 * Private functions
****************************************/

static int _isEqualAsType(mixed a, mixed b, _valueType type) {
  switch (type) {
    case INTEGER:
      return a.intValue == b.intValue;
      break;
    case DOUBLE:
      return a.doubleValue == b.doubleValue;
      break;
    default:
      return -1;
  }
}

static void _printNodeValue(Node* n, _valueType type) {
  switch (type) {
    case INTEGER:
      printf("%d", n->value.intValue);
      break;
    case DOUBLE:
      printf("%lf", n->value.doubleValue);
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
    _printNodeValue(p, list->valueType);
    printf(" --> ");
    p = p->next;
  }
  printf("\n");
}

int linkedListInit(LinkedList* list, _valueType type) {
  assert(
      type == INTEGER ||
      type == DOUBLE
      );
  list->valueType = type;

  list->head = NULL;
  list->tail = NULL;
  return 0;
}

void linkedListAppend(LinkedList* list, mixed value) {
  Node* n = (Node*)malloc(sizeof(Node));
  n->prev = list->tail;
  n->next = NULL;
  n->value = value;

  if (list->head == NULL) {
    list->head = n;
    list->tail = n;
  } else {
    list->tail->next = n;
    list->tail = n;
  }
}

int linkedListInsert(LinkedList* list, int index, mixed value) {
  assert(index >= 0);
  Node* p = list->head;
  int i = 0;
  while (p != NULL && i != index) {
    p = p->next;
    ++i;
  }
  if (p == NULL) {
    linkedListAppend(list, value);
    return 1;
  }
  Node* n = (Node*)malloc(sizeof(Node));
  n->value = value;
  n->prev = p->prev;
  n->next = p;
  p->prev = n;
  if (n->prev != NULL) {
    n->prev->next = n;
  } else {
    list->head = n;
  }
  return 1;
}

int linkedListIndexOf(LinkedList* list, mixed value) {
  Node* p = list->head;
  int i = 0;
  while (p != NULL) {
    if (_isEqualAsType(p->value, value, list->valueType)) {
      return i;
    }
    p = p->next;
    ++i;
  }
  return -1;
}
