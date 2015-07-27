#include <iostream>
#include <cassert>
using namespace std;

int myMult(int a, int b) {
  bool negative = (a < 0) ^ (b < 0);
  a = abs(a); b = abs(b);
  int ret = 0;
  for (int i = 0; i < b; ++i) {
    ret += a;
  }
  return negative ? -ret : ret;
}

int myDiv(int a, int b) {
  bool negative = (a < 0) ^ (b < 0);
  a = abs(a); b = abs(b);
  int curr = 0;
  int ret = 0;
  while (curr + b <= a) {
    curr += b;
    ret += 1;
  }
  return negative ? -ret : ret;
}

int myMinus(int a, int b) {
  return a + (~b + 1);
}

int main()
{
  assert(myMult(1, 1) == 1);
  assert(myMult(0, 1) == 0);
  assert(myMult(3, 3) == 9);
  assert(myMult(-3, 3) == -9);
  assert(myMult(-3, -3) == 9);

  assert(myDiv(9, 3) == 3);
  assert(myDiv(9, 4) == 2);
  assert(myDiv(0, 1) == 0);
  assert(myDiv(-8, 2) == -4);
  assert(myDiv(-8, -2) == 4);

  assert(myMinus(5, 2) == 3);
  assert(myMinus(5, 5) == 0);
  assert(myMinus(5, 8) == -3);
}
