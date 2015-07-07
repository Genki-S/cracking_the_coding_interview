#include <iostream>
#include <bitset>
#include <cassert>
using namespace std;

int insert_bits(int N, int M, int i, int j) {
  // 1. clear i..j bits of N to 0
  // 2. shift M so that it starts from i-th bit
  // 3. calculate or of those
  int mask = ~(((1 << (j + 1)) - 1) & ~((1 << (i + 1)) - 1));
  int ret = N & mask;
  ret = ret | (M << i);
  return ret;
}

int main() {
  // N = 100_0000_0000, M = 1_0011
  int N = 0x400, M = 0x13;
  // bitset<11> n(N);
  // bitset<5> m(M);
  // cout << n << endl;
  // cout << m << endl;

  // expected = 100_0100_1100
  int expected = 0x44C;
  int actual = insert_bits(N, M, 2, 6);
  assert(expected == actual);
}
