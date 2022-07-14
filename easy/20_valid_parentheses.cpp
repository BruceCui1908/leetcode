#include <stack>
#include <string>
#include <unordered_map>

/*
20. Valid Parentheses
https://leetcode.cn/problems/valid-parentheses/

Input: s = "()[]{}"
Output: true
*/
using namespace std;

class Solution {
public:
  bool isValid(std::string s) {
    int n = s.size();
    if (n % 2 == 1) {
      return false;
    }

    std::unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
    std::stack<char> stk;

    for (char ch : s) {
      // if met right one
      if (pairs.count(ch)) {
        if (stk.empty() || stk.top() != pairs[ch]) {
          return false;
        }
        stk.pop();
      }
      // if met left one
      else {
        stk.push(ch);
      }
    }

    return stk.empty();
  }
};