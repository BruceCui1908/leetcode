#include <utility>
#include <vector>

/*
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/

class Solution {
public:
  void moveZeroes(std::vector<int> &nums) {
    int left = 0, right = 0;

    while (right < nums.size()) {
      if (nums[right]) {
        std::swap(nums[left], nums[right]);
        left++;
      }
      right++;
    }
  }
};