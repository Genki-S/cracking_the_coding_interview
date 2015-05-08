#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// If string consists of only ascii: O(N)
// Use the answer of 1.1 (p.172) and check if occurances count matches

// Else: O(NlogN)
// Sort, then compair

// Try first approach because I wrote sorting in problem 1.2

static const int MAX_CHAR_KIND = 256;

static int is_permutation(char* a, char* b) {
  int i;
  int* counters;
  int len_a = strlen(a), len_b = strlen(b);

  if ( NULL == (counters = calloc(MAX_CHAR_KIND, sizeof(int))) ) {
    printf("malloc failed\n");
    return(-1);
  }

  if (len_a != len_b) {
    return 0;
  }
  for (i = 0; i < len_a; i++) {
    counters[a[i] - 'a']++;
  }
  for (i = 0; i < len_b; i++) {
    counters[b[i] - 'a']--;
  }
  for (i = 0; i < MAX_CHAR_KIND; i++) {
    if (counters[i] != 0) {
      return 0;
    }
  }

  free(counters);
  return 1;
}

int main(int argc, char const* argv[])
{
  char s[] = "HelloWorld";
  char n1[] = "foobar";
  char n2[] = "HelloWorlp";
  char n3[] = "";
  char o1[] = "edlHWollor";
  char o2[] = "oWoerlldHl";
  char o3[] = "HlroodleWl";
  assert(is_permutation(s, n1) == 0);
  assert(is_permutation(s, n2) == 0);
  assert(is_permutation(s, n3) == 0);
  assert(is_permutation(s, o1) == 1);
  assert(is_permutation(s, o2) == 1);
  assert(is_permutation(s, o3) == 1);
  return 0;
}
