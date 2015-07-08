#include <iostream>
#include <bitset>
#include <cassert>
#include <cfloat>
using namespace std;
typedef unsigned long long ULL;

int bit_swap(unsigned num) {
  // 0-origin masks
  // 0101 0101 0101 0101 0101 0101 0101 0101
  const unsigned even_mask = 0x55555555;
  // 1010 1010 1010 1010 1010 1010 1010 1010
  const unsigned odd_mask = 0xAAAAAAAA;

  unsigned even = (num >> 1) & even_mask;
  unsigned odd = (num << 1) & odd_mask;
  return even | odd;
}

int main() {
  // 0000 => 0000
  assert(bit_swap(0) == 0);
  // 1010 => 0101
  assert(bit_swap(0xA) == 0x5);
}
