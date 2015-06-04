#include <iostream>
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

Node* magic_add(Node* n1, Node* n2) {
  // Try zipping rather than producing intval from each list
  bool carry = false;
  Node* ret = NULL;
  while (n1 != NULL || n2 != NULL) {
    int sum = 0;
    if (n1 != NULL) {
      sum += n1->value;
      n1 = n1->next;
    }
    if (n2 != NULL) {
      sum += n2->value;
      n2 = n2->next;
    }
    sum += carry;

    carry = sum >= 10;
    Node* new_n = new Node(sum % 10);
    if (ret == NULL) {
      ret = new_n;
    } else {
      // FIXME: this is slow because push_back is O(N)
      ret->push_back(new_n);
    }
  }
  return ret;
}

int main() {
  int v1a[] = { 7, 1, 6 }, v1b[] = { 5, 9, 2 };
  Node *l1a = make_list(v1a, 3), *l1b = make_list(v1b, 3);
  Node* n1 = magic_add(l1a, l1b);
  int a1[] = { 2, 1, 9 };
  for (int i = 0; i < sizeof(a1) / sizeof(a1[0]); ++i) {
    assert(n1 != NULL);
    assert(n1->value == a1[i]);
    n1 = n1->next;
  }

  int v2a[] = { 7, 2, 6, 9, 4 }, v2b[] = { 5, 9, 5 };
  Node *l2a = make_list(v2a, 5), *l2b = make_list(v2b, 3);
  Node* n2 = magic_add(l2a, l2b);
  int a2[] = { 2, 2, 2, 0, 5 };
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
