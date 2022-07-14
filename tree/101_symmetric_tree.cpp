#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val{0}, left{nullptr}, right{nullptr} {}

  TreeNode(int x) : val{x}, left{nullptr}, right{nullptr} {}

  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val{x}, left{left}, right{right} {}
};

class Solution {
public:
  bool isSymmetric(TreeNode *root) { return check(root, root); }

  bool check(TreeNode *left, TreeNode *right) {
    if (!left && !right) {
      return true;
    }
    if (!left || !right) {
      return false;
    }
    return left->val == right->val && check(left->left, right->right) &&
           check(left->right, right->left);
  }

  bool check2(TreeNode *u, TreeNode *v) {
    std::queue<TreeNode *> queue;
    queue.push(u);
    queue.push(v);

    while (!queue.empty()) {
      u = queue.front();
      queue.pop();

      v = queue.front();
      queue.pop();

      if (!u && !v) {
        continue;
      }

      if ((!u || !v) || (u->val != v->val)) {
        return false;
      }

      queue.push(u->left);
      queue.push(v->right);

      queue.push(u->right);
      queue.push(v->left);
    }

    return true;
  }
};
