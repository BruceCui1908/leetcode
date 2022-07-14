#include <algorithm>
#include <vector>

class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    int pre = 0;
    int max_num = nums[0];

    // [1,2,3,-4]
    for (const auto &x : nums) {
      pre = std::max(pre + x, x);
      max_num = std::max(pre, max_num);
    }

    return max_num;
  }
};