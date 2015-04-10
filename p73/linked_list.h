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
};

// returns -1 for unsuccessful init
int linkedListInit(LinkedList* list, char* type);

void linkedListAppend(LinkedList* list, int value);

// returns 0 for failure, 1 for success.
int linkedListInsert(LinkedList* list, int index, int value);

// returns -1 if the value was not found.
int linkedListIndexOf(LinkedList* list, int value);

// returns deleted value.
int linkedListDeleteAtIndex(LinkedList* list, int value);

#define __LINKED_LIST_H__
#endif
