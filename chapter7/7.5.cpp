#include <iostream>
#include <limits>
#include <complex>
#include <cassert>
using namespace std;

typedef complex<double> Point;
#define Y imag()
#define X real()
const double EPS = 1e-12;
bool EQ(double a, double b) {
  return (isinf(a) && isinf(b))
      || (a - b < EPS && b - a < EPS);
}

class Line {
  private:
  public:
    double slope, y_intersect;
    Line() {
      slope = 0;
      y_intersect = 0;
    }

    Line(double s, double y) {
      slope = s;
      y_intersect = y;
    }

    Line(Point a, Point b) {
      if (a == b) { throw; }
      double dx = b.X - a.X;
      if (EQ(dx, 0)) {
        slope = numeric_limits<double>::infinity();
        y_intersect = numeric_limits<double>::infinity();
      } else {
        slope = (b.Y - a.Y) / dx;
        y_intersect = a.Y + slope * -a.X;
      }
    }

    bool operator==(const Line& rhs) {
      return EQ(slope, rhs.slope) && EQ(y_intersect, rhs.y_intersect);
    }
};
std::ostream& operator<<(std::ostream &s, const Line &l) {
  s << "(" << l.slope << ", " << l.y_intersect << ")" << endl;
	return s;
}

Line divideSquares(Point tl1, Point dr1, Point tl2, Point dr2) {
  Point c1 = Point((tl1.Y + dr1.Y) / 2.0, (tl1.X + dr1.X) / 2.0);
  Point c2 = Point((tl2.Y + dr2.Y) / 2.0, (tl2.X + dr2.X) / 2.0);
  if (c1 == c2) {
    return Line(0, c1.Y);
  }
  return Line(c1, c2);
}

int main() {
  Point tl1, dr1, tl2, dr2;
  Line actual, expected;
  tl1 = Point(0, -1);
  dr1 = Point(-1, 0);
  tl2 = Point(1, 0);
  dr2 = Point(0, 1);
  actual = divideSquares(tl1, dr1, tl2, dr2);
  expected = Line(1, 0);
  assert(actual == expected);

  // Line parallel to Y axis
  tl1 = Point(1, 0);
  dr1 = Point(0, 1);
  tl2 = Point(0, 0);
  dr2 = Point(-1, 1);
  actual = divideSquares(tl1, dr1, tl2, dr2);
  expected = Line(numeric_limits<double>::infinity(), numeric_limits<double>::infinity());
  assert(actual == expected);

  // 2 same square
  tl1 = Point(2, -1);
  dr1 = Point(0, 1);
  tl2 = Point(2, -1);
  dr2 = Point(0, 1);
  actual = divideSquares(tl1, dr1, tl2, dr2);
  expected = Line(0, 1); // expect line with slope 0
  assert(actual == expected);
}
