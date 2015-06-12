#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

template<typename T>
class MyQueue {
  stack<T> inputStack;
  stack<T> outputStack;
  public:
    MyQueue() {
    }

    void push(T val) {
      inputStack.push(val);
    }

    T pop() {
      if (outputStack.empty()) {
        swapStacks();
      }
      if (outputStack.empty()) { throw; }

      T ret = outputStack.top(); outputStack.pop();
      return ret;
    }

    T front() {
      if (outputStack.empty()) {
        swapStacks();
      }
      if (outputStack.empty()) { throw; }
      return outputStack.top();
    }

    void swapStacks() {
      while (!inputStack.empty()) {
        outputStack.push(inputStack.top()); inputStack.pop();
      }
    }
};

int main() {
  srand(time(0));
  const int MAX_N = 100;
  MyQueue<int> myQueue;
  queue<int> stdQueue;
  int limit = rand() % MAX_N;
  for (int i = 0; i < limit; ++i) {
    int val = rand() % MAX_N;
    myQueue.push(val);
    stdQueue.push(val);
  }
  for (int i = 0; i < limit; ++i) {
    assert(myQueue.front() == stdQueue.front());
    // cerr << myQueue.front() << endl;
    // cerr << stdQueue.front() << endl;
    myQueue.pop();
    stdQueue.pop();
  }
}
