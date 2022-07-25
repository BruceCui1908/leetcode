#include <vector>

/*
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be
target 3.

-1 + 1 + 1 + 1 + 1 = 3

+1 - 1 + 1 + 1 + 1 = 3

+1 + 1 - 1 + 1 + 1 = 3

+1 + 1 + 1 - 1 + 1 = 3

+1 + 1 + 1 + 1 - 1 = 3
*/
class Solution {
public:
  int count{0};
  int findTargetSumWays(std::vector<int> &nums, int target) {
    backtrack(nums, target, 0, 0);
    return count;
  }

  void backtrack(std::vector<int> &nums, int target, int index, int sum) {
    if (index == nums.size()) {
      if (sum == target) {
        count++;
      }
    } else {
      backtrack(nums, target, index + 1, sum + nums[index]);
      backtrack(nums, target, index + 1, sum - nums[index]);
    }
  }
};