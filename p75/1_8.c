// I could not come up with the solution...

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int is_substring(const char* s1, const char* s2)
{
  int i, ti;
  char save;
  int len1 = strlen(s1);
  int len2 = strlen(s2);
  if (len1 > len2) {
    return 0;
  }

  char* s;
  if ( NULL == (s = calloc(len2 + 1, sizeof(char))) ) {
    printf("malloc failed\n");
    return(-1);
  }
  strcpy(s, s2);

  int success = 0;
  for (i = 0; i + len1 <= len2; i++) {
    ti = i + len1;
    save = s[ti];
    s[ti] = '\0';
    if (strcmp(s1, s + i) == 0) {
      success = 1;
      break;
    }
    s[ti] = save;
  }

  free(s);
  return success;
}

int is_rotation(const char* s1, const char* s2)
{
  int len1 = strlen(s1);
  int len2 = strlen(s2);
  char* s1s1;

  if (len1 != len2) {
    return 0;
  }

  if ( NULL == (s1s1 = calloc(len1 * 2 + 1, sizeof(char))) ) {
    printf("malloc failed\n");
    return(-1);
  }
  strcpy(s1s1, s1);
  strcpy(s1s1 + len1, s1);

  int success = 0;
  if (is_substring(s2, s1s1)) {
    success = 1;
  }

  free(s1s1);
  return success;
}

int main(int argc, char const* argv[])
{
  char s[] = "Hello";
  assert(is_substring("lo", s) == 1);
  assert(is_substring("He", s) == 1);
  assert(is_substring("ell", s) == 1);
  assert(is_substring("Hello", s) == 1);
  assert(is_substring("loo", s) == 0);
  assert(is_substring("HHe", s) == 0);
  assert(is_substring("HelloHello", s) == 0);

  char ss[] = "waterbottle";
  assert(is_rotation("waterbottle", ss) == 1);
  assert(is_rotation("erbottlewat", ss) == 1);
  assert(is_rotation("waterbottlewaterbottle", ss) == 0);
  assert(is_rotation("", ss) == 0);
  return 0;
}
