/*
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
*/
#include <algorithm>
#include <vector>

class Solution {
public:
  int rob(std::vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }

    int size = nums.size();
    if (size == 1) {
      return nums[0];
    }

    int first = nums[0];
    int second = std::max(nums[0], nums[1]);
    for (int i = 2; i < size; i++) {
      int temp = second;
      second = std::max(first + nums[i], second);
      first = temp;
    }

    return second;
  }
};