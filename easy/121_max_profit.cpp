#include <algorithm>
#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int n = (int)prices.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        ans = std::max(ans, prices[j] - prices[i]);
      }
    }

    return ans;
  }
};