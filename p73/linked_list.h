/* Linked list for integers.
 *
 * Usage:
 *   LinkedList list;
 *   linkedListInit(&list);
 *   linkedListAppend(&list, int value);
 *   linkedListInsert(&list, INDEX, int value);
 *   linkedListIndexOf(&list, int value);
 *   linkedListDeleteAtIndex(&list, int value);
 */

#ifndef __LINKED_LIST_H__

typedef enum valueType {
  INTEGER,
  DOUBLE
} valueType;

typedef union mixed {
  int intVal;
  double doubleVal;
} mixed;

typedef struct Node Node;
struct Node {
  Node *prev, *next;
  mixed val;
};

typedef struct LinkedList LinkedList;
struct LinkedList {
  Node* head;
  Node* tail;
};

void printLinkedList(LinkedList *list);

// returns -1 for unsuccessful init
int linkedListInit(LinkedList* list, valueType type);

void linkedListAppend(LinkedList* list, mixed value);

// returns 0 for failure, 1 for success.
int linkedListInsert(LinkedList* list, int index, mixed value);

// returns the first index of the value found, or -1 if the value is not found.
int linkedListIndexOf(LinkedList* list, mixed value);

// returns deleted value.
int linkedListDeleteAtIndex(LinkedList* list, mixed value);

#define __LINKED_LIST_H__
#endif
