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

// This is different algorithm from answer on the book, but seems right
// Complexity is O(depth^2)
TreeNode* common_ancestor(TreeNode* a, TreeNode* b) {
  TreeNode* ta = a;
  while (ta != NULL) {
    TreeNode* tb = b;
    while (tb != NULL) {
      if (ta == tb) { return ta; }
      tb = tb->parent;
    }
    ta = ta->parent;
  }
  return NULL;
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

  assert(common_ancestor(tree->left, tree->right) == tree);
  assert(common_ancestor(tree->left->left->right, tree->left->right->left) == tree->left);
  assert(common_ancestor(tree->left->left->left, tree->right->right->right) == tree);
}
