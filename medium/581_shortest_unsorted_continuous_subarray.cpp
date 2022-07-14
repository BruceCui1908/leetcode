#include <vector>

/*
Given an integer array nums, you need to find one continuous subarray that if
you only sort this subarray in ascending order, then the whole array will be
sorted in ascending order.
Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9]
*/
class Solution {
public:
  int findUnsortedSubarray(std::vector<int> &nums) {
    int len = nums.size();

    int min = nums[len - 1];
    int max = nums[0];
    int begin = 0;
    int end = -1;

    for (int i = 0; i < len; i++) {
      // 从左到右维持最大值，寻找右边界end
      if (nums[i] < max) {
        end = i;
      } else {
        max = nums[i];
      }

      if (nums[len - i - 1] > min) {
        begin = len - i - 1;
      } else {
        min = nums[len - i - 1];
      }
    }

    return end - (begin - 1);
  }
};