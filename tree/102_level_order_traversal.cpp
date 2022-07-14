#include <queue>
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

using namespace std;

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (!root) {
      return res;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int cur_level_size = q.size();
      res.push_back(vector<int>());

      for (int i = 1; i <= cur_level_size; i++) {
        auto node = q.front();
        q.pop();
        res.back().push_back(node->val);
        if (node->left) {

          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
    }

    return res;
  }
};