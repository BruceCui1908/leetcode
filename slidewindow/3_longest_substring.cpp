#include <algorithm>
#include <string>
#include <unordered_set>

/*
3. Longest Substring Without Repeating Characters
https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/
class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    std::unordered_set<char> set;
    int right = -1;
    int res = 0;

    // when left move, remove from set, when right move, insert into set
    for (int left = 0; left < s.size(); left++) {
      if (left != 0) {
        set.erase(s[left - 1]);
      }

      while (right + 1 < s.size() && !set.count(s[right + 1])) {
        set.insert(s[right + 1]);
        right++;
      }

      res = std::max(res, right + 1 - left);
    }

    return res;
  }
};