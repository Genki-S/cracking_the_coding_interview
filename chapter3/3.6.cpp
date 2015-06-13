#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>

// #include <deque>
// #define stack deque
// #define push push_front
// #define top front
// #define pop pop_front
// #define dump(x) { cerr << " [L" << __LINE__ << "] " << #x << " = " << (x) << endl; }
// template<typename T>
// void print_stack(stack<T> s) {
  // cout << "stack: ";
  // for(stack<int>::iterator itr = s.begin(); itr != s.end(); ++itr) {
    // cout << (*itr) << " ";
  // }
  // cout << endl;
// }

using namespace std;

template<typename T>
void sortStack(stack<T> &st) {
  stack<T> sorted;
  stack<T> next;
  bool minTop = true;
  while (!st.empty()) {
    T &val = st.top();

    // cout << "st: ";
    // print_stack(st);
    // dump(val);

    bool pushed = false;
    while (!sorted.empty()) {
      if ( !pushed && ( (minTop && val < sorted.top()) || (!minTop && val > sorted.top()) ) ) {
        next.push(val);
        pushed = true;
      }
      next.push(sorted.top()); sorted.pop();
    }
    if (!pushed) {
      next.push(val);
    }

    // cout << "next: ";
    // print_stack(next);

    st.pop();
    stack<T> tmp = sorted;
    sorted = next;
    next = tmp;
    minTop = !minTop;
  }

  if (!minTop) {
    while (!sorted.empty()) {
      next.push(sorted.top()); sorted.pop();
    }
    sorted = next;
  }

  st = sorted;
}

int main()
{
  srand(time(0));
  const int MAX_N = 100;
  stack<int> st;
  vector<int> v;
  int limit = rand() % MAX_N;
  for (int i = 0; i < limit; ++i) {
    int val = rand() % MAX_N;
    st.push(val);
    v.push_back(val);
  }
  sort(v.begin(), v.end());
  sortStack(st);

  for (int i = 0; i < v.size(); ++i) {
    assert(v[i] == st.top());
    st.pop();
  }
}
