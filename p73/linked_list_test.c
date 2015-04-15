#include <stdio.h>
#include "linked_list.h"

// http://eradman.com/posts/tdd-in-c.html
#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test, succ, fail) do { if(test()) { printf("F"); fail++; } else { printf("."); succ++; } } while(0)

int testInit() {
  LinkedList list;
  linkedListInit(&list, INTEGER);
  _assert(list.head == NULL);
  _assert(list.tail == NULL);

  LinkedList doubleList;
  linkedListInit(&doubleList, DOUBLE);
  _assert(doubleList.head == NULL);
  _assert(list.tail == NULL);
  return 0;
}

int testAppend() {
  LinkedList list;
  linkedListInit(&list, INTEGER);
  linkedListAppend(&list, (mixed)1);
  _assert(linkedListIndexOf(&list, (mixed)1) == 0);
  linkedListAppend(&list, (mixed)2);
  _assert(linkedListIndexOf(&list, (mixed)2) == 1);
  return 0;
}

int testInsert() {
  LinkedList list;
  linkedListInit(&list, INTEGER);

  _assert(linkedListInsert(&list, 1, (mixed)1) == 1); // it succeeds
  // 1
  _assert(linkedListIndexOf(&list, (mixed)1) == 0);
  _assert(linkedListInsert(&list, 0, (mixed)2) == 1); // it succeeds
  // 2 -> 1
  _assert(linkedListIndexOf(&list, (mixed)2) == 0);
  _assert(linkedListInsert(&list, 1, (mixed)3) == 1); // it succeeds
  // 2 -> 3 -> 1
  _assert(linkedListIndexOf(&list, (mixed)2) == 0);
  _assert(linkedListIndexOf(&list, (mixed)3) == 1);
  _assert(linkedListIndexOf(&list, (mixed)1) == 2);
  return 0;
}

int main(int argc, char const* argv[])
{
  int successes = 0, failures = 0;
  _verify(testInit, successes, failures);
  _verify(testAppend, successes, failures);
  _verify(testInsert, successes, failures);
  printf("\n%d/%d TESTS PASSED.\n", successes, successes + failures);
  return failures ? 1 : 0;
}
