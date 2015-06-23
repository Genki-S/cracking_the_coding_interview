#include <iostream>
#include <cassert>
#include <climits>
using namespace std;

class TreeNode {
  private:
  public:
    TreeNode *left, *right;
    int value;
    TreeNode(int v) {
      value = v;
      left = right = NULL;
    }
};

bool _is_bst(TreeNode *root, int min, int max) {
  if (root == NULL) { return true; }
  if (root->value < min || root->value >= max) {
    return false;
  }
  if (!_is_bst(root->left, min, root->value) || !_is_bst(root->right, root->value, max)) {
    return false;
  }
  return true;
}

bool is_bst(TreeNode *root) {
  return _is_bst(root, INT_MIN, INT_MAX);
}

int main()
{
  TreeNode *tree = new TreeNode(10);
  assert(is_bst(tree) == true);
  tree->left = new TreeNode(9);
  tree->right = new TreeNode(11);
  assert(is_bst(tree) == true);
  tree->right->right = new TreeNode(11);
  assert(is_bst(tree) == true);
  tree->left->left = new TreeNode(12);
  assert(is_bst(tree) == false);

  tree = new TreeNode(20);
  tree->left = new TreeNode(10);
  tree->right = new TreeNode(30);
  assert(is_bst(tree) == true);
  tree->left->right = new TreeNode(25);
  assert(is_bst(tree) == false);
}
