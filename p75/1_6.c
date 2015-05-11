#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void print_matrix(int** matrix, int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d\t", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void rotate(int** matrix, int n) {
  /* print_matrix(matrix, n); */
  int i, j, k;
  int ti, tj, prev, current;
  int xs[5], ys[5];
  for (i = 0; i <= n / 2; i++) {
    for (j = i; j < n - i - 1; j++) {
      ys[0] = i ; ys[1] = j         ; ys[2] = n - i - 1 ; ys[3] = n - j - 1 ; ys[4] = i ;
      xs[0] = j ; xs[1] = n - i - 1 ; xs[2] = n - j - 1 ; xs[3] = i         ; xs[4] = j ;
      prev = 0; // dummy value
      for (k = 0; k < 5; k++) { // NOTE: 5 times to bring value of 4th to 1st
        ti = ys[k]; tj = xs[k];
        current = matrix[ti][tj];
        matrix[ti][tj] = prev;
        prev = current;
      }
    }
  }
  /* print_matrix(matrix, n); */
}

void check(int** matrix, int** ans, int n) {
  int i, j;
  rotate(matrix, n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      assert(matrix[i][j] == ans[i][j]);
    }
  }
}

int main(int argc, char const* argv[])
{
  int** ans;
  if ( NULL == (ans = calloc(5, sizeof(int*))) ) {
    printf("malloc failed\n");
    return(-1);
  }
  int** mat;
  if ( NULL == (mat = calloc(5, sizeof(int*))) ) {
    printf("malloc failed\n");
    return(-1);
  }

  // 5x5 matrix
  int m1r1[] = { 1, 2, 3, 4, 5 };
  int m1r2[] = { 1, 2, 3, 4, 5 };
  int m1r3[] = { 1, 2, 3, 4, 5 };
  int m1r4[] = { 1, 2, 3, 4, 5 };
  int m1r5[] = { 1, 2, 3, 4, 5 };
  mat[0] = m1r1;
  mat[1] = m1r2;
  mat[2] = m1r3;
  mat[3] = m1r4;
  mat[4] = m1r5;

  int a1r1[] = { 1, 1, 1, 1, 1 };
  int a1r2[] = { 2, 2, 2, 2, 2 };
  int a1r3[] = { 3, 3, 3, 3, 3 };
  int a1r4[] = { 4, 4, 4, 4, 4 };
  int a1r5[] = { 5, 5, 5, 5, 5 };
  ans[0] = a1r1;
  ans[1] = a1r2;
  ans[2] = a1r3;
  ans[3] = a1r4;
  ans[4] = a1r5;

  check(mat, ans, 5);

  // 4x4 matrix (try even)
  int m2r1[] = { 1, 2, 3, 4 };
  int m2r2[] = { 1, 2, 3, 4 };
  int m2r3[] = { 1, 2, 3, 4 };
  int m2r4[] = { 1, 2, 3, 4 };
  mat[0] = m2r1;
  mat[1] = m2r2;
  mat[2] = m2r3;
  mat[3] = m2r4;

  int a2r1[] = { 1, 1, 1, 1 };
  int a2r2[] = { 2, 2, 2, 2 };
  int a2r3[] = { 3, 3, 3, 3 };
  int a2r4[] = { 4, 4, 4, 4 };
  ans[0] = a2r1;
  ans[1] = a2r2;
  ans[2] = a2r3;
  ans[3] = a2r4;

  check(mat, ans, 4);

  // 1x1 matrix
  int m3r1[] = { 1 };
  mat[0] = m3r1;

  int a3r1[] = { 1 };
  ans[0] = a3r1;

  check(mat, ans, 1);

  free(mat);
  free(ans);

  return 0;
}
