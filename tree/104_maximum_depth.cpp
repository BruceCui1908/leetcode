#include <algorithm>
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
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }

  int dfs(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    std::queue<TreeNode *> queue;
    queue.push(root);
    int ans = 0;

    while (!queue.empty()) {
      int size = queue.size();
      while (size > 0) {
        TreeNode *node = queue.front();
        queue.pop();
        if (node->left) {
          queue.push(node->left);
        }

        if (node->right) {
          queue.push(node->right);
        }

        size--;
      }
      ans++;
    }

    return ans;
  }
};