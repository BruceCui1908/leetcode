#include <algorithm>
#include <vector>

/*
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
*/
class Solution {
public:
  int minPathSum(std::vector<std::vector<int>> &grid) {
    if (grid.size() == 0 || grid[0].size() == 0) {
      return 0;
    }

    int rows = grid.size(), columns = grid[0].size();

    auto dp = std::vector<std::vector<int>>(rows, std::vector<int>(columns));

    dp[0][0] = grid[0][0];

    for (int i = 1; i < rows; i++) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < columns; j++) {
      dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < rows; i++) {
      for (int j = 1; j < columns; j++) {
        dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }

    return dp[rows - 1][columns - 1];
  }
};