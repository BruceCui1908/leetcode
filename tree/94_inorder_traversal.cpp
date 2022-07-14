#include <stack>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val{0}, left{nullptr}, right{nullptr} {}

  TreeNode(int x) : val{x}, left{nullptr}, right{nullptr} {}

  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val{x}, left{left}, right{right} {}
};

// 左子树——根节点——右子树
class Solution {
public:
  std::vector<int> inorderTraversal(TreeNode *node) {
    std::vector<int> res;
    inorderHelper(node, res);
    return res;
  }

  void inorderHelper(TreeNode *root, std::vector<int> &res) {
    if (!root) {
      return;
    }

    inorderHelper(root->left, res);
    res.push_back(root->val);
    inorderHelper(root->right, res);
  }

  std::vector<int> inorderTraversal2(TreeNode *root) {
    std::vector<int> res;
    std::stack<TreeNode *> stk;

    while (root != nullptr || !stk.empty()) {
      while (root != nullptr) {
        stk.push(root);
        root = root->left;
      }

      root = stk.top();
      stk.pop();
      res.push_back(root->val);
      root = root->right;
    }

    return res;
  }
};