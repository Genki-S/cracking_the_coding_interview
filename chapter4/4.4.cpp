#include <iostream>
#include <vector>
#include <queue>
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

class ListNode {
  private:
  public:
    ListNode *next;
    int value;
    ListNode(int v) {
      next = NULL;
      value = v;
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
  }
  if (right.size() > 0) {
    tree->right = make_balanced_bst(right);
  }
  return tree;
}


vector<ListNode*> make_lists(TreeNode* tree) {
  vector<ListNode*> ret;
  queue<TreeNode*> q, nq;
  q.push(tree);
  while (!q.empty()) {
    ListNode *list_head = NULL, *list_tail = NULL;
    while (!q.empty()) {
      TreeNode* tn = q.front(); q.pop();
      ListNode* ln = new ListNode(tn->value);
      if (list_head == NULL) {
        list_head = list_tail = ln;
      } else {
        list_tail->next = ln;
        list_tail = ln;
      }

      if (tn->left != NULL) {
        nq.push(tn->left);
      }
      if (tn->right != NULL) {
        nq.push(tn->right);
      }
    }
    ret.push_back(list_head);
    swap(q, nq);
  }
  return ret;
}

int main()
{
  vector<int> v;
  const int MAX_N = 16;
  for (int i = 1; i < MAX_N; ++i) {
    v.push_back(i);
  }
  TreeNode* tree = make_balanced_bst(v);

  vector<ListNode*> ret = make_lists(tree);
  assert(ret.size() == 4);

  int tree_values[4][8] = {
    { 8 },
    { 4, 12 },
    { 2, 6, 10, 14 },
    { 1, 3, 5, 7, 9, 11, 13, 15 }
  };
  for (int i = 0; i < 4; ++i) {
    ListNode *n = ret[i];
    int j = 0;
    while (n != NULL) {
      assert(n->value == tree_values[i][j]);
      n = n->next;
      j++;
    }
  }
}
