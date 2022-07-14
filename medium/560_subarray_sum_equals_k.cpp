#include <unordered_map>
#include <vector>

class Solution {
public:
  int subarraySum(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> mp;
    mp[0] = 1;

    int count = 0, pre = 0;
    for (const auto &num : nums) {
      pre += num;
      if (mp.find(pre - k) != mp.end()) {
        count += mp[pre - k];
      }
      mp[pre]++;
    }

    return count;
  }
};