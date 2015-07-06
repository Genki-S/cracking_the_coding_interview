#include <iostream>
#include <vector>
#include <deque>
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

typedef deque<TreeNode*> Path;
// Returns paths [vector<Path>] whose end node is lower than *node*
vector<Path> paths_with_sum(int sum, int current_sum, TreeNode* node, Path current_path) {
  vector<Path> paths;
  if (node == NULL) { return paths; }

  current_sum += node->value;
  current_path.push_back(node);
  while (current_sum > sum) {
    assert(current_path.size() > 0);
    current_sum -= current_path.front()->value;
    current_path.pop_front();
  }

  if (current_sum == sum && !current_path.empty()) {
    paths.push_back(current_path);
  }

  vector<Path> tmp;
  tmp = paths_with_sum(sum, current_sum, node->left, current_path);
  paths.insert(paths.end(), tmp.begin(), tmp.end());
  tmp = paths_with_sum(sum, current_sum, node->right, current_path);
  paths.insert(paths.end(), tmp.begin(), tmp.end());

  return paths;
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
  vector<Path> paths;
  paths = paths_with_sum(15, 0, tree, Path());
  // 8 > 4 > 2 > 1, 4 > 6 > 5, 15
  assert(paths.size() == 3);
  for (int i = 0; i < paths.size(); ++i) {
    Path& path = paths[i];
    if (path.size() == 4) {
      int expected[] = {8, 4, 2, 1};
      for (int j = 0; j < 4; ++j) {
        assert(path[j]->value == expected[j]);
      }
    } else if (path.size() == 3) {
      int expected[] = {4, 6, 5};
      for (int j = 0; j < 3; j++) {
        assert(path[j]->value == expected[j]);
      }
    } else if (path.size() == 1) {
      assert(path[0]->value == 15);
    } else {
      assert(false);
    }
  }
}
