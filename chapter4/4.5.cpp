#include <iostream>
#include <cassert>
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

bool is_bst(TreeNode *root) {
  if (root == NULL) { return true; }
  if (root->left != NULL && (!is_bst(root->left) || root->left->value > root->value)) {
    return false;
  }
  if (root->right != NULL && (!is_bst(root->right) || root->right->value < root->value)) {
    return false;
  }
  return true;
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
}
