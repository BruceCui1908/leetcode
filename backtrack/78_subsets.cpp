#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {

    vector<vector<int>> res;
    vector<int> temp;
    backtrack();
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