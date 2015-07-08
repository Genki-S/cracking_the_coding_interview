#include <iostream>
#include <bitset>
#include <cassert>
#include <cfloat>
using namespace std;
typedef unsigned long long ULL;

int bit_changed(unsigned a, unsigned b) {
  unsigned c = a ^ b;
  int ans = 0;
  while (c != 0) {
    if (c & 1) { ans++; }
    c >>= 1;
  }
  return ans;
}

int main() {
  assert(bit_changed(31, 14) == 2);
  assert(bit_changed(0, 0) == 0);
  assert(bit_changed(~0, 0) == 32);
}
