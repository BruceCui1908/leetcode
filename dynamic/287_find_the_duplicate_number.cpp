#include <vector>

/*
There is only one repeated number in nums, return this repeated number.
Input: nums = [3,1,3,4,2]
Output: 3

[1,3,4,2]
映射关系 n->f(n)
0->1
1->3
2->4
3->2
0->1->3->2->4->null

[1,3,4,2,2]
映射关系 n->f(n)
0->1
1->3
2->4
3->2
4->2
0->1->3->2->4->2->4->2->……


*/
class Solution {
public:
  int findDuplicate(std::vector<int> &nums) {
    int slow = 0;
    int fast = 0;

    slow = nums[slow];
    fast = nums[nums[fast]];

    while (slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }

    int pre1 = 0;
    int pre2 = slow;
    while (pre1 != pre2) {
      pre1 = nums[pre1];
      pre2 = nums[pre2];
    }

    return pre1;
  }
};