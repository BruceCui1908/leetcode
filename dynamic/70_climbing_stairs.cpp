#include <vector>

/*
f(x) = f(x-1)+f(x-2)
f(0)=1;
f(1)=1;
f(2)=2;
*/
class Solution {
public:
  int climbStairs(int n) {
    int p = 0;
    int q = 0;
    int r = 1;

    for (int i = 1; i <= n; i++) {
      p = q;
      q = r;
      r = p + q;
    }

    return r;
  }
};