#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void row_col_zerofy(int** matrix, int n, int m) {
  int i, j;
  int* zerorow;
  int* zerocol;
  if ( NULL == (zerorow = calloc(n, sizeof(int))) ) {
    printf("malloc failed\n");
    return;
  }
  if ( NULL == (zerocol = calloc(m, sizeof(int))) ) {
    printf("malloc failed\n");
    return;
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (matrix[i][j] == 0) {
        zerorow[i] = 1;
        zerocol[j] = 1;
      }
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (zerorow[i] || zerocol[j]) {
        matrix[i][j] = 0;
      }
    }
  }

  free(zerorow);
  free(zerocol);
}

int main(int argc, char const* argv[])
{
  int i, j;
  int** matrix;
  if ( NULL == (matrix = calloc(100, sizeof(int*))) ) {
    printf("malloc failed\n");
    return(-1);
  }

  int r1[] = {1, 2, 3, 4, 5};
  int r2[] = {1, 2, 3, 0, 5};
  int r3[] = {1, 2, 3, 4, 5};
  int r4[] = {1, 0, 3, 4, 5};
  int r5[] = {1, 2, 3, 4, 5};
  matrix[0] = r1;
  matrix[1] = r2;
  matrix[2] = r3;
  matrix[3] = r4;
  matrix[4] = r5;

  row_col_zerofy(matrix, 5, 5);

  int ans[5][5] = {
    {1, 0, 3, 0, 5},
    {0, 0, 0, 0, 0},
    {1, 0, 3, 0, 5},
    {0, 0, 0, 0, 0},
    {1, 0, 3, 0, 5}
  };

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      assert(matrix[i][j] == ans[i][j]);
    }
  }

  int rr1[] = {1, 2, 3, 4, 5};
  int rr2[] = {1, 2, 3, 4, 5};
  int rr3[] = {1, 2, 3, 4, 5};
  matrix[0] = rr1;
  matrix[1] = rr2;
  matrix[2] = rr3;

  row_col_zerofy(matrix, 3, 5);

  int ans2[3][5] = {
    {1, 2, 3, 4, 5},
    {1, 2, 3, 4, 5},
    {1, 2, 3, 4, 5},
  };

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      assert(matrix[i][j] == ans2[i][j]);
    }
  }

  free(matrix);
  return 0;
}
