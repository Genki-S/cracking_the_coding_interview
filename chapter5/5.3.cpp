#include <iostream>
#include <bitset>
#include <cassert>
#include <cfloat>
using namespace std;
typedef unsigned long long ULL;

ULL same_bits_prev(ULL num) {
  assert(num > 0);
  if (num == (~0ULL)) { return ~0ULL; } // all 1 except sign
  // move least significant 1 (after at least one occurence of 0) to right by 1 bit
  ULL ret = num;
  bool zero_found = false;
  for (int i = 0; i < 64; ++i) {
    if ((ret & (1ULL << i)) == 0) {
      zero_found = true;
    } else {
      if (zero_found) {
        ret = ret & ~(1ULL << i);
        ret = ret | (1 << (i-1));
        break;
      }
    }
  }
  if (ret == num) { return ~(0ULL); }
  return ret;
}

ULL same_bits_succ(ULL num) {
  assert(num > 0);
  if (num == (~0ULL)) { return ~0ULL; } // all 1 except sign
  // move least significant 1 to left
  bool one_found = false;
  ULL ret = num;
  for (int i = 0; i < 64; ++i) {
    if ((ret & (1ULL << i)) != 0) {
      one_found = true;
    } else {
      if (one_found) {
        ret = ret & ~(1ULL << (i-1));
        ret = ret | (1ULL << i);
        break;
      }
    }
  }
  if (ret == num) { return ~(0ULL); }
  return ret;
}

int main() {
  ULL bit = 0x1; // 0001
  assert(same_bits_prev(bit) == ~(0ULL));
  assert(same_bits_succ(bit) == 0x2);
  bit = 0x10; // 10000
  assert(same_bits_prev(bit) == 0x8);
  assert(same_bits_succ(bit) == 0x20);
  bit = ~0ULL;
  assert(same_bits_prev(bit) == ~(0ULL));
  assert(same_bits_succ(bit) == ~(0ULL));
}
