#include <iostream>
#include <unordered_map>
#include <vector>

/*
1. Two Sum
https://leetcode-cn.com/problems/two-sum/
*/
class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> hastable;
    for (int i = 0; i < nums.size(); i++) {
      auto it = hastable.find(target - nums[i]);
      if (it != hastable.end()) {
        return std::vector<int>{it->second, i};
      }

      hastable[nums[i]] = i;
    }
    return std::vector<int>{};
  }
};