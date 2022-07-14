#include <algorithm>
#include <vector>

/*
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
*/
class Solution {
public:
  int coinChange(std::vector<int> &coins, int amount) {
    // init dp array
    int max = amount + 1;
    std::vector<int> dp(amount + 1, max);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
      for (int j = 0; j < coins.size(); j++) {
        if (coins[j] <= i) {
          dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
        }
      }
    }

    return dp[amount] > amount ? -1 : dp[amount];
  }
};