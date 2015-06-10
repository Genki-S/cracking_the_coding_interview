#include <iostream>
#include <deque>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <cassert>

template<typename T>
class SetOfStacks {
  int limit;
  std::deque< std::stack<T> > stacks;

  std::stack<T>& add_stack() {
    stacks.push_front(std::stack<T>());
    return stacks.front();
  }

  public:
    SetOfStacks(int _limit) : limit(_limit) {
      add_stack();
    }

    void push(T val) {
      if (stacks.front().size() == limit) {
        add_stack();
      }
      stacks.front().push(val);
    }

    T pop() {
      std::stack<T> &current_stack = stacks.front();
      if (current_stack.size() == 0) { throw; }
      T ret = current_stack.top(); current_stack.pop();
      if (current_stack.size() == 0) {
        stacks.pop_front();
      }
      return ret;
    }

    T popAt(int index) {
      if (index >= stacks.size()) { throw; }
      std::stack<T> &stack = *(stacks.begin() + index);
      T ret = stack.top(); stack.pop();
      if (stack.size() == 0) {
        stacks.erase(stacks.begin() + index);
      }
      return ret;
    }

    T top() {
      return stacks.front().top();
    }
};

int main()
{
  srand(time(0));
  const int MAX_N = 100;
  SetOfStacks<int> myStack(rand() % MAX_N);
  std::stack<int> stdStack;

  for (int i = 0; i < MAX_N; ++i) {
    int val = rand() % MAX_N;
    stdStack.push(val);
    myStack.push(val);
  }

  while (!stdStack.empty()) {
    assert(myStack.top() == stdStack.top());
    myStack.pop();
    stdStack.pop();
  }

  myStack = SetOfStacks<int>(3);
  for (int i = 5; i >= 0; --i) {
    myStack.push(i);
  }
  assert(myStack.popAt(1) == 3);
}
