#include <iostream>
#include <deque>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>

template<typename T>
class Node {
  public:
    T value;
    Node<T> *prev, *next;
    Node(T val) {
      value = val;
    }
};

template<typename T>
class Stack {
  Node<T> *head;
  public:
    Stack() {
      head = NULL;
    }

    void push(T val) {
      Node<T> *n = new Node<T>(val);
      n->next = head;
      head = n;
    }

    T top() {
      if (head == NULL) { throw; }
      return head->value;
    }

    T pop() {
      if (head == NULL) { throw; }
      Node<T>* n = head;
      head = n->next;
      return n->value;
    }

    bool isEmpty() {
      return head == NULL;
    }

    T findMinForTesting() {
      // brute force search
      if (head == NULL) { throw; }
      Node<T> *n = head;
      T min = n->value;
      while (n != NULL) {
        if (n->value < min) {
          min = n->value;
        }
        n = n->next;
      }
      return min;
    }

    void print() {
      Node<T> *n = head;
      while (n != NULL) {
        std::cout << "(" << n->value << ") ->";
        n = n->next;
      }
      std::cout << std::endl;
    }
};

template<typename T>
class MyStack {
  Stack<T> stack;
  Stack<T> minStack;
  public:
    MyStack() {
      stack = Stack<T>();
      minStack = Stack<T>();
    }

    void push(T val) {
      if (minStack.isEmpty() || val <= minStack.top()) {
        minStack.push(val);
      }
      stack.push(val);
    }

    T top() {
      if (stack.isEmpty()) { throw; }
      return stack.top();
    }

    T pop() {
      if (stack.isEmpty()) { throw; }

      T val = stack.pop();
      assert(!minStack.isEmpty());
      if (val == minStack.top()) {
        minStack.pop();
      }
      return val;
    }

    T min() {
      if (minStack.isEmpty()) { throw; }
      return minStack.top();
    }

    T findMinForTesting() {
      return stack.findMinForTesting();
    }

    void print() {
      std::cout << "stack:" << std::endl;
      stack.print();
      std::cout << "minStack:" << std::endl;
      minStack.print();
    }
};

int main() {
  srand(time(0));
  const int MAX_N = 100;
  std::deque<int> deque;
  std::stack<int> stack;
  MyStack<int> myStack;
  for (int i = 0; i < MAX_N; ++i) {
    int val = rand() % MAX_N;
    deque.push_back(val);
    stack.push(val);
    myStack.push(val);
  }
  // myStack.print();

  std::sort(deque.begin(), deque.end());

  int expected, actual;
  while (!stack.empty()) {
    expected = myStack.findMinForTesting();
    actual = myStack.min();
    assert(expected == actual);

    expected = stack.top();
    actual = myStack.top();
    assert(expected == actual);

    if (myStack.top() == deque.front()) {
      deque.pop_front();
    }

    stack.pop();
    myStack.pop();
  }
}
