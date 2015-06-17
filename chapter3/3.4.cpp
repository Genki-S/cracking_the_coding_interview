#include <iostream>

// #include <stack>
#include <deque>
#define stack deque
#define push push_front
#define top front
#define pop pop_front

#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

void print_stack(stack<int> s) {
  cout << "stack: ";
  for(stack<int>::iterator itr = s.begin(); itr != s.end(); ++itr) {
    cout << (*itr) << " ";
  }
  cout << endl;
}

void hanoi(stack<int> &a, stack<int> &b, stack<int> &c, int n) {
  if (n == 0) { return; }
  hanoi(a, c, b, n - 1);
  c.push(a.top()); a.pop();
  hanoi(b, a, c, n - 1);
  // print_stack(a); print_stack(b); print_stack(c);
}

int main()
{
  srand(time(0));
  const int MAX_N = 50;
  stack<int> a;
  int n = rand() % MAX_N;
  for (int i = 0; i < n; ++i) {
    a.push(n - i);
  }
  stack<int> b, c;
  hanoi(a, b, c, n);
  assert(a.size() == 0);
  assert(b.size() == 0);
  assert(c.size() == n);
  for (int i = 0; i < n; ++i) {
    assert(c.top() == i+1);
    c.pop();
  }
}
