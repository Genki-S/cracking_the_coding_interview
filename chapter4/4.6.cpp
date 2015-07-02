#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class TreeNode {
  private:
  public:
    TreeNode *parent, *left, *right;
    int value;
    TreeNode(int v) {
      value = v;
      parent = left = right = NULL;
    }

    void add_left(TreeNode* n) {
      left = n;
      n->parent = this;
    }

    void add_right(TreeNode* n) {
      right = n;
      n->parent = this;
    }
};

// from 4.3
TreeNode* make_balanced_bst(vector<int> arr) {
  int mid = arr.size() / 2;
  TreeNode* tree = new TreeNode(arr[mid]);
  vector<int> left(arr.begin(), arr.begin() + mid);
  vector<int> right(arr.begin() + mid + 1, arr.end());
  if (left.size() > 0) {
    tree->left = make_balanced_bst(left);
    tree->left->parent = tree;
  }
  if (right.size() > 0) {
    tree->right = make_balanced_bst(right);
    tree->right->parent = tree;
  }
  return tree;
}

TreeNode* in_order_next_node(TreeNode* n) {
  if (n->right != NULL) {
    TreeNode* _n = n->right;
    while (_n->left != NULL) {
      _n = _n->left;
    }
    return _n;
  }
  if (n->parent == NULL) {
    return NULL;
  }
  if (n->parent->left == n) {
    return n->parent;
  }

  // this tree is right tree
  TreeNode* _n = n->parent;
  while (_n && _n->parent && _n->parent->right == _n) {
    _n = _n->parent;
  }
  if (_n->parent && _n->parent->left == _n) {
    return _n->parent;
  } else {
    return NULL;
  }
}

int main()
{
  vector<int> v;
  const int MAX_N = 16;
  for (int i = 1; i < MAX_N; ++i) {
    v.push_back(i);
  }
  TreeNode* tree = make_balanced_bst(v);

  // int tree_values[4][8] = {
    // { 8 },
    // { 4, 12 },
    // { 2, 6, 10, 14 },
    // { 1, 3, 5, 7, 9, 11, 13, 15 }
  // };

  assert(in_order_next_node(tree) == tree->right->left->left);
  assert(in_order_next_node(tree->left->left->left) == tree->left->left);
  assert(in_order_next_node(tree->left->right->right) == tree);
}
