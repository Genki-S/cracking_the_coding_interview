#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

static void _swap(char* a, char* b) {
  if (a == b) { return; }
  *a = (*a) ^ (*b);
  *b = (*a) ^ (*b);
  *a = (*a) ^ (*b);
}

static void _quicksort(char* arr, int l, int r) {
  if (!(l < r)) { return; }

  int pivot_i;
  char pivot;
  int lf = l, rf = r - 1; // fingers

  // select random pivot
  pivot_i = rand() % (r - l) + l;
  _swap(&(arr[pivot_i]), &(arr[r]));
  pivot = arr[r];

  while (lf <= rf) {
    if (arr[lf] < pivot) {
      lf++;
    } else {
      _swap(&(arr[lf]), &(arr[rf]));
      rf--;
    }
  }
  _swap(&(arr[lf]), &(arr[r]));

  _quicksort(arr, l, lf - 1);
  _quicksort(arr, lf + 1, r);
}

static void quicksort(char* arr, int size) {
  srand(time(NULL));
  _quicksort(arr, 0, size - 1);
}

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
    _swap(&(arr[rand() % ARR_SIZE]), &(arr[rand() % ARR_SIZE]));
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
