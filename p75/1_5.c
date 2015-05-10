#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void compress(char* src, char* dst)
{
  int i;
  int len = strlen(src);
  char c;
  int count = 0;
  int di = 0;
  for (i = 0; i <= len; ++i) {
    if (i == 0) { c = src[i]; }

    if (src[i] != c) {
      dst[di++] = c;
      dst[di++] = '0' + count;
      if (di >= len) {
        goto FAIL;
      }
      count = 0;
      c = src[i];
    }
    count++;
  }
  dst[di] = '\0';
  return;

FAIL:
  for (i = 0; i < len + 1; ++i) {
    dst[i] = src[i];
  }
}

int main(int argc, char const* argv[])
{
  char* s;
  if ( NULL == (s = calloc(1000, sizeof(char))) ) {
    printf("malloc failed\n");
    return(-1);
  }

  char s1[] = "aabcccccaaa";
  compress(s1, s);
  assert(strcmp(s, "a2b1c5a3") == 0);

  char s2[] = "abcdefg";
  compress(s2, s);
  assert(strcmp(s, "abcdefg") == 0);

  char s3[] = "aabbccdd";
  compress(s3, s);
  assert(strcmp(s, "aabbccdd") == 0);

  char s4[] = "aabbccddd";
  compress(s4, s);
  assert(strcmp(s, "a2b2c2d3") == 0);

  char s5[] = "";
  compress(s5, s);
  assert(strcmp(s, "") == 0);

  free(s);
  return 0;
}
