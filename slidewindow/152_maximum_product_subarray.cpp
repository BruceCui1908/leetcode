/*
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
*/

#include <algorithm>
#include <vector>

class Solution {
public:
  int maxProduct(std::vector<int> &nums) {
    int max_num = nums[0], min_num = nums[0], ans = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      int max = max_num;
      int min = min_num;
      max_num = std::max(max * nums[i], std::max(nums[i], min * nums[i]));
      min_num = std::min(min * nums[i], std::min(nums[i], max * nums[i]));
      ans = std::max(ans, max_num);
    }
    return ans;
  }
};