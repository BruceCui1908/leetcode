#include <vector>

/*
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/
using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {

    vector<vector<int>> res;
    vector<int> temp;
    backtrack(nums, 0, res, temp);
    return res;
  }

  void backtrack(vector<int> &nums, int begin, vector<vector<int>> &result,
                 vector<int> &temp) {
    result.emplace_back(temp);

    for (int i = begin; i < nums.size(); i++) {
      temp.push_back(nums[i]);
      backtrack(nums, i + 1, result, temp);
      temp.pop_back();
    }
  }
};