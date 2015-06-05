#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <stack>
using namespace std;

class Node {
  public:
    int value;
    Node *prev, *next;

    Node(int v);
    void push_back(Node* n) {
      Node* tail = this->tail();
      tail->next = n;
      n->prev = tail;
    }
    Node* tail() {
      Node* n = this;
      while (n->next != NULL) {
        n = n->next;
      }
      return n;
    }

    void print() {
      Node* n = this;
      do {
        printf("(%d) -> ", n->value);
        n = n->next;
      } while (n != NULL);
      printf("\n");
    }
};

Node::Node(int v) {
  value = v;
  prev = next = NULL;
}

int list_len(Node* n) {
  int ret = 0;
  while (n != NULL) {
    ret++;
    n = n->next;
  }
  return ret;
}

bool is_palindrome(Node* list) {
  if (list == NULL) { return true; }

  int len = list_len(list);
  stack<int> st;
  Node* n = list;
  for (int i = 0; i < len / 2; ++i) {
    st.push(n->value);
    n = n->next;
  }
  if (len % 2 == 1) {
    // ignore center
    n = n->next;
  }
  for (int i = 0; i < len / 2; ++i) {
    int expected = st.top(); st.pop();
    if (n->value != expected) {
      return false;
    }
    n = n->next;
  }
  return true;
}

int main() {
  Node* n = NULL;
  assert(is_palindrome(n) == true);
  n = new Node(0);
  assert(is_palindrome(n) == true);
  srand(time(0));
  const int MAX_N = 100;

  int limit = rand() % MAX_N + 1; // NOTE: at least 1
  stack<int> st;
  for (int i = 0; i < limit; ++i) {
    int t = rand() % MAX_N;
    t += 1; // NOTE: head of list contains 0
    st.push(t);
    n->push_back(new Node(t));
  }
  assert(is_palindrome(n) == false);

  for (int i = 0; i < limit; ++i) {
    int t = st.top(); st.pop();
    n->push_back(new Node(t));
  }
  n->push_back(new Node(0));
  assert(is_palindrome(n) == true);
}
