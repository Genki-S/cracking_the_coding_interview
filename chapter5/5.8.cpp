#include <iostream>
#include <cassert>
#include <bitset>
using namespace std;

typedef char byte;

void drawHorizontalLine(byte screen[], int width, int x1, int x2, int y) {
  y--, x1--, x2--; // make y and xs 0-origin
  int offset = (width / 8) * y;
  int i = offset + x1 / 8, j = offset + x2 / 8;
  byte mask = (1 << (8 - x1 % 8)) - 1;
  screen[i] |= mask;
  mask = (1 << 8) - 1;
  for (int k = i+1; k < j; ++k) {
    screen[k] |= mask;
  }
  mask = ~0 << (7 - x2 % 8);
  screen[j] |= mask;
}

int main() {
  byte screen[] = {
    0x00, 0x00, 0x00,
    0x80, 0x00, 0x01
  };

  // 10000000 00000000 00000001 =>
  // 10001111 11111111 11110001
  drawHorizontalLine(screen, 8 * 3, 5, 20, 2);

  assert(screen[3] == (byte)0x8f);
  assert(screen[4] == (byte)0xff);
  assert(screen[5] == (byte)0xf1);
}
