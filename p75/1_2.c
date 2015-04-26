#include <stdio.h>
#include <string.h>
#include <assert.h>

static void _swap(char* a, char* b) {
  if (a == b) { return; }
  *a = (*a) ^ (*b);
  *b = (*a) ^ (*b);
  *a = (*a) ^ (*b);
}

static void reverse(char* str) {
  int len = strlen(str);
  int i, j;
  for (i = 0, j = len - 1; i < j; i++, j--) {
    _swap(&(str[i]), &(str[j]));
  }
}

int main(int argc, char const* argv[])
{
  // http://stackoverflow.com/questions/4129188/bus-error-when-trying-to-access-character-on-a-string-in-c
  char s1[] = "reverseme";
  reverse(s1);
  assert(strcmp(s1, "emesrever") == 0);
  char s2[] = "";
  reverse(s2);
  assert(strcmp(s2, "") == 0);
  char s3[] = "a";
  reverse(s3);
  assert(strcmp(s3, "a") == 0);
  return 0;
}
