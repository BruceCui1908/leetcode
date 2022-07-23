#include <algorithm>
#include <iostream>
#include <string>

class Solution {
public:
  std::string longestPalindrome(std::string s) {
    std::string ans;
    int max = 0;

    for (int i = 0; i < s.size(); i++) {
      for (int j = i + 1; j <= s.size(); j++) {
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

    // abcba
    for (int i = 0; i < len / 2; i++) {
      if (s[i] != s[len - i - 1]) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  std::string input = "abcdefghijklmn";

  for (int i = 0; i < input.size(); i++) {
    for (int j = i + 1; j <= input.size(); j++) {
      std::string sub = input.substr(i, j - i);
      std::cout << sub << " ";
    }
  }

  std::cout << std::endl;
}