#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
class Node {
  public:
    T val;
    Node *right, *left;

    Node(T _val) : val(_val) {
      right = left = NULL;
    }

    int height() {
      int ret = 1;
      if (left != NULL) {
        ret = max(ret, 1 + left->height());
      }
      if (right != NULL) {
        ret = max(ret, 1 + right->height());
      }
      return ret;
    }

    bool is_flat() {
      int left_h = 0, right_h = 0;
      if (left != NULL) {
        left_h = left->height();
      }
      if (right != NULL) {
        right_h = right->height();
      }
      return abs(left_h - right_h) <= 1;
    }
};

int main()
{
  Node<int>* tree = new Node<int>(0);
  assert(tree->is_flat() == true);
  Node<int>* n1 = new Node<int>(1);
  tree->left = n1;
  assert(tree->is_flat() == true);
  Node<int>* n2 = new Node<int>(2);
  n1->right = n2;
  assert(tree->is_flat() == false);
  Node<int>* n3 = new Node<int>(3);
  tree->right = n3;
  assert(tree->is_flat() == true);
}
