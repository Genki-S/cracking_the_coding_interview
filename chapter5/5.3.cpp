#include <iostream>
#include <bitset>
#include <cassert>
#include <cfloat>
using namespace std;
typedef unsigned long long ULL;

const int BITSIZE = 32;

int same_bits_prev(int num) {
  assert(num > 0);
  // move least significant movable 1 to right, and move 1s to left as much as possible
  int p = 0;
  int c0 = 0, c1 = 0;
  while (p < BITSIZE && (num & (1 << p)) != 0) {
    c1++; p++;
  }
  while (p < BITSIZE && (num & (1 << p)) == 0) {
    c0++; p++;
  }

  if (p == 0 || p >= BITSIZE) {
    return -1;
  }
  assert((num & (1 << p)) != 0);

  // 1. clear 1s before p
  num &= ~((1 << p) - 1);
  // 2. subtract 1 and make all bits before p to 1
  num -= 1;
  // 3. fill c0-1 0s from right
  num &= ~((1 << (c0-1)) - 1);

  return num;
}

int same_bits_succ(int num) {
  assert(num > 0);
  // move least significant movable 1 to left, and move 1s to right as much as possible
  int p = 0;
  int c0 = 0, c1 = 0;
  while (p < BITSIZE && (num & (1 << p)) == 0) {
    c0++; p++;
  }
  while (p < BITSIZE && (num & (1 << p)) != 0) {
    c1++; p++;
  }

  if (p == 0 || p >= BITSIZE) {
    return -1;
  }
  assert((num & (1 << p)) == 0);

  // 1. get 1 to the left
  num |= (1 << p);
  // 2. clear all bits before p
  num &= ~((1 << p) - 1);
  // 3. fill c1-1 1s from right
  num |= (1 << (c1-1)) - 1;

  return num;
}

int main() {
  int bit = 0x1; // 0001
  // assert(same_bits_prev(bit) == ~(0));
  // assert(same_bits_succ(bit) == 0x2);
  bit = 0x10; // 10000
  // assert(same_bits_prev(bit) == 0x8);
  // assert(same_bits_succ(bit) == 0x20);
  bit = 0x2783; // 10 0111 1000 0011 (p.239)
  assert(same_bits_prev(bit) == 0x2770); // 10 0111 0111 0000
  bit = 0x367C; // 11 0110 0111 1100 (p.236)
  assert(same_bits_succ(bit) == 0x368F); // 11 0110 1000 1111
}
