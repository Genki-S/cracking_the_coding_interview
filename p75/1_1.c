#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "quicksort.h"

static int is_unique(char* str) {
  int i;
  int len = strlen(str);
  char* copy = malloc(sizeof(char) * len);
  strcpy(copy, str);
  quicksort(copy, len);
  for (i = 1; copy[i] != '\0'; i++) {
    if (copy[i] == copy[i-1]) {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char const* argv[])
{
#define ARR_SIZE (100)
  int i;
  char arr[ARR_SIZE];
  srand(time(NULL));
  for (i = 0; i < ARR_SIZE; i++) {
    arr[i] = i;
  }
  for (i = 0; i < 1000; i++) {
    int ti = rand() % ARR_SIZE, tj = rand() % ARR_SIZE;
    char tmp = arr[ti];
    arr[ti] = arr[tj];
    arr[tj] = tmp;
  }

  quicksort(arr, sizeof(arr) / sizeof(arr[0]));

  for (i = 0; i < ARR_SIZE; ++i) {
    assert(arr[i] == i);
  }

  char* s1 = "crackingthecodinginterview";
  assert(is_unique(s1) == 0);
  char* s2 = "uniqstr";
  assert(is_unique(s2) == 1);
  char* s3 = "";
  assert(is_unique(s3) == 1);
  return 0;
}
