#include <algorithm>
#include <vector>

/*
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/
class Solution {
public:
  void sortColors(std::vector<int> &nums) {
    int index = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        std::swap(nums[i], nums[index]);
        index++;
      }
    }

    for (int i = index; i < nums.size(); i++) {
      if (nums[i] == 1) {
        std::swap(nums[i], nums[index]);
        index++;
      }
    }
  }
};