#include <vector>

/*
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
*/
class Solution {
public:
  std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
                                               int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> tmp;
    backtrack(candidates, result, target, tmp, 0);
    return result;
  }

  void backtrack(std::vector<int> &candidates,
                 std::vector<std::vector<int>> &result, int target,
                 std::vector<int> &tmp, int index) {
    if (index == candidates.size()) {
      return;
    }

    if (target == 0) {
      result.emplace_back(tmp);
      return;
    }

    backtrack(candidates, result, target, tmp, index + 1);

    if (target - candidates[index] >= 0) {
      tmp.emplace_back(candidates[index]);
      backtrack(candidates, result, target - candidates[index], tmp, index);
      tmp.pop_back();
    }
  }
};