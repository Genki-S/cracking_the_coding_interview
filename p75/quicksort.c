#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "quicksort.h"

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

void quicksort(char* arr, int size) {
  srand(time(NULL));
  _quicksort(arr, 0, size - 1);
}
