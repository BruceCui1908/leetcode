#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> result;
    std::string current;
    backtrack(result, current, 0, 0, n);
    return result;
  }

  void backtrack(std::vector<std::string> &ans, std::string &current, int open,
                 int close, int n) {
    if (current.size() == 2 * n) {
      ans.push_back(current);
      return;
    }

    if (open < n) {
      current.push_back('(');
      backtrack(ans, current, open + 1, close, n);
      current.pop_back();
    }

    if (close < open) {
      current.push_back(')');
      backtrack(ans, current, open, close + 1, n);
      current.pop_back();
    }
  }
};