#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;

class Node {
  private:
  public:
    int val;
    Node *left, *right;
    Node(int _val) : val(_val) {
      left = right = NULL;
    }

    int height() {
      int ret = 1;
      if (right != NULL) {
        ret = max(ret, 1 + right->height());
      }
      if (left != NULL) {
        ret = max(ret, 1 + left->height());
      }
      return ret;
    }
};

Node* make_balanced_bst(vector<int> arr) {
  int mid = arr.size() / 2;
  Node* tree = new Node(arr[mid]);
  vector<int> left(arr.begin(), arr.begin() + mid);
  vector<int> right(arr.begin() + mid + 1, arr.end());
  if (left.size() > 0) {
    tree->left = make_balanced_bst(left);
  }
  if (right.size() > 0) {
    tree->right = make_balanced_bst(right);
  }
  return tree;
}

int main()
{
  vector<int> v;
  const int MAX_N = 100;
  for (int i = 0; i < MAX_N; ++i) {
    v.push_back(i);
  }

  Node* tree = make_balanced_bst(v);
  assert(tree->height() == ceil(log2(MAX_N)));
}
