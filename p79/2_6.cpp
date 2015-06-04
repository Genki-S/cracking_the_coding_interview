#include <iostream>
#include <cstdio>
#include <set>
#include <cassert>
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
    Node* head() {
      Node* n = this;
      while (n->prev != NULL) {
        n = n->prev;
      }
      return n;
    }

    Node* nth(int n) {
      Node* node = this;
      for (int i = 0; i < n; ++i) {
        node = node->next;
        if (node == NULL) {
          break;
        }
      }
      return node;
    }

    void print() {
      Node* n = this;
      do {
        printf("(%d) -> ", n->value);
        n = n->next;
      } while (n != NULL);
    }
};

Node::Node(int v) {
  value = v;
  prev = next = NULL;
}

Node* find_loop(Node* list) {
  set<Node*> visited;
  Node* n = list;
  while (n != NULL) {
    if (visited.find(n) != visited.end()) {
      return n;
    }
    visited.insert(n);
    n = n->next;
  }
  return NULL;
}

int main() {
  Node* n = new Node(0);
  for (int i = 1; i < 5; ++i) {
    n->push_back(new Node(i));
  }

  assert(find_loop(n) == NULL);

  n->tail()->next = n->nth(2);
  assert(find_loop(n) == n->nth(2));

  assert(find_loop(NULL) == NULL);
}
