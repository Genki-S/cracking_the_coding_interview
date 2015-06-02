#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

void bubbleUpSmallerThan(list<int>& l, int x)
{
  list<int>::iterator fast_f, slow_f; // fingers
  fast_f = slow_f = l.begin();
  while (fast_f != l.end()) {
    if (fast_f == slow_f) {
      ++fast_f;
      if (*slow_f < x) {
        ++slow_f;
      }
      continue;
    }

    assert(*slow_f >= x);
    if (*fast_f < x) {
      swap(*fast_f, *slow_f);
      ++slow_f;
    }
    ++fast_f;
  }
}

int main()
{
  list<int> mylist;
  srand(time(NULL));
  const int MAX_N = 100;

  for (int i = 0; i < 100; ++i) {
    mylist.push_back(rand() % MAX_N);
  }

  int threshold = rand() % MAX_N;
  bubbleUpSmallerThan(mylist, threshold);

  bool smaller = true;
  for(list<int>::iterator itr = mylist.begin(); itr != mylist.end(); ++itr) {
    if (smaller && *itr > threshold) {
      smaller = false;
    }

    if (smaller) {
      assert(*itr < threshold);
    } else {
      assert(*itr >= threshold);
    }
  }
}
