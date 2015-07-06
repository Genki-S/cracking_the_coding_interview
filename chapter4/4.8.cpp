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

bool is_same_tree(TreeNode *a, TreeNode *b) {
  if (a == NULL && b == NULL) { return true; }
  if (a == NULL || b == NULL) { return false; }
  if (a->value != b->value) { return false; }
  return is_same_tree(a->left, b->left) && is_same_tree(a->right, b->right);
}

bool check_bottomup(TreeNode *a, TreeNode *b) {
  if (b == NULL) { return true; }
  if (a == NULL) { return false; }
  if (a->value != b->value) { return false; }
  return is_same_tree(a->right, b->right) && check_bottomup(a->parent, b->parent);
}

bool _is_subtree(TreeNode* tree, TreeNode* sub, TreeNode *sub_leaf) {
  if (tree == NULL) { return false; }
  if (tree->left == NULL) {
    return check_bottomup(tree, sub_leaf);
  }
  return _is_subtree(tree->left, sub, sub_leaf) || _is_subtree(tree->right, sub, sub_leaf);
}

bool is_subtree(TreeNode* tree, TreeNode* sub) {
  TreeNode *sub_leaf = sub;
  while (sub_leaf->left != NULL) {
    sub_leaf = sub_leaf->left;
  }
  return _is_subtree(tree, sub, sub_leaf);
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
  TreeNode* sub = new TreeNode(10);
  sub->left = new TreeNode(9);
  sub->left->parent = sub;
  assert(is_subtree(tree, sub) == false);
  sub->right = new TreeNode(11);
  sub->right->parent = sub;
  assert(is_subtree(tree, sub) == true);
}
