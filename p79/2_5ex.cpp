#include <iostream>
#include <cstdio>
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

Node* make_list(int values[], int size) {
  Node* list = new Node(values[0]);
  for (int i = 1; i < size; ++i) {
    Node* n = new Node(values[i]);
    list->push_back(n);
  }
  return list;
}

int magic_value(Node* n) {
  int v = 0;
  while (n != NULL) {
    v *= 10;
    v += n->value;
    n = n->next;
  }
  return v;
}

Node* magic_add(Node* n1, Node* n2) {
  int sum = magic_value(n1) + magic_value(n2);
  int divisor = 1;
  while (sum / divisor > 0) {
    divisor *= 10;
  }
  divisor /= 10;

  Node* ret = NULL;
  while (divisor) {
    int digit = (sum / divisor) % 10;
    Node* n = new Node(digit);
    if (ret == NULL) {
      ret = n;
    } else {
      // FIXME: O(N)
      ret->push_back(n);
    }
    divisor /= 10;
  }
  return ret;
}

int main() {
  int v1a[] = { 6, 1, 7 }, v1b[] = { 2, 9, 5 };
  Node *l1a = make_list(v1a, 3), *l1b = make_list(v1b, 3);
  Node* n1 = magic_add(l1a, l1b);
  int a1[] = { 9, 1, 2 };
  for (int i = 0; i < sizeof(a1) / sizeof(a1[0]); ++i) {
    assert(n1 != NULL);
    assert(n1->value == a1[i]);
    n1 = n1->next;
  }

  int v2a[] = { 7, 2, 6, 9, 4 }, v2b[] = { 5, 9, 5 };
  Node *l2a = make_list(v2a, 5), *l2b = make_list(v2b, 3);
  Node* n2 = magic_add(l2a, l2b);
  int a2[] = { 7, 3, 2, 8, 9 };
  for (int i = 0; i < sizeof(a2) / sizeof(a2[0]); ++i) {
    assert(n2 != NULL);
    assert(n2->value == a2[i]);
    n2 = n2->next;
  }

  int v3a[] = { 7, 3, 6, 9, 4 }, v3b[] = {};
  Node *l3a = make_list(v3a, 5), *l3b = NULL;
  Node* n3 = magic_add(l3a, l3b);
  int a3[] = { 7, 3, 6, 9, 4 };
  for (int i = 0; i < sizeof(a3) / sizeof(a3[0]); ++i) {
    assert(n3 != NULL);
    assert(n3->value == a3[i]);
    n3 = n3->next;
  }

  assert(magic_add(NULL, NULL) == NULL);
}
