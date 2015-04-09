#include <stdio.h>
#include "linked_list.h"

// http://eradman.com/posts/tdd-in-c.html
#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test, succ, fail) do { if(test()) { printf("F"); fail++; } else { printf("."); succ++; } } while(0)

int testInit() {
  LinkedList list;
  linkedListInit(&list);
  _assert(list.head == NULL);
  return 0;
}

int main(int argc, char const* argv[])
{
  int successes = 0, failures = 0;
  _verify(testInit, successes, failures);
  printf("\n%d/%d TESTS PASSED.\n", successes, successes + failures);
  return failures ? 1 : 0;
}
