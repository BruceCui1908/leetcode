/*
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
*/
#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  merge(std::vector<std::vector<int>> &intervals) {
    if (intervals.size() == 0) {
      return {};
    }
    std::vector<std::vector<int>> result;
    std::sort(intervals.begin(), intervals.end());

    for (int i = 0; i < intervals.size(); i++) {
      int left = intervals[i][0], right = intervals[i][1];
      if (!result.size() || result.back()[1] < left) {
        result.push_back({left, right});
      } else {
        result.back()[1] = std::max(result.back()[1], right);
      }
    }

    return result;
  }
};