#include <utility>
#include <vector>

/*
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Input: nums = [0,1]
Output: [[0,1],[1,0]]
*/
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