/*
中心拓展，说白了，就是挨个遍历，只不过，中心可能是1个字符也可能是2个字符而已，

不可能出现3个字符作为中心的情况，因为3个字符作为中心的话，他就是回文了，等于1个字符作为中心的情况
*/

#include <string>

class Solution {
public:
  int countSubstrings(std::string s) {
    int num = 0;

    int len = s.size();

    // 遍历回文中心点
    for (int i = 0; i < len; i++) {
      // j=0,中心是一个点，j=1,中心是两个点
      for (int j = 0; j <= 1; j++) {
        int left = i;
        int right = i + j;

        while (left >= 0 && right < len && s[left--] == s[right++]) {
          num++;
        }
      }
    }

    return num;
  }
};