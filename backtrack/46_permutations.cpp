#include <utility>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;
    backtrack(result, nums, 0);
    return result;
  }

  void backtrack(std::vector<std::vector<int>> &res, std::vector<int> &nums,
                 int index) {
    if (index == nums.size()) {
      res.emplace_back(nums);
      return;
    }

    for (int i = index; i < nums.size(); i++) {
      std::swap(nums[i], nums[index]);
      backtrack(res, nums, index + 1);
      std::swap(nums[index], nums[i]);
    }
  }
};