#include <algorithm>
#include <string>

class Solution {
public:
  std::string longestPalindrome(std::string s) {
    std::string ans;

    int max = 0;
    int len = s.size();

    for (int i = 0; i < len; i++) {
      for (int j = i + 1; j <= len; j++) {
        std::string test = s.substr(i, j - i);

        if (isPalindromic(test) && test.size() > max) {
          ans = test;
          max = std::max(max, (int)ans.size());
        }
      }
    }

    return ans;
  }

  bool isPalindromic(const std::string &s) {
    int len = s.size();

    for (int i = 0; i < len / 2; i++) {
      if (s[i] != s[len - i - 1]) {
        return false;
      }
    }

    return true;
  }
};