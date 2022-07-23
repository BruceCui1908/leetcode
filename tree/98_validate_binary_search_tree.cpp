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
  bool isValidBST(TreeNode *root) {
    return is_bst_helper(root, LONG_MIN, LONG_MAX);
  }

  bool is_bst_helper(TreeNode *node, long long lower, long long upper) {
    if (node == nullptr) {
      return true;
    }

    if (node->val <= lower || node->val >= upper) {
      return false;
    }

    return is_bst_helper(node->left, lower, node->val) &&
           is_bst_helper(node->right, node->val, upper);
  }
};

/*
中序遍历是二叉树的一种遍历方式，它先遍历左子树，再遍历根节点，最后遍历右子树。
而我们二叉搜索树保证了左子树的节点的值均小于根节点的值，根节点的值均小于右子树的值，
因此中序遍历以后得到的序列一定是升序序列
*/

#include <stack>
using namespace std;

class Solution2 {
public:
  bool isValidBST(TreeNode *root) {
    stack<TreeNode *> st;
    int min = INT_MIN;

    while (!st.empty() || root) {
      while (root) {
        st.push(root);
        root = root->left;
      }

      root = st.top();
      st.pop();

      // 如果中序遍历得到的节点的值小于等于前一个 inorder，说明不是二叉搜索树
      if (root->val <= min) {
        return false;
      }

      min = root->val;
      root = root->right;
    }

    return true;
  }
};

class Solution3 {
public:
  long pre{LONG_MIN};
  bool isValidBST(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }

    // 访问左子树
    if (!isValidBST(root->left)) {
      return false;
    }

    if (root->val <= pre) {
      return false;
    }

    return isValidBST(root->right);
  }
};