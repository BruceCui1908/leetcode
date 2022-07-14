#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    std::unordered_set<int> num_set;

    for (const int &num : nums) {
      num_set.insert(num);
    }

    int longestStreak = 0;

    for (const int &num : nums) {
      if (!num_set.count(num - 1)) {
        int current_num = num;
        int cur_streak = 1;
        while (num_set.count(current_num + 1)) {
          current_num++;
          cur_streak++;
        }

        longestStreak = std::max(longestStreak, cur_streak);
      }
    }

    return longestStreak;
  }
};