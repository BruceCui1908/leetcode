#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> ans;
    int len = nums.size();

    for (int first = 0; first < len; first++) {
      if (first > 0 && nums[first] == nums[first - 1]) {
        continue;
      }

      int third = len - 1;
      int target = -nums[first];

      for (int second = first + 1; second < len; second++) {
        if (second > first + 1 && nums[second] == nums[second - 1]) {
          continue;
        }

        while (second < third && nums[second] + nums[third] > target) {
          third--;
        }

        if (second == third) {
          break;
        }

        if (nums[second] + nums[third] == target) {
          ans.push_back({nums[first], nums[second], nums[third]});
        }
      }
    }

    return ans;
  }
};