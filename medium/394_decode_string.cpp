/*
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Input: s = "3[a2[c]]"
Output: "accaccacc"

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
*/
#include <stack>
#include <string>
#include <utility>

class Solution {
public:
  std::string decodeString(std::string s) {
    std::stack<std::pair<int, std::string>> sta;
    int num = 0;
    std::string res = "";

    for (int i = 0; i < s.size(); i++) {
      if (s[i] >= '0' && s[i] <= '9') {
        num *= 10;
        num += (s[i] - '0');
      } else if (s[i] == '[') {
        sta.push(std::make_pair(num, res));
        num = 0;
        res = "";
      } else if (s[i] == ']') {
        int n = sta.top().first;
        std::string a = sta.top().second;
        sta.pop();
        for (int i = 0; i < n; i++) {
          a += res;
        }
        res = a;
      } else {
        res += s[i];
      }
    }

    return res;
  }
};