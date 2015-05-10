#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void replace_spaces(char* str, int len)
{
  int memsize = strlen(str) + 1;
  char* tmp_s;
  if ( NULL == (tmp_s = calloc(memsize, sizeof(char))) ) {
    printf("malloc failed\n");
    assert(0);
  }

  int s = 0;
  for (int i = 0; i < len; ++i) {
    if (str[i] == ' ') {
      tmp_s[s++] = '%';
      tmp_s[s++] = '2';
      tmp_s[s++] = '0';
    } else {
      tmp_s[s++] = str[i];
    }
  }
  assert(s == memsize - 1);
  tmp_s[s] = '\0';

  for (int i = 0; i < memsize; ++i) {
    str[i] = tmp_s[i];
  }

  free(tmp_s);
}

int main(int argc, char const* argv[])
{
  char s1[] = "Mr John Smith    ";
  char s2[] = "NoSpaceAtAll";
  char s3[] = "   Spaces before string          ";
  replace_spaces(s1, 13);
  replace_spaces(s2, 12);
  replace_spaces(s3, 23);
  assert(strcmp(s1, "Mr%20John%20Smith") == 0);
  assert(strcmp(s2, "NoSpaceAtAll") == 0);
  assert(strcmp(s3, "%20%20%20Spaces%20before%20string") == 0);
  return 0;
}
