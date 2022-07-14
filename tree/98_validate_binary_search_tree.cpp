/*
Given the root of a binary tree, determine if it is a valid binary search tree
(BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's
key. The right subtree of a node contains only nodes with keys greater than the
node's key. Both the left and right subtrees must also be binary search trees.
*/

#include <limits.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isValidBST(TreeNode *root) { return dfs(root, LONG_MIN, LONG_MAX); }

  bool dfs(TreeNode *root, long long lower, long long upper) {
    if (root == nullptr) {
      return true;
    }

    if (root->val >= upper || root->val <= lower) {
      return false;
    }

    // iterate left tree and right tree
    return dfs(root->left, lower, root->val) &&
           dfs(root->right, root->val, upper);
  }
};
