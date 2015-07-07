#include <iostream>
#include <bitset>
#include <cassert>
#include <cfloat>
using namespace std;

string double_as_bitstring(double d) {
  assert(0 < d && d < 1);
  string ret = "0.";
  double denom = 1 / 2.0;
  while (d > DBL_MIN) {
    if (d >= denom) {
      d -= denom;
      ret += "1";
    } else {
      ret += "0";
    }
    denom /= 2.0;
  }
  if (ret.length() > 32) {
    return "ERROR";
  } else {
    return ret;
  }
}

int main() {
  assert(double_as_bitstring(0.5) == "0.1");
  assert(double_as_bitstring(0.25) == "0.01");
  assert(double_as_bitstring(0.000000000000003) == "ERROR");
}
